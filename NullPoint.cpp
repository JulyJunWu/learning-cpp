#include <iostream>

using namespace std;

/**
 *  当对象是一个空指针,妄想去访问成员变量,那么下场就是GG(报错);
 *  但是呢,如果没有访问成员变量,访问一个成员函数(函数中未访问成员变量),那么这个是允许的;
 */
class Point {

public:
    int order;

    /**
     * 可以通过空指针进行访问该函数
     */
    void sleep() {
        cout << "Sleep" << "\n";
    }

    /**
     *  通过空指针进行访问该函数,则报错
     */
    void play() {
        //这里访问order其实就是通过 this->order进行访问的;
        cout << order << endl;
    }

    /**
     * 需要进行访问成员变量的时候,先验证一下当前对象是否空指针
     */
    void perform() {
        //如果该对象是空指针,那么就不让继续走下去
        if (this == NULL) {
            cout << "this 为 NULL , 阻止执行" << endl;
            return;
        }
        cout << order << "\n";
    }
};

int main() {

    Point *point = NULL;

    point->sleep();
    point->perform();
    point->play();

    return 0;
};