#include <iostream>

#include "Split.cpp"

using namespace std;

/**
 * 类模板 , 类模板可以有默认类型
 *
 * 类模板中的成员函数,一开始是不会创建的,而是在模板调用的时候再生成
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

    // 获取类型的名称
    void print() {
        cout << typeid(c).name() << endl;
    }

};

/**
 * 接收类模板方式一 , 指定传入类型(常用)
 */
void receive(Object<string> &o) {
    cout << typeid(o).name() << endl;
}

/**
 * 方式二
 * 模板函数只有在使用的时候生成
 */
template<typename S>
void receive2(S s) {
    s.print();
    cout << typeid(s).name() << endl;
}

/**
 * 类模板类的继承;
 *
 *
 */
class Father : public Object<char, string> {
};

void test() {
    string str = "Hello";
    //使用类模板 ,需要指定数据类型
    Object<string, int> o(str, 1);
    //也可以省略默认类型
    Object<string> c(str, 1);
    o.print();
    //使用类模板对象 方式一
    receive(o);
    //方式二
    receive2(o);
}

/**
 * 如果子类也需要进行模板化,那么也需要将自身变为模板类
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
 * 类模板的 函数类外实现
 */
template<class A>
class Phone {
public:
    A a;

    Phone(A a);

    void perform();
};

//模板类->构造函数类外实现
template<class A>
Phone<A>::Phone(A a) {
    this->a = a;
}

//模板类->成员函数类外实现
template<class A>
void Phone<A>::perform() {
    cout << a << endl;
}

/**
 * 测试模板类 构造/函数 类外实现
 */
void testPhone() {
    Phone<string> phone("APPLE");
    phone.perform();
}

int main() {
    //test();
    //testExtends();
    //testPhone();

    //应用外部类
    Split<string> s("Work");
    s.dance();
    return 0;
}