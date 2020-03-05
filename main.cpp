#include <iostream>
using namespace std;

#define DAY 7
int main() {

    cout << "你个臭BB" << endl;
    char c[] = "Hello World 哈哈";
    string str = "First blood";

    bool ok = false;
    bool is_ok = true;
    cout << ok << endl;
    cout << is_ok << endl;

    cout << str << endl;
    cout << c << endl;

    int a = 0;
    //输出去到控制台(output)
    cout << "请输入整形:" << endl;
    //读到程序(input)
    //cin >> a ;
    cout << a << endl;
    a = 1 | 1;
    cout << a << endl;
    a = 1 & 2;
    cout << a << endl;

    if (a > 0) {
        cout << "1" << endl;
    } else if (a == 0) {
        cout << "<0 " << endl;
    } else {
        cout << "error" << endl;
    }


    int k, g = 0;
    k = 10;

    (k > g ? k : g) = 1000;
    cout << k << endl;


    switch (a) {
        case 1:
            cout << 1 << endl;
            break;
        case 2:
            cout << 2 << endl;
            break;
        default:
            cout << "default" << endl;
            break;
    }

    for (;;) {
        a++;
        if (a % 2 == 0) {
            //continue;
            break;
        }
        cout << a << endl;
    }

    //遇到goto,那么直接跳到标记的位置
    goto LOOP;
    //不执行
    cout << 222 << endl;
    LOOP:
    cout << 333 << endl;

    int arr[] = {1, 2, 3};
    cout << sizeof(arr) << endl;

    for (int i = 0; i < 3; ++i) {
        cout << arr[i] << endl;
    }
    //首个元素地址(16进制)
    cout << arr << endl;
    //索引0的地址
    cout << &arr[0] << endl;

    int param = 10;
    //定义一个指针
    int * p;
    p = &param;
    //打印指针地址
    cout << &a << endl;
    cout << p << endl;

    //解引用
    cout << *p << endl;
    //通过指针去操作数据(改变变量param数据)
    *p = 666;
    /**
     * 在32位操作系统下,指针都是占用4位
     * 在64位操作系统下,指针占用8位
     */
    cout << *p << endl;
    cout << param << endl;

    /**
     * 空指针
     * 空指针是不能进行访问的
     * 0~255之间的内存编号是系统使用的,因此不能访问
     */
    int * pp = NULL;
    //报错,走不下去了
    //cout << *pp << endl;

    /**
     * 野指针: 指向一个越界的地址
     */
    int * y = (int *) 0x11111;
    // 报错,指针越界,非法指针
   // cout << *y << endl;

    /**
     * 1.常量指针:
     *   指针可以修改指向,
     *   但是不能修改指向的值
     */
    int cc = 6;
    int bb = 7;
    const int * cl = &cc;
    //允许
    cl = &bb;
    //非法: *cl = 8888;

    /**
     * 2.指针常量:
     *  指针不能修改
     *  指针指向的值可以修改
     */
    int * const zz = &cc;
    // 报错,不能修改指针 zz = &bb;
    //正确 ,可以修改指针指向的数据
    *zz = 999;

    /**
     * 3. const既修饰指针有修饰常量
     * 即不能修改指向值又不能修改指针
     */
     const int * const ff = &cc;

     /**
      * 使用指针去访问数组
      */
      int arrayNum [] = {11,22,33};
      int * pArray = arrayNum;
      // 打印索引为0的值
      cout << *pArray << endl;

      //指针向后偏移4个字节(因为定义的是int类型)
      pArray++;
      //这时候打印的就是索引为1的值
      cout << *pArray << endl;

      int num = 5;
      while (num -- > 0){
          cout << num << endl;
      }
      // 常量不可被修改
      //DAY = 9;
      cout << DAY << endl;
    return 0;
}
