#include <iostream>

using namespace std;

/**
 * 常函数: 成员函数后加const称之为 常函数
 *      常函数内不可用修改成员属性;
 *      成员属性声明时加关键字mutable,在常函数中仍然可以修改
 *
 *  常对象:
 *      声明对象前加const成为常对象;
 *      常对象只能调用常函数
 *
 */

class ConstObject {

public:
    int num;
    mutable int age;

    /**
     *
     * this指针的本质是 指针常量(int * const this) , 指针的指向是不可以修改的
     *
     * void hello() const 相当于是 const + this => const int * const this; ,使得指针和指针指向的值都不可修改;
     */
    void hello() const {
        //num = 19; 报错
        age = 88;
        cout << "常函数" << endl;
    }

    void hi() {
        cout << age << endl;
    }

};

int main() {

    const ConstObject *constObject;
    //mutable修饰的值可以改变
    constObject->age = 10;
    //constObject->num = 10 ; 报错

    //常对象只能访问常函数
    constObject->hello();
    //报错,常对象不能访问非常函数
    //constObject->hi();

    return 0;
};