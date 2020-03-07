#include <iostream>

using namespace std;

/**
 * 友元 : 目的就是让一个函数或一个类去访问另一个类中的私有成员
 *   1.全局友元函数
 */
class Friend {
    //允许全局函数去访问私有属性
    friend void visit(Friend *f);

public:
    int age;
private:
    int weight;
public:
    void setDefault() {
        this->age = 18;
        this->weight = 60;
    }
};

void visit(Friend *f) {
    //访问公开属性,但是无法访问私有属性
    cout << "年龄(public) -> " << f->age << endl;
    // 在Friend类中,将函数 加上friend后 成为一个声明函数 就可以访问私有属性了
    cout << "体重(private) -> " << f->weight << endl;
}

int main() {

    Friend aFriend;
    aFriend.setDefault();
    visit(&aFriend);
    return 0;
};