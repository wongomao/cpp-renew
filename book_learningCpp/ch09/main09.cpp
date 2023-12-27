#include <iostream>

int main()
{
    int x = 5;
    int* const ptr = &x;
    *ptr = 6; // this is fine
    std::cout << "The value our pointer points to is: " << *ptr << std::endl;

    const int a = 7;
    int y{ 10 };
    // int *p = &a; // disallowed because a is const
    int *p = &y;
    std::cout << "The value our pointer points to is: " << *p << std::endl;
}