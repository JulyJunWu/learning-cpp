#include <iostream>

using namespace std;

/**
 * 局部变量不要返回地址
 * 局部变量的内存分配在栈区
 * 请勿使用这样!!!
 */
int *printf() {
    int a = 18;
    cout << a << endl;
    return &a;
}

/**
 * 分配在栈区的数据
 * @return
 */
int getMax() {
    int b = 10;
    return b;
}

/**
 * new关键字 创建一个在堆区的数据
 *
 * new返回的是该数据类型的指针
 * @return
 */
int *createInt() {
    // 这个数据是在堆区创建的,但是 p还是在栈区
    int *p = new int(18);
    return p;
}

/**
 * 创建一个数组 并释放
 * @return
 */
void createArray() {
    //返回的是数组首个索引的指针
    int *array = new int[5];
    array[0] = 55;
    //对数组进行释放
    delete[] array;
}

int main() {
    //int *p = printf();
    int *p = createInt();
    //访问指针指向的数据
    cout << *p << endl;
    //打印指针的地址
    cout << p << endl;
    //释放一个指针所占用的内存
    delete p;
    //输出的是乱码(非法操作),应该原来的占用内存已经被释放
    cout << *p << endl;

    int a = 18;
    int & b = a ;
    int c = a;
    // 18 | 18 | 18
    cout << a << " | " << b << " | " << c <<endl;
    a = 20;
    // 20 | 20 | 18
    cout << a << " | " << b << " | " << c <<endl;

    return 0;
};