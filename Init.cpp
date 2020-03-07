#include <iostream>

using namespace std;

/**
 * 对象初始化 - 初始化列表
 *
 *
 * 对象中拥有成员对象,那么构造函数调用顺序,则是 对象 -> 成员对象
 *                      析构函数调用顺序,则是 成员对象 -> 对象
 *
 */

class World {
public:
    int count;
    string name;

    World(){
        cout << "World Init F" << endl;
    }

    /**
     * 传统上的赋值 --- 方式一
     */
    World(int a, string name) {
        cout << "World Init S" <<endl;
        this->count = a;
        this->name = name;
    }

    /**
     * 初始化列表 ----方式二
     */
    World(string name, int a) : count(a), name(name) {}

    ~World(){
        cout << "World Destroy" << endl;
    }

};

class YinHe{

public:
    string name;
    World world;

    YinHe(){
        cout << "YinHe Init F" << endl;
    }

    YinHe(string name , World w){
        cout << "YinHe Init S"<<endl;
        this->name = name;
        this->world = w;
    }

    ~YinHe(){
        cout << "YinHe Destroy" << endl;
    }

};

int main() {

    //World w1("World",666);
    //World w2(888,"Nice");

    YinHe yinHe;

    return 0;
};