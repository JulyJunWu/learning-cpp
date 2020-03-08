#include <iostream>
#include <zconf.h>
#include "Split.cpp"
#include "vector"
#include "thread"

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

int main() {
    //testVector();
    //�����Զ��������ռ�
    testNamespace();
    cout << Max(10, 18) << endl;
    testThread();

    //����һ���߳�
    thread t(deadEach);
    //���̵߳ȴ��߳�t����,��JAVAһ��
    t.join();
    return 0;
};