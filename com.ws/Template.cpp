#include <iostream>

using namespace std;

/**
 * ����ģ�� , ������JAVA�еķ���
 */

//����һ��ģ��,��֪����������������T�𱨴� , T��һ��ͨ�õ���������
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

//ģ������;��廯 ,��ƥ�䵽��ģ��,����ƥ���Ӧ���͵İ汾
template<>
bool compare(Human &a, Human &b) {
    return a.age == b.age && a.name == b.name;
}

int main() {

    int a = 18;
    int b = 28;
    //ʹ�÷�ʽһ: �ɱ������Զ������Ƶ�
    mySwap(a, b);
    cout << a << " | " << b << endl;;
    //��ʾָ������(�Ƽ�ʹ��) , ������ʽת��
    mySwap<int>(a, b);
    cout << a << " | " << b << endl;

    Human h1;
    Human h2;
    h1.name = h2.name = "��";
    h1.age = h2.age = 18;
    //����ƥ���Ӧ�����͵�ģ��
    bool same = compare(h1, h2);
    cout << (same ? "true" : "false") << endl;

    Human h3;
    h3.name = h2.name;
    h3.age = 19;
    same = compare(h1, h3);
    cout << (same ? "true" : "false") << endl;
    return 0;
};