#include <iostream>

using namespace std;

/**
 * �ֲ�������Ҫ���ص�ַ
 * �ֲ��������ڴ������ջ��
 * ����ʹ������!!!
 */
int *printf() {
    int a = 18;
    cout << a << endl;
    return &a;
}

/**
 * ������ջ��������
 * @return
 */
int getMax() {
    int b = 10;
    return b;
}

/**
 * new�ؼ��� ����һ���ڶ���������
 *
 * new���ص��Ǹ��������͵�ָ��
 * @return
 */
int *createInt() {
    // ����������ڶ���������,���� p������ջ��
    int *p = new int(18);
    return p;
}

/**
 * ����һ������ ���ͷ�
 * @return
 */
void createArray() {
    //���ص��������׸�������ָ��
    int *array = new int[5];
    array[0] = 55;
    //����������ͷ�
    delete[] array;
}

int main() {
    //int *p = printf();
    int *p = createInt();
    //����ָ��ָ�������
    cout << *p << endl;
    //��ӡָ��ĵ�ַ
    cout << p << endl;
    //�ͷ�һ��ָ����ռ�õ��ڴ�
    delete p;
    //�����������(�Ƿ�����),Ӧ��ԭ����ռ���ڴ��Ѿ����ͷ�
    cout << *p << endl;

    int a = 18;
    int & b = a ;
    int c = a;
    // 18 | 18 | 18
    cout << a << " | " << b << " | " << c <<endl;
    a = 20;
    // 20 | 20 | 18
    cout << a << " | " << b << " | " << c <<endl;

    return 0;
};