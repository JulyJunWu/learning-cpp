#include <iostream>

using namespace std;
/**
 * ���峣�� �Լ� �鿴�����ĵ�ַ ����ͨ�Ķ�ֲ������ĵ�ַ��ɶ��һ��!!
 * @return
 */
#define DAY 7;

int a_a = 18;

/**
 * @param a ���ò���
 */
void change(int &a) {
    a = 8;
}

int main() {

    int day = 7;
    //����
    int &d = day;

    change(d);
    cout << d << endl;
    cout << "�ֲ����� = " <<&day << endl;

    cout << "ȫ�ֱ��� = " << &a_a << "\n";

    const int c = 18;
    static int e = 18;
    static const int f = 18;
    cout << "const int c = " <<  &c << endl;
    cout << "static int e = " << &e << endl;
    cout << "static const int f  = " << &f << endl;

    return 0;
};