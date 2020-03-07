#include <iostream>

using namespace std;

/**
 * 2.������Ԫ
 *  ��Ԫ�� : ���һ����(����A��)�е�˽�г�Ա����������(����B��) ��A���˽�г�Ա���з���,
 *  ��ôֱ����A������� friend class B ����
 *
 * 3.��Ա��������Ԫ
 *   ��A���ĳ����Ա����(void print())��Ҫȥ����B���е�˽������,��ôֱ����
 *   B�������friend void A::print() ����;
 */
//����һ����
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
    //�������Ա����е�˽��˳���Խ��з���!!!
    friend class Person;

public:
    Security();

    int age;
private:
    int weight;
};

//��ʼ��Security����
Security::Security() {
    this->age = 18;
    this->weight = 168;
}

//��ʼ��Person����
Person::Person() {
    security = new Security();
}

//��ʼ��Person��������
void Person::visit() {
    //����Security �������� ,ȴ�޷�����˽������
    cout << security->age << endl;
    //��Security�������friend �� , ���������������˽�����Ծͽ��з���
    cout << security->weight << endl;
}

int main() {
    Person person;
    person.visit();
    return 0;
};