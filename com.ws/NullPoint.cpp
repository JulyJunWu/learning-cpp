#include <iostream>

using namespace std;

/**
 *  ��������һ����ָ��,����ȥ���ʳ�Ա����,��ô�³�����GG(����);
 *  ������,���û�з��ʳ�Ա����,����һ����Ա����(������δ���ʳ�Ա����),��ô����������;
 */
class Point {

public:
    int order;

    /**
     * ����ͨ����ָ����з��ʸú���
     */
    void sleep() {
        cout << "Sleep" << "\n";
    }

    /**
     *  ͨ����ָ����з��ʸú���,�򱨴�
     */
    void play() {
        //�������order��ʵ����ͨ�� this->order���з��ʵ�;
        cout << order << endl;
    }

    /**
     * ��Ҫ���з��ʳ�Ա������ʱ��,����֤һ�µ�ǰ�����Ƿ��ָ��
     */
    void perform() {
        //����ö����ǿ�ָ��,��ô�Ͳ��ü�������ȥ
        if (this == NULL) {
            cout << "this Ϊ NULL , ��ִֹ��" << endl;
            return;
        }
        cout << order << "\n";
    }
};

int main() {

    Point *point = NULL;

    point->sleep();
    point->perform();
    point->play();

    return 0;
};