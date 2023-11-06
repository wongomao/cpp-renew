#include <iostream>
#include "includes\various.h"
#include "includes\Vector.h"
using namespace std;

int main()
{
    action1();
    //bool answer = accept3();
    //examineReference();

    Vector v = { 0, nullptr };
    vector_init(v, 5);
    cout << "v.sz = " << v.sz << endl;
    cout << "v.elem = " << v.elem << endl;
    show_all(v);
    cout << "destroy(v)" << endl;
    vector_destroy(v);
    cout << "v.sz = " << v.sz << endl;
    return 0;
}