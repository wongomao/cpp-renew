#ifndef VECTOR_H
#define VECTOR_H

// Vector is a container class that holds a collection of doubles
// It is allocated on the free store and is freed when out of scope
// much like a variable of built-in type
class Vector {
public:
    Vector(int s);
    Vector(std::initializer_list<double> lst);
    ~Vector();
    double& operator[](int i);
    int size() const;
    double sum();
private:
    double* elem;
    int sz;
};



#endif // VECTOR_H