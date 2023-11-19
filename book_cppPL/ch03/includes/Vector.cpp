#include <stdexcept>
#include "Vector.h"

Vector::Vector(int s) :elem{ new double[s] }, sz{ s }
{
}

// initializer_list constructor, uses std::copy to copy the elements from the list into the Vector
// use it like this: Vector v = {1, 2, 3, 4, 5};
Vector::Vector(std::initializer_list<double> lst) :elem{ new double[lst.size()] }, sz{ static_cast<int>(lst.size()) }
{
    std::copy(lst.begin(), lst.end(), elem);
}

Vector::~Vector()
{
    delete[] elem;
}

double& Vector::operator[](int i)
{
    if (i < 0 || i >= sz)
        throw std::out_of_range("Vector::operator[]");
    return elem[i];
}

int Vector::size() const
{
    return sz;
}

double Vector::sum()
{
    double sum = 0;
    for (int i = 0; i < sz; ++i)
    {
        sum += elem[i];
    }
    return sum;
}