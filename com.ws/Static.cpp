#include <iostream>

using namespace std;

/**
 * ��̬��Ա����
 *
 * ���ʷ�ʽ::: �ο�JAVA��static
 *
 * һ���ն���,�������κγ�Ա����,����ռ��1���ֽ�
 *
 * ��Ա�����ͳ�Ա�����ֿ��洢
 *
 */
class Women {
    /**
     * ��̬��Ա����
     */
public:
    static string str;

    static void function() {
        cout << "static function" << endl;
        cout << str << endl;
        cout << "��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����!" << endl;
    }
};

string Women::str = "��̬��Ա�������г�ʼ��";

int main() {

    //���ʾ�̬��Ա������ʽһ: ͨ��ʵ��������з���
    Women women;
    women.function();

    //��ʽ�� : ֱ��ͨ����������
    Women::function();

    cout << sizeof(women) << endl;

    return 0;
};