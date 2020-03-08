#include <iostream>
#include <zconf.h>
#include "Split.cpp"
#include "vector"
#include "thread"

using namespace std;
//定义一个宏
#define Hello
#define Max(a, b) (a>b?a:b)
using namespace spl;

/**
 * 容器
 */

void testVector() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(8);

    //遍历方式一
    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << endl;
        it++;
    }
    cout << "-------------------" << endl;
    //方式二
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << endl;
    }
}

/**
 * 异常以及异常处理
 */
void throwAble(int a) {
    try {
        if (a % 2 == 0) {
            //抛出异常
            throw "Bad number";
        }
    } catch (const char *msg) {
        cerr << msg << endl;
        exit(-1);
    }
}

/**
 * 测试预编译
 *
 * #define
 * #ifdef ---> 这些都是预编译,在程序编译时会进行处理
 */
void testIf() {
#ifdef Hello
//如果定义了#define Hello,name这段代码将会执行
    cout << "test #ifdef" << endl;
#endif

#if 1
    cout << "test" << endl;
#endif
}

/**
 * 测试睡眠
 */
void testSleep() {
    int a = 5;
    //睡眠,参考java sleep
    while (a-- > 0) {
        sleep(1);
        cout << a << endl;
    }
}

//获取当前线程????
thread::id main_thread = this_thread::get_id();

void testThread() {

    thread::id current_thread = this_thread::get_id();

    if (current_thread == main_thread) {
        cout << "main thread" << endl;
    } else {
        cout << "non main thread" << endl;
    }
}

void deadEach() {
    int i = 0;
    while (1) {
        sleep(1);
        cout << i++ << endl;
        if (i > 5)break;
    }
}

int main() {
    //testVector();
    //测试自定义命名空间
    testNamespace();
    cout << Max(10, 18) << endl;
    testThread();

    //启动一个线程
    thread t(deadEach);
    //主线程等待线程t结束,与JAVA一样
    t.join();
    return 0;
};