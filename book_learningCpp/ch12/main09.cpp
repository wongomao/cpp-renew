#include <iostream>
#include <concepts>

template<typename T>
concept EqualityComparable = requires(T a, T b)
{
    { a == b } -> std::convertible_to<bool>;
    { a != b } -> std::convertible_to<bool>;
};

template<EqualityComparable T>
void compareValues(const T& a, const T& b)
{
    if constexpr (EqualityComparable<T>)
    {
        if (a == b)
        {
            std::cout << "Values are equal." << std::endl;
        }
        else
        {
            std::cout << "Values are not equal." << std::endl;
        }
    }
    else
    {
        std::cout << "Cannot compare values." << std::endl;
    }
}

int main()
{
    int x = 5;
    int y = 10;
    compareValues(x, y);

    std::string str1 = "Hello";
    std::string str2 = "Hello";
    compareValues(str1, str2);

    return 0;
}