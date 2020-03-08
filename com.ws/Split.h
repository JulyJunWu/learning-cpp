#include "iostream"

using namespace std;

/**
 *  声明模板类 , 具体实现交给同名的cpp实现
 */
template<typename A>
class Split {
public:
    A a;

    Split(A a);

    void dance();
};
