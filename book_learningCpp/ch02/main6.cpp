#include <iostream>
int main()
{
    auto myNum = 42;
    auto myFloat = 3.14159;
    auto myChar = 'z';
    std::cout << "myNum is of type " << typeid(myNum).name() << " and has value " << myNum << "\n";
    std::cout << "myFloat is of type " << typeid(myFloat).name() << " and has value " << myFloat << "\n";
    std::cout << "myChar is of type " << typeid(myChar).name() << " and has value " << myChar << "\n";
    std::cout << "-------------------------\n";
    int num{};
    int age { 15 };
    double temp { 12.3 };
    char label { 'L' };
    int* n_ptr{}; // n_ptr is a null pointer
    double d{}; // d is zero
    bool b{}; // b is false
    int scores[5]{}; // all 5 elements are zero
    // int i{ 5.3 }; // i becomes 5, implicit conversion from double to int - not allowed
    const double PI { 3.14159 }; // PI is a const double with value 3.14159
    
    return 0;
}