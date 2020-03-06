#include <iostream>
#include "ctime"

using namespace std;
/**
 * �ṹ
 */
struct Book{
    string name;
    string author;
    double price;
};
/**
 * ���� Ϊ�ṹ��
 * @param book
 */
void printName(struct Book book){
    cout << book.author <<  "\n" << book.name << "\n" << book.price << "\n";
}

int main() {

    //ʱ���
    time_t now = time(0);
    cout << now << endl;
    //��Ϊ�ַ���
    char *c =  ctime(&now);
    cout << c <<endl;

    tm *tlm = localtime(&now);
    cout << tlm->tm_hour <<endl;

    Book book;
    book.author = "��";
    book.name = "plan";
    book.price = 8.88;
    cout << book.price << endl;
    printName(book);

    //ָ��ṹ��ָ��
    struct Book *book_point ;
    //ָ�����
    book_point = &book;
    //ʹ��ָ�����ָ��ĳ�Ա����
    cout << book_point->price << endl;
    //�ı�ָ���ĳһ����
    book_point->price = 9.99;
    cout << book.price << endl;
    return 0;
}