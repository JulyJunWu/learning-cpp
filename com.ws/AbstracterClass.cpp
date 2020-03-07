#include <iostream>

using namespace std;

/**
 * ������ : �ο�JAVA������
 *  �����಻��ʵ����
 *
 *  ���麯��    :    virtual int getResult() = 0; ----JAVA�г��󷽷�
 *  ������     :
 *  ��������  :
 */

class AbstracterCalc {

public:
    //���麯�� -> ������
    virtual int getResult() = 0;

    int x;
    int y;

    /**
     * ������virtual,��������ӵ��ָ��,�������ڶ��������ݲ��ܻ���;
     * ����virtual,�������к���ָ��,���л��յ�ʱ������������������,�ٵ��ø�����������;
     */
    virtual ~AbstracterCalc() {
        cout << "AbstracterCalc����" << endl;
    }
};


class Add : public AbstracterCalc {

public:

    Add() {
        x = 18;
        y = 19;
    }

    Add(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getResult() {
        return x + y;
    }

    ~Add() {
        cout << " Add ����" << endl;
    }
};

class Multi : public AbstracterCalc {

public:
    Multi() {
        this->x = 15;
        this->y = 15;
    }

    Multi(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getResult() {
        return x * y;
    }
};

int main() {

    AbstracterCalc *ac = new Add;
    cout << " Add -> " << ac->getResult() << endl;
    delete ac;

    ac = new Multi;
    cout << "Multi -> " << ac->getResult() << endl;
    delete ac;

    return 0;
};