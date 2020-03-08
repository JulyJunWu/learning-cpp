#include <iostream>

using namespace std;

#include "fstream"

/**
 * ʹ��IO ,�����
 */

/**
 * д�����ļ�
 */
void outPut() {
    //����һ�������
    ofstream os;
    //�������
    string str = "Hello World ,I`am ��";
    //��һ���ļ�
    os.open("ws.txt");
    //���뵽�ļ���
    os << str << endl;
    //�ر���Դ
    os.close();
}

/**
 * �ӿ���̨��ȡ���ݵ�ϵͳ,Ȼ��������ļ���
 */
void readFromConsoleAndOutputFile() {
    string data;
    cin >> data;
    ofstream os;
    os.open("cb.txt");
    os << data << endl;
    os.close();
}

/**
 * ʹ��writeд
 */
void write() {
    ofstream os;
    os.open("hello.txt");
    char c[] = "your success depend on your feet !";
    os.write((const char *) c, sizeof(c));
    os.close();
}
// ------------------------------------------------------------------ ��
/**
 * ���ļ��ж�����,ʹ��char���ݽ���
 */
void readFromFile() {

    ifstream is;
    is.open("ws.txt");
    //�ж��Ƿ��
    if (!is.is_open()) {
        is.close();
        return;
    }
    char data[1024];
    is.read(data, sizeof(data));
    cout << data << endl;
    is.close();
}

/**
 * ʹ��string���ն�ȡ����
 */
void readFromFile2() {

    ifstream is;
    is.open("ws.txt");

    if (!is.is_open()) {
        is.close();
        return;
    }
    string str;
    //char c [1024];
    //��ȡһ��
    //is >> str;
    //cout << str << endl;
    //��ȡȫ��
    while (is >> str){
        cout << str << endl;
    }
    is.close();
}

/**
 * һ��һ�ж�ȡ
 */
void getLine(){
    ifstream is;
    is.open("ws.txt");
    if (!is.is_open()) {
        is.close();
        return;
    }
    char c [1024] ;
    while (is.getline(c, sizeof(c))){
        cout << c << endl;
    }
    is.close();
}

/**
 * һһ����ȡ
 */
void getChar(){
    ifstream is;
    is.open("ws.txt");
    if (!is.is_open()) {
        is.close();
        return;
    }
    char c ;
    while (is.get(c) && c != -1){
        cout << c ;
    }
    is.close();
}

int main() {
    //readFromConsoleAndOutputFile();
    //write();
    //readFromFile();
    //readFromFile2();
    //getLine();
    getChar();
    return 0;
}