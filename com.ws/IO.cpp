#include <iostream>

using namespace std;

#include "fstream"

/**
 * 使用IO ,输出流
 */

/**
 * 写出到文件
 */
void outPut() {
    //创建一个输出流
    ofstream os;
    //输出文字
    string str = "Hello World ,I`am 大宝";
    //打开一个文件
    os.open("ws.txt");
    //输入到文件中
    os << str << endl;
    //关闭资源
    os.close();
}

/**
 * 从控制台读取数据到系统,然后输出到文件中
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
 * 使用write写
 */
void write() {
    ofstream os;
    os.open("hello.txt");
    char c[] = "your success depend on your feet !";
    os.write((const char *) c, sizeof(c));
    os.close();
}
// ------------------------------------------------------------------ 读
/**
 * 从文件中读数据,使用char数据接收
 */
void readFromFile() {

    ifstream is;
    is.open("ws.txt");
    //判断是否打开
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
 * 使用string接收读取数据
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
    //读取一行
    //is >> str;
    //cout << str << endl;
    //读取全部
    while (is >> str){
        cout << str << endl;
    }
    is.close();
}

/**
 * 一行一行读取
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
 * 一一个读取
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