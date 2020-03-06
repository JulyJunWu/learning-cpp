#include <iostream>

using namespace std;

/**
 * 申请一个类(感觉和结构差不多)
 */
class Person {
public:
    char name;
    int age;

};

struct Man{
    string sex;
};

/**
 * 结构体
 */
struct Student{
    int age;
    string address;
    string name;
    /**
     * 结构体嵌套结构体
     */
    struct Man man;
};


int main() {

    Person person;
    person.name = 'A';
    person.age = 19;
    cout << person.age << endl;

    Student student = {17,"北京朝阳区","张大宝"};
    cout << student.name << endl;
    student.name = "SIX";
    //结构体指针
    Student * p = &student;
    cout << p->address << endl;
    //通过指针来对数据赋值
    p->address = "老铁666";
    cout << p->address << endl;

    Man man = {"男"};
    p->man = man;
    cout << p->man.sex << endl;
    man.sex = "女";
    cout << p->man.sex << endl;
    cout << man.sex << endl;

    struct Student sArray[] = {
            {30,"北京朝阳区","张大宝"},
            {20,"北京朝阳区","张大宝2"},
            {40,"北京朝阳区","张大宝3"},
            {10,"北京朝阳区","张大宝3"},
            {90,"北京朝阳区","张大宝3"},
            {25,"北京朝阳区","张大宝3"},
            {12,"北京朝阳区","张大宝3"}
    };

    int len = sizeof(sArray) / sizeof(sArray[0]);

    for (int i = 0; i < len; ++i) {
        for (int j = 0 ; j < len- i ; ++j) {
            struct Student temp = sArray[j];
            if (temp.age > sArray[j+1].age){
                sArray[j] = sArray[j+1];
                sArray[j+1] = temp;
            }
        }
    }

    for (int k = 0; k < len; ++k) {
        cout << sArray[k].age << "\t";
    }
    cout << "\n";

    return 0;
};