#include <iostream>

int get_integer()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

char get_operator()
{
    std::cout << "Enter an operator (+ or -): ";
    char op{};
    std::cin >> op;
    return op;
}

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

void show_result(int z)
{
    std::cout << "The answer is: " << z << '\n';
}