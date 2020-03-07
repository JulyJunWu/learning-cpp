#include <iostream>

using namespace std;

/**
 * ��̬ : �麯�� virtual(��̬��)
 */

class Father {
public:
    /**
     * �ص�::::::::
     */
    virtual void work() {
        cout << "�ϰ�" << endl;
    }

    void walk() {
        cout << "����" << endl;
    }

    virtual void sleep(){
        cout << "�Ӱ�..." << endl;
    }
};

class Son : public Father {
public:
    void work() {
        cout << "��ѧ" << endl;
    }

    void walk() {
        cout << "�����г�" << endl;
    }
};

void testWork(Father *father) {
    father->work();
}

int main() {
    Son son;
    son.work();
    son.walk();

    Father *father = &son;
    father->work();
    father->walk();
    cout << "-----------------------" << endl;

    son.sleep();
    testWork(&son);

    return 0;
};