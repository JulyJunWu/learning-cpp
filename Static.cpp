#include <iostream>

using namespace std;

/**
 * 静态成员函数
 *
 * 访问方式::: 参考JAVA的static
 *
 * 一个空对象,不包含任何成员变量,则是占用1个字节
 *
 * 成员变量和成员函数分开存储
 *
 */
class Women {
    /**
     * 静态成员函数
     */
public:
    static string str;

    static void function() {
        cout << "static function" << endl;
        cout << str << endl;
        cout << "静态成员函数只能访问静态成员变量!" << endl;
    }
};

string Women::str = "静态成员变量进行初始化";

int main() {

    //访问静态成员函数方式一: 通过实例对象进行访问
    Women women;
    women.function();

    //方式二 : 直接通过类名调用
    Women::function();

    cout << sizeof(women) << endl;

    return 0;
};