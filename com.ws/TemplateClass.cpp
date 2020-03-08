#include <iostream>

#include "Split.cpp"

using namespace std;

/**
 * ��ģ�� , ��ģ�������Ĭ������
 *
 * ��ģ���еĳ�Ա����,һ��ʼ�ǲ��ᴴ����,������ģ����õ�ʱ��������
 */
template<typename C, typename D = int>
class Object {

public:
    C c;
    D d;

    Object(C c, D d) {
        this->c = c;
        this->d = d;
    }

    Object() {}

    // ��ȡ���͵�����
    void print() {
        cout << typeid(c).name() << endl;
    }

};

/**
 * ������ģ�巽ʽһ , ָ����������(����)
 */
void receive(Object<string> &o) {
    cout << typeid(o).name() << endl;
}

/**
 * ��ʽ��
 * ģ�庯��ֻ����ʹ�õ�ʱ������
 */
template<typename S>
void receive2(S s) {
    s.print();
    cout << typeid(s).name() << endl;
}

/**
 * ��ģ����ļ̳�;
 *
 *
 */
class Father : public Object<char, string> {
};

void test() {
    string str = "Hello";
    //ʹ����ģ�� ,��Ҫָ����������
    Object<string, int> o(str, 1);
    //Ҳ����ʡ��Ĭ������
    Object<string> c(str, 1);
    o.print();
    //ʹ����ģ����� ��ʽһ
    receive(o);
    //��ʽ��
    receive2(o);
}

/**
 * �������Ҳ��Ҫ����ģ�廯,��ôҲ��Ҫ�������Ϊģ����
 */
template<typename A, typename B, typename C>
class Son : public Object<A, B> {
public:
    C sonC;

    void say() {
        cout << "I`am " << sonC << endl;
    }
};


void testExtends() {
    Son<int, int, int> s;
    s.sonC = 18;
    s.say();
}


/**
 * ��ģ��� ��������ʵ��
 */
template<class A>
class Phone {
public:
    A a;

    Phone(A a);

    void perform();
};

//ģ����->���캯������ʵ��
template<class A>
Phone<A>::Phone(A a) {
    this->a = a;
}

//ģ����->��Ա��������ʵ��
template<class A>
void Phone<A>::perform() {
    cout << a << endl;
}

/**
 * ����ģ���� ����/���� ����ʵ��
 */
void testPhone() {
    Phone<string> phone("APPLE");
    phone.perform();
}

int main() {
    //test();
    //testExtends();
    //testPhone();

    //Ӧ���ⲿ��
    Split<string> s("Work");
    s.dance();
    return 0;
}