#include <iostream>

// non-type template parameters

constexpr int getValue()
{
    return 5;
}

template <char C, int N>
void processValue(int* ptr)
{
    std::cout << "Char: " << C << ", Integer: " << N;
    std::cout << ", Pointer: " << *ptr << std::endl;
}

int main()
{
    int value = getValue();
    int* ptr = &value;
    processValue<'a', 10>(ptr);
    return 0;
}