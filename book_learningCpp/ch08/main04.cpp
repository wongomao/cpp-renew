#include <iostream>

template <typename T>
T CalcMax(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    std::cout << CalcMax(1, 2) << std::endl;
    std::cout << CalcMax(2.5, 1.5) << std::endl;
    std::cout << CalcMax('a', 'b') << std::endl;
    std::cout << CalcMax("Hello", "World") << std::endl;
    return 0;
}