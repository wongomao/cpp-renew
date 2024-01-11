#include <iostream>
#include <concepts>

template <typename T>
class MyContainer
{
public:
    void print(const T& value) requires std::integral<T>;
    void print(const T& value) requires std::floating_point<T>;
};

template <typename T>
void MyContainer<T>::print(const T& value) requires std::integral<T>
{
    std::cout << "Integral value: " << value << std::endl;
}

template <typename T>
void MyContainer<T>::print(const T& value) requires std::floating_point<T>
{
    std::cout << "Floating-point value: " << value << std::endl;
}

int main() 
{
    MyContainer<int> intContainer;
    intContainer.print(42);
 
    MyContainer<double> doubleContainer;
    doubleContainer.print(3.14);
 
    return 0;
}