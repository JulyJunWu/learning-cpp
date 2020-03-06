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


int main() {

    Person person;
    person.name = 'A';
    person.age = 19;

    cout << person.age << endl;

    return 0;
};