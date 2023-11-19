#ifndef CONTAINER_H
#define CONTAINER_H

// A class with a pure virtual function is called an abstract class
// and cannot be used to create objects.
// the =0 suffix in the declaration of operator[] and size() indicates that these are pure virtual functions.
// Notice there is no constructor, as there is nothing to initialize.
class Container {
public:
    virtual double& operator[](int) = 0; // pure virtual function
    virtual int size() const = 0; // const member function (§2.2.1)
    virtual ~Container() {} // destructor (§2.2.2)
};

#endif // CONTAINER_H