#include <iostream>
#include "VectorStruct.h"
using namespace std;

void vector_init(VectorStruct& v, int s) {
    v.elem = new double[s];
    for (int i = 0; i != s; ++i) {
        v.elem[i] = 0;
    }
    v.sz = s;
}

void show_all(VectorStruct& v) {
    cout << "v:\t";
    for (int i = 0; i != v.sz; ++i) {
        cout << v.elem[i] << '\t';
    }
    cout << endl;
}

double read_and_sum(int s) {
    VectorStruct v;
    vector_init(v, s);
    cout << "Please enter " << s << " numbers:" << endl;
    for (int i = 0; i != s; ++i) {
        cin >> v.elem[i];
    }
    double sum = 0;
    for (int i = 0; i != s; ++i) {
        sum += v.elem[i];
    }
    vector_destroy(v);
    return sum;
}

void vector_destroy(VectorStruct& v) {
    delete[] v.elem;
    v.elem = nullptr;
    v.sz = 0;
}

void vector_action(VectorStruct v, VectorStruct& rv, VectorStruct* pv) {
    cout << "v.sz = " << v.sz << endl;
    cout << "v.elem = " << v.elem << endl;
    cout << "rv.sz = " << rv.sz << endl;
    cout << "rv.elem = " << rv.elem << endl;
    cout << "pv->sz = " << pv->sz << endl;
    cout << "pv->elem = " << pv->elem << endl;
}