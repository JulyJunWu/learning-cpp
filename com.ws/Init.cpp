#include <iostream>

using namespace std;

/**
 * �����ʼ�� - ��ʼ���б�
 *
 *
 * ������ӵ�г�Ա����,��ô���캯������˳��,���� ���� -> ��Ա����
 *                      ������������˳��,���� ��Ա���� -> ����
 *
 */

class World {
public:
    int count;
    string name;

    World(){
        cout << "World Init F" << endl;
    }

    /**
     * ��ͳ�ϵĸ�ֵ --- ��ʽһ
     */
    World(int a, string name) {
        cout << "World Init S" <<endl;
        this->count = a;
        this->name = name;
    }

    /**
     * ��ʼ���б� ----��ʽ��
     */
    World(string name, int a) : count(a), name(name) {}

    ~World(){
        cout << "World Destroy" << endl;
    }

};

class YinHe{

public:
    string name;
    World world;

    YinHe(){
        cout << "YinHe Init F" << endl;
    }

    YinHe(string name , World w){
        cout << "YinHe Init S"<<endl;
        this->name = name;
        this->world = w;
    }

    ~YinHe(){
        cout << "YinHe Destroy" << endl;
    }

};

int main() {

    //World w1("World",666);
    //World w2(888,"Nice");

    YinHe yinHe;

    return 0;
};