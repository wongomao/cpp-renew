#ifndef Vector_Container_H
#define Vector_Container_H

#include "Container.h"
#include "Vector.h"

class Vector_Container : public Container { // Vector_Container implements Container
public:
    Vector_Container(int s); // Vector_Container holds s elements
    ~Vector_Container();
    double& operator[](int i);
    int size() const;
};


#endif // Vector_Container_H