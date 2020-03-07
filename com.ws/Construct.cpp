#include <iostream>

using namespace std;


/**
 * ��� : ǳ����
 * �Ƿ���ͬһ���ڴ��ַ , �������Ϊǳ����,����������
 * ǳ���������ָ���ν��л��յ��³������;
 * ������ڵ�ַ�ǲ�ͬ,���Ը��Ի��յ�����ĵ�ַ�ڴ�,���ᷢ����λ��յ�����;
 */

class Hello {
public:

    string word;
    int num;
    int *scope;

    Hello() {
        cout << "���캯��" << endl;
    }

    Hello(string word, int num, int *scope) {
        this->word = word;
        this->num = num;
        //ǳ���� , ǳ���������ָ�����ͷ�,���´���
        this->scope = scope;
    }

    Hello(Hello const &hello) {
        word = hello.word;
        num = hello.num;
        //���,���ǳ����ָ������
        scope = new int(*hello.scope);
    }

    /**
     * �е������� Java�е� Object.finalize()
     */
    ~Hello() {
        if (scope != NULL) {
            cout << "��������" << endl;
            delete scope;
            scope = NULL;
        }
    }

    /**
     * �βο���ӵ��Ĭ�ϲ���,����
     */
    int max(int a, int b = 10) {
        return a > b ? a : b;
    }

    /**
     * ��������
     */
    double max(double a = 8.8, double b = 6.6) {
        return a > b ? a : b;
    }

};

void createInstance() {
    Hello hello;
}

int main() {

    createInstance();

    Hello hello;
    hello.num = 18;
    hello.word = "Hello";
    hello.scope = new int(1);
    //new�ؼ����൱�����ڶ��п���,���ص���һ�����������͵�ָ��
    Hello world(hello);
    cout << world.word << endl;
    hello.word = "World";
    cout << world.word << endl;
    world.word = "Good";
    cout << world.word << endl;
    cout << hello.word << endl;

    int scope = 100;
    Hello h3("XM", 10, &scope);

    Hello h4(h3);

    return 0;
};