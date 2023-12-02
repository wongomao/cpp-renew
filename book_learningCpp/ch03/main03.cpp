#include <iostream>
#include <compare>

int main()
{
    int b{}, a{};
    std::cout << "Enter a integer: ";
    std::cin >> a;
    std::cout << "Enter b integer: ";
    std::cin >> b;
    if ( a <=> b == std::strong_ordering::equal )
        std::cout << "a == b" << std::endl;
    else if ( a <=> b == std::strong_ordering::greater )
        std::cout << "a > b" << std::endl;
    else
        std::cout << "a < b" << std::endl;
}