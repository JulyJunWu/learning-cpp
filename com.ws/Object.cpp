#include <iostream>

using namespace std;

/**
 * ����һ����(�о��ͽṹ���)
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
 * �ṹ��
 */
struct Student{
    int age;
    string address;
    string name;
    /**
     * �ṹ��Ƕ�׽ṹ��
     */
    struct Man man;
};


int main() {

    Person person;
    person.name = 'A';
    person.age = 19;
    cout << person.age << endl;

    Student student = {17,"����������","�Ŵ�"};
    cout << student.name << endl;
    student.name = "SIX";
    //�ṹ��ָ��
    Student * p = &student;
    cout << p->address << endl;
    //ͨ��ָ���������ݸ�ֵ
    p->address = "����666";
    cout << p->address << endl;

    Man man = {"��"};
    p->man = man;
    cout << p->man.sex << endl;
    man.sex = "Ů";
    cout << p->man.sex << endl;
    cout << man.sex << endl;

    struct Student sArray[] = {
            {30,"����������","�Ŵ�"},
            {20,"����������","�Ŵ�2"},
            {40,"����������","�Ŵ�3"},
            {10,"����������","�Ŵ�3"},
            {90,"����������","�Ŵ�3"},
            {25,"����������","�Ŵ�3"},
            {12,"����������","�Ŵ�3"}
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