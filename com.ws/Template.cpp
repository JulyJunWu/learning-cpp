#include <iostream>

using namespace std;

/**
 * 函数模板 , 类似于JAVA中的泛型
 */

//定义一个模板,告知编译器后续的类型T别报错 , T是一个通用的数据类型
template<typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

class Human {
public:
    string name;
    int age;
};

template<typename O>
bool compare(O &a, O &b) {
    return a == b;
}

//模板的类型具体化 ,当匹配到该模板,优先匹配对应类型的版本
template<>
bool compare(Human &a, Human &b) {
    return a.age == b.age && a.name == b.name;
}

int main() {

    int a = 18;
    int b = 28;
    //使用方式一: 由编译器自动类型推导
    mySwap(a, b);
    cout << a << " | " << b << endl;;
    //显示指定类型(推荐使用) , 可以隐式转换
    mySwap<int>(a, b);
    cout << a << " | " << b << endl;

    Human h1;
    Human h2;
    h1.name = h2.name = "大宝";
    h1.age = h2.age = 18;
    //优先匹配对应的类型的模板
    bool same = compare(h1, h2);
    cout << (same ? "true" : "false") << endl;

    Human h3;
    h3.name = h2.name;
    h3.age = 19;
    same = compare(h1, h3);
    cout << (same ? "true" : "false") << endl;
    return 0;
};