#include "Vector_Container.h"
#include "Vector.h"

class Vector_Container : public Container { // Vector_Container implements Container
    Vector v;
public:
    Vector_Container(int s) : v(s) { } // Vector_Container holds s elements
    ~Vector_Container() {}

    double& operator[](int i) { return v[i]; } // Vector_Container's implementation of operator[]
    int size() const { return v.size(); }
};
