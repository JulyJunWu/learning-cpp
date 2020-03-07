#include <iostream>

using namespace std;

/**
 * ������: ��Ա�������const��֮Ϊ ������
 *      �������ڲ������޸ĳ�Ա����;
 *      ��Ա��������ʱ�ӹؼ���mutable,�ڳ���������Ȼ�����޸�
 *
 *  ������:
 *      ��������ǰ��const��Ϊ������;
 *      ������ֻ�ܵ��ó�����
 *
 */

class ConstObject {

public:
    int num;
    mutable int age;

    /**
     *
     * thisָ��ı����� ָ�볣��(int * const this) , ָ���ָ���ǲ������޸ĵ�
     *
     * void hello() const �൱���� const + this => const int * const this; ,ʹ��ָ���ָ��ָ���ֵ�������޸�;
     */
    void hello() const {
        //num = 19; ����
        age = 88;
        cout << "������" << endl;
    }

    void hi() {
        cout << age << endl;
    }

};

int main() {

    const ConstObject *constObject;
    //mutable���ε�ֵ���Ըı�
    constObject->age = 10;
    //constObject->num = 10 ; ����

    //������ֻ�ܷ��ʳ�����
    constObject->hello();
    //����,�������ܷ��ʷǳ�����
    //constObject->hi();

    return 0;
};