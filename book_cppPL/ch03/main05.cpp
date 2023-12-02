#include <iostream>

template<typename T>
class Vector {
public:
    explicit Vector(int s);
    T& operator[](int i);
    const T& operator[](int i) const;
    int size() const;
}

// stuff from chapter 3 doesn't work

template<typename T>
Vector<T>::Vector(int s)
    :elem{new T[s]}, sz{s}
{
}