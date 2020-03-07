#include <iostream>

using namespace std;

/**
 * 继承
 *  class A : public B ===> 子类 : 继承方式 父类,
 *  多继承则是 class A : public B ,public C ...
 *
 *  继承方式:
 *      1.公共继承 public    父类中的能访问的成员变量修饰符不变;
 *      2.保护继承 protected 子类能访问的父类的所有成员变量修饰符都变成 protected;
 *      3.私有继承 private , 子类能访问的父类所有成员变量的修饰符在子类都变成 private
 *
 *  父类中的私有成员 , 子类访问不到;
 *
 *  继承::构造和析构函数执行顺序(和对象成员顺序类似):
 *      构造执行顺序 : 父类 -> 子类
 *      析构执行顺序:  子类 -> 父类
 *
 *
 */
class Animal {
public:
    string first = "愚蠢";

    static string str;

    Animal() {
        cout << "Animal init" << endl;
    }

    void sleep() {
        cout << first << " sleep" << endl;
    }

    void eat() {
        cout << first << " eat " << endl;
    }

    static void hi() {
        cout << "Animal hi" << endl;
    }

    ~Animal() {
        cout << "Animal Destroy" << endl;
    }

protected:
    string second = "nice";

private:
    string third = "good";
};

string Animal::str = "Animal str";


class Work {
public:
    string str = "work";
};

/**
 * public继承
 */
class People : public Animal, public Work {

public:
    People() {
        cout << "People Init" << endl;
    }

    static string str;

    //子类覆盖了父类中可访问的头同名变量,最终访问的是子类中的属性
    string first = "People";

    void sleep() {
        cout << "People sleep" << endl;
        cout << first << " | " << second << endl;
    }

    static void hi() {
        cout << "People hi" << endl;
    }

    ~People() {
        cout << "People destroy" << endl;
    }
};

string People::str = "People str";

/**
 * protected继承,,只能在类内部访问父类的protected成员,无限制访问public
 */
class Cat : protected Animal {

public:
    void sleep() {
        cout << "Cat " << first << " | " << second << endl;
    }
};

/**
 * private继承
 */
class Dog : private Animal {
public:
    void sleep() {
        cout << "Dog " << first << " | " << second << endl;
    }
};

int main() {

    People people;
    // Cat cat;
    //Dog dog;
    cout << sizeof(people) << endl;
    //打印People
    cout << people.first << endl;
    //访问与子类变量重名的父类属性,打印父类属性值(重名函数名一样) :::通过作用域访问
    cout << people.Animal::first << endl;

    //访问子类与父类同名静态成员变量
    cout << people.str << endl;
    //访问父类中的同名静态变量
    cout << people.Animal::str << endl;
    //访问与父类同名子类中的静态函数
    people.hi();
    //访问父类中的同名静态函数
    people.Animal::hi();
    cout << "----------------------------------" << endl;

    //直接使用类名访问子类
    cout << People::str << endl;
    //通难过子类访问父类的同名静态变量
    cout << People::Animal::str << endl;
    //子类
    People::hi();
    //子类访问父类
    People::Animal::hi();
    cout << "----------------------------------" << endl;
    return 0;
};