#include <iostream>

using namespace std;
/**
 * 定义常量 以及 查看常量的地址 和普通的额局部变量的地址有啥不一样!!
 * @return
 */
#define DAY 7;

int a_a = 18;

/**
 * @param a 引用参数
 */
void change(int &a) {
    a = 8;
}

int main() {

    int day = 7;
    //引用
    int &d = day;

    change(d);
    cout << d << endl;
    cout << "局部变量 = " <<&day << endl;

    cout << "全局变量 = " << &a_a << "\n";

    const int c = 18;
    static int e = 18;
    static const int f = 18;
    cout << "const int c = " <<  &c << endl;
    cout << "static int e = " << &e << endl;
    cout << "static const int f  = " << &f << endl;

    return 0;
};