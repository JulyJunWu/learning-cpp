#include <iostream>

using namespace std;

/**
 * ��Ԫ : Ŀ�ľ�����һ��������һ����ȥ������һ�����е�˽�г�Ա
 *   1.ȫ����Ԫ����
 */
class Friend {
    //����ȫ�ֺ���ȥ����˽������
    friend void visit(Friend *f);

public:
    int age;
private:
    int weight;
public:
    void setDefault() {
        this->age = 18;
        this->weight = 60;
    }
};

void visit(Friend *f) {
    //���ʹ�������,�����޷�����˽������
    cout << "����(public) -> " << f->age << endl;
    // ��Friend����,������ ����friend�� ��Ϊһ���������� �Ϳ��Է���˽��������
    cout << "����(private) -> " << f->weight << endl;
}

int main() {

    Friend aFriend;
    aFriend.setDefault();
    visit(&aFriend);
    return 0;
};