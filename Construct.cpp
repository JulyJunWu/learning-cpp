#include <iostream>

using namespace std;


/**
 * 深拷贝 : 浅拷贝
 * 是否共享同一块内存地址 , 如果是则为浅拷贝,否则就是深拷贝
 * 浅拷贝会造成指针多次进行回收导致程序错误;
 * 深拷贝由于地址是不同,所以各自回收的自身的地址内存,不会发生多次回收的问题;
 */

class Hello {
public:

    string word;
    int num;
    int *scope;

    Hello() {
        cout << "构造函数" << endl;
    }

    Hello(string word, int num, int *scope) {
        this->word = word;
        this->num = num;
        //浅拷贝 , 浅拷贝会造成指针多次释放,导致错误
        this->scope = scope;
    }

    Hello(Hello const &hello) {
        word = hello.word;
        num = hello.num;
        //深拷贝,解决浅拷贝指针问题
        scope = new int(*hello.scope);
    }

    /**
     * 有点类似于 Java中的 Object.finalize()
     */
    ~Hello() {
        if (scope != NULL) {
            cout << "析构函数" << endl;
            delete scope;
            scope = NULL;
        }
    }

    /**
     * 形参可以拥有默认参数,如下
     */
    int max(int a, int b = 10) {
        return a > b ? a : b;
    }

    /**
     * 函数重载
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
    //new关键字相当于是在堆中开辟,返回的是一个改数据类型的指针
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