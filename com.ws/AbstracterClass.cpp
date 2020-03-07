#include <iostream>

using namespace std;

/**
 * 抽象类 : 参考JAVA抽象类
 *  抽象类不能实例化
 *
 *  纯虚函数    :    virtual int getResult() = 0; ----JAVA中抽象方法
 *  虚析构     :
 *  纯虚析构  :
 */

class AbstracterCalc {

public:
    //纯虚函数 -> 抽象类
    virtual int getResult() = 0;

    int x;
    int y;

    /**
     * 若不加virtual,当子类中拥有指针,则子类在堆区的数据不能回收;
     * 加了virtual,当子类中含有指针,进行回收的时候会调用子类析构函数,再调用父类析构函数;
     */
    virtual ~AbstracterCalc() {
        cout << "AbstracterCalc析构" << endl;
    }
};


class Add : public AbstracterCalc {

public:

    Add() {
        x = 18;
        y = 19;
    }

    Add(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getResult() {
        return x + y;
    }

    ~Add() {
        cout << " Add 析构" << endl;
    }
};

class Multi : public AbstracterCalc {

public:
    Multi() {
        this->x = 15;
        this->y = 15;
    }

    Multi(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getResult() {
        return x * y;
    }
};

int main() {

    AbstracterCalc *ac = new Add;
    cout << " Add -> " << ac->getResult() << endl;
    delete ac;

    ac = new Multi;
    cout << "Multi -> " << ac->getResult() << endl;
    delete ac;

    return 0;
};