//
// Created by Administrator on 2020/7/26.
// 测试线程安全
//
#include <iostream>
#include <mutex>
#include <thread>
#include <zconf.h>
#include <pthread.h>

using namespace std;
//  锁
static mutex mutex2;
static pthread_mutex_t  m;
//  资源
static int number = 0;

/**
 * 未使用锁
 */
void incrNumber() {
    for (int i = 0; i < 100000; ++i) {
        number = number + 1;
    }
}

/**
 * 使用锁
 * @return
 */
void incrNumberSync() {
    mutex2.lock();
    for (int i = 0; i < 100000; ++i) {
        number = number + 1;
    }
    mutex2.unlock();
}

/**
 * 使用tryLock
 * @return
 */
void incrNumberTryLock() {
    bool lock = mutex2.try_lock();
    while (!lock) {
        cout << "wait !" << endl;
        sleep(1);
        lock = mutex2.try_lock();
    }
    incrNumber();
    mutex2.unlock();
}


thread startThread() {
    thread t(incrNumber);
    return t;
}

thread startSyncThread() {
    thread t(incrNumberSync);
    return t;
}

thread startThreadTryLock() {
    thread t(incrNumberTryLock);
    return t;
}

int main() {
    thread t = startThread();
    thread t2 = startThread();
    t.join();
    t2.join();
    time_t time2 = time(0);
    cout << number <<  endl;
    //  重新把number置零
    number = 0;

    thread t3 = startSyncThread();
    thread t4 = startSyncThread();
    t3.join();
    t4.join();
    cout << number << endl;

    //  重新把number置零
    number = 0;

    thread t5 = startThreadTryLock();
    thread t6 = startThreadTryLock();
    t5.join();
    t6.join();
    cout << number << endl;

    printf("%p\n",malloc(1));
    printf("%p\n",malloc(1));
    int a = 3;
    int b = 3;
    printf("%p\n",&a);
    printf("%p\n",&b);

    //  malloc 分配一个4个字节的内存
    int *aa = (int *) malloc(sizeof(int));
    //  回收内存
    free(aa);

    return 0;
}
