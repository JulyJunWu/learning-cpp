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
//����һ����
#define Hello
#define Max(a, b) (a>b?a:b)
using namespace spl;

/**
 * ����
 */

void testVector() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(8);

    //������ʽһ
    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << endl;
        it++;
    }
    cout << "-------------------" << endl;
    //ɾ�����һ��Ԫ��
    v.pop_back();
    //��ʽ��
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << endl;
    }


}

/**
 * �쳣�Լ��쳣����
 */
void throwAble(int a) {
    try {
        if (a % 2 == 0) {
            //�׳��쳣
            throw "Bad number";
        }
    } catch (const char *msg) {
        cerr << msg << endl;
        exit(-1);
    }
}

/**
 * ����Ԥ����
 *
 * #define
 * #ifdef ---> ��Щ����Ԥ����,�ڳ������ʱ����д���
 */
void testIf() {
#ifdef Hello
//���������#define Hello,name��δ��뽫��ִ��
    cout << "test #ifdef" << endl;
#endif

#if 1
    cout << "test" << endl;
#endif
}

/**
 * ����˯��
 */
void testSleep() {
    int a = 5;
    //˯��,�ο�java sleep
    while (a-- > 0) {
        sleep(1);
        cout << a << endl;
    }
}

//��ȡ��ǰ�߳�????
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
 * �����߳�
 */
void startThread() {
    //����һ���߳�
    thread t(deadEach);
    //���̵߳ȴ��߳�t����,��JAVAһ��
    t.join();
}

/**
 * ����deque
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
 * ����stack FILO
 */
void testStack() {
    stack<int> s;

    for (int i = 0; i < 10; ++i) {
        s.push(i);
    }

    //��ȡջ��Ԫ��
    int a = s.top();
    for (int j = 0; j < 10; ++j) {
        s.pop();
        cout << s.size() << endl;
    }
}

/**
 * queue����(��deque����,ĳЩ�ط���Щ����)
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
    //�����Զ��������ռ�
    //testNamespace();
    //cout << Max(10, 18) << endl;
    //testThread();
    //test deque
    //testDeque();
    //test stack
    //testStack();



    return 0;
};