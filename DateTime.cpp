#include <iostream>
#include "ctime"

using namespace std;
/**
 * 结构
 */
struct Book{
    string name;
    string author;
    double price;
};
/**
 * 参数 为结构体
 * @param book
 */
void printName(struct Book book){
    cout << book.author <<  "\n" << book.name << "\n" << book.price << "\n";
}

int main() {

    //时间戳
    time_t now = time(0);
    cout << now << endl;
    //变为字符串
    char *c =  ctime(&now);
    cout << c <<endl;

    tm *tlm = localtime(&now);
    cout << tlm->tm_hour <<endl;

    Book book;
    book.author = "大宝";
    book.name = "plan";
    book.price = 8.88;
    cout << book.price << endl;
    printName(book);

    //指向结构的指针
    struct Book *book_point ;
    //指针关联
    book_point = &book;
    //使用指针访问指向的成员数据
    cout << book_point->price << endl;
    //改变指向的某一属性
    book_point->price = 9.99;
    cout << book.price << endl;
    return 0;
}