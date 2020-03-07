#include <iostream>

using namespace std;

/**
 * �̳�
 *  class A : public B ===> ���� : �̳з�ʽ ����,
 *  ��̳����� class A : public B ,public C ...
 *
 *  �̳з�ʽ:
 *      1.�����̳� public    �����е��ܷ��ʵĳ�Ա�������η�����;
 *      2.�����̳� protected �����ܷ��ʵĸ�������г�Ա�������η������ protected;
 *      3.˽�м̳� private , �����ܷ��ʵĸ������г�Ա���������η������඼��� private
 *
 *  �����е�˽�г�Ա , ������ʲ���;
 *
 *  �̳�::�������������ִ��˳��(�Ͷ����Ա˳������):
 *      ����ִ��˳�� : ���� -> ����
 *      ����ִ��˳��:  ���� -> ����
 *
 *
 */
class Animal {
public:
    string first = "�޴�";

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
 * public�̳�
 */
class People : public Animal, public Work {

public:
    People() {
        cout << "People Init" << endl;
    }

    static string str;

    //���า���˸����пɷ��ʵ�ͷͬ������,���շ��ʵ��������е�����
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
 * protected�̳�,,ֻ�������ڲ����ʸ����protected��Ա,�����Ʒ���public
 */
class Cat : protected Animal {

public:
    void sleep() {
        cout << "Cat " << first << " | " << second << endl;
    }
};

/**
 * private�̳�
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
    //��ӡPeople
    cout << people.first << endl;
    //������������������ĸ�������,��ӡ��������ֵ(����������һ��) :::ͨ�����������
    cout << people.Animal::first << endl;

    //���������븸��ͬ����̬��Ա����
    cout << people.str << endl;
    //���ʸ����е�ͬ����̬����
    cout << people.Animal::str << endl;
    //�����븸��ͬ�������еľ�̬����
    people.hi();
    //���ʸ����е�ͬ����̬����
    people.Animal::hi();
    cout << "----------------------------------" << endl;

    //ֱ��ʹ��������������
    cout << People::str << endl;
    //ͨ�ѹ�������ʸ����ͬ����̬����
    cout << People::Animal::str << endl;
    //����
    People::hi();
    //������ʸ���
    People::Animal::hi();
    cout << "----------------------------------" << endl;
    return 0;
};