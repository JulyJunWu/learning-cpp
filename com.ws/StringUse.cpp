#include <iostream>
#include "cstring"

using namespace std;

/**
 * �ַ���ʹ��
 */
int main() {

    string str = "Hello";

    str.append(" World");

    cout << str << endl;

    //��ȡ�Ӵ�
    string subStr =  str.substr(0,6);
    cout << subStr <<endl;

    return 0;
}