#include "Split.h"

/**
 *  模板类的类外外实现
 */

template<typename A>
Split<A>::Split(A a) {
    this->a = a;
}

template<typename A>
void Split<A>::dance() {
    cout << a << endl;
}

void testNamespace(){
    cout << "name space success" << endl;
}

namespace spl{

}


