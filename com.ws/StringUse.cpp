#include <iostream>
#include "cstring"

using namespace std;

/**
 * 字符串使用
 */
int main() {

    string str = "Hello";

    str.append(" World");

    cout << str << endl;

    //截取子串
    string subStr =  str.substr(0,6);
    cout << subStr <<endl;

    return 0;
}