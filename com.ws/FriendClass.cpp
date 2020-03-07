#include <iostream>

using namespace std;

/**
 * 2.类做友元
 *  友元类 : 如果一个类(比如A类)中的私有成员允许其他类(比如B类) 对A类的私有成员进行访问,
 *  那么直接在A类中添加 friend class B 即可
 *
 * 3.成员函数做友元
 *   如A类的某个成员函数(void print())需要去访问B类中的私有属性,那么直接在
 *   B类中添加friend void A::print() 即可;
 */
//声明一个类
class Security;

class Person {
public:
    Person();

    void visit();

    void visit2();

private:
    Security *security;
};

class Security {
    //允许该类对本类中的私有顺序性进行访问!!!
    friend class Person;

public:
    Security();

    int age;
private:
    int weight;
};

//初始化Security构造
Security::Security() {
    this->age = 18;
    this->weight = 168;
}

//初始化Person构造
Person::Person() {
    security = new Security();
}

//初始化Person声明函数
void Person::visit() {
    //访问Security 公开属性 ,却无法访问私有属性
    cout << security->age << endl;
    //在Security类中添加friend 类 , 则允许该类对自身的私有属性就进行访问
    cout << security->weight << endl;
}

int main() {
    Person person;
    person.visit();
    return 0;
};