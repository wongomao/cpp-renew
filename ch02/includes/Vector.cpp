#include <iostream>
#include "Vector.h"
using namespace std;

void vector_init(Vector& v, int s) {
    v.elem = new double[s];
    for (int i = 0; i != s; ++i) {
        v.elem[i] = 0;
    }
    v.sz = s;
}

void show_all(Vector& v) {
    cout << "v:\t";
    for (int i = 0; i != v.sz; ++i) {
        cout << v.elem[i] << '\t';
    }
    cout << endl;
}

void vector_destroy(Vector& v) {
    delete[] v.elem;
    v.elem = nullptr;
    v.sz = 0;
}