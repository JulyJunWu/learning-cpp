#include <iostream>

using namespace std;

/**
 * 多态 : 虚函数 virtual(动态绑定)
 */

class Father {
public:
    /**
     * 重点::::::::
     */
    virtual void work() {
        cout << "上班" << endl;
    }

    void walk() {
        cout << "开车" << endl;
    }

    virtual void sleep(){
        cout << "加班..." << endl;
    }
};

class Son : public Father {
public:
    void work() {
        cout << "上学" << endl;
    }

    void walk() {
        cout << "骑自行车" << endl;
    }
};

void testWork(Father *father) {
    father->work();
}

int main() {
    Son son;
    son.work();
    son.walk();

    Father *father = &son;
    father->work();
    father->walk();
    cout << "-----------------------" << endl;

    son.sleep();
    testWork(&son);

    return 0;
};