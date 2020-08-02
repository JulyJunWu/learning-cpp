//
// Created by Administrator on 2020/7/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <assert.h>
#include <iostream>

using namespace std;

void *mythread(void *args) {
    printf("%s\n", (char *) args);
    return nullptr;
}

typedef struct Hello {
    int a;
    int b;
} Hello;

/**
 *   类似这样的代码不允许传递出函数作用域(因为在此值会随着函数的执行完毕而进行释放)
    一旦外部使用该参数会导致未知的错误!!

    错误使用例子
 * @return
 */
Hello *test1() {

    Hello h;
    h.a = 10;
    h.b = 20;
    return &h;
}

/**
 * 推荐这种方法,直接在堆中分配内存,允许作为参数返回
 * @return
 */
Hello *test2() {
    auto *hello = static_cast<Hello *>(malloc(sizeof(Hello)));
    hello->b = 10;
    hello->a = 10;
    return hello;
}

int main() {

    // Hello *hello = test1();
    // 报错,因为hello已经被释放了!! 严禁使用此方式!!!
    //cout << hello->a << "|||" << hello->b << endl;

    // 正确使用方式,使用堆上分配
    Hello *hello2 = test2();
    cout << hello2->a << "|" << hello2->b << endl;


    return 0;
}