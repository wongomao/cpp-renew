#include <iostream>
#include <vector>
#include <ranges>

void showVector(const std::vector<int> &vec)
{
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << "numbers: ";
    showVector(numbers);

    // construct a range using a lambda
    auto oddNumbers = numbers | std::views::filter([](int num)
    {
        return num % 2 != 0;
    });
    std::cout << "oddNumbers: ";
    // showVector(oddNumbers); no worky because oddNumbers is a range, not a vector
    for (auto i : oddNumbers)
        std::cout << i << " ";
    std::cout << std::endl;

    // naming a lambda can make it more readable
    auto make_even = [](int num) { return num % 2 == 0; };
    auto evenNumbers = numbers
        | std::views::filter(make_even)
        | std::views::reverse;
    std::cout << "evenNumbers reversed: ";
    for (auto i : evenNumbers)
        std::cout << i << " ";
    std::cout << std::endl;
}