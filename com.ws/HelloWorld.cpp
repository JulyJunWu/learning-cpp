#include <iostream>
#include "ctime"

using namespace std;


void getTime(long *p) {
    *p = time(NULL);
}

/**
 * 返回指针函数
 * @return
 */
 int * getPoint(){
     int arr[1];
     arr[0] = 6666;
     return arr;
 }


int main() {

    long a = 19;
    long *p;
    p = &a;

    //访问指针所在的数据
    cout << *p << endl;
    //访问指针地址
    cout << p << endl;
    //修改指针指向的数据
    *p = 66;
    cout <<  a << endl;

    //可以这样
    getTime(&a);
    //也可以这样
    getTime(p);

    cout <<  a << endl;

    /**
     * 引用: 引用不能被改变,只能改变引用的数据
     */
    int c;
    //创一个c的引用 cc
    int& cc = c;
    c = 10;
    cout << c <<endl;
    cout << cc <<endl;

    cc = 66;
    //改变引用的对象的数据
    cout << c <<endl;
    return 0;
}