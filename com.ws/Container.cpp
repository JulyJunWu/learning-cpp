#include <iostream>
#include <zconf.h>
#include "Split.cpp"
#include "vector"
#include "thread"
#include "deque"
#include "stack"
#include "queue"
#include "map"

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
    //删除最后一个元素
    v.pop_back();
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

/**
 * 启动线程
 */
void startThread() {
    //启动一个线程
    thread t(deadEach);
    //主线程等待线程t结束,与JAVA一样
    t.join();
}

/**
 * 测试deque
 */
void testDeque() {

    deque<int> d;

    for (int i = 0; i < 10; ++i) {
        d.push_back(i);
    }

    for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << endl;
    }
}

/**
 * 测试stack FILO
 */
void testStack() {
    stack<int> s;

    for (int i = 0; i < 10; ++i) {
        s.push(i);
    }

    //获取栈顶元素
    int a = s.top();
    for (int j = 0; j < 10; ++j) {
        s.pop();
        cout << s.size() << endl;
    }
}

/**
 * queue队列(与deque类似,某些地方有些差异)
 */
void testQueue() {
    queue<int> q;

    for (int i = 0; i < 10; ++i) {
        q.push(i);
    }

    for (int j = 0; j < 10; ++j) {
        q.pop();
    }
}
void testMap(){

    //TODO

}

int main() {
    //testVector();
    //测试自定义命名空间
    //testNamespace();
    //cout << Max(10, 18) << endl;
    //testThread();
    //test deque
    //testDeque();
    //test stack
    //testStack();



    return 0;
};