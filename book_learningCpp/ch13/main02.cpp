#include <iostream>
#include <vector>
#include <algorithm>

// free-standing function
constexpr auto isEven1 = [](int num) { return num % 2 == 0; };

int main()
{
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // lambda expression
    // a different instance of the lambda expression is created for each call
    auto isEven = [](int num) { return num % 2 == 0; };
    std::cout << "Even numbers: ";
    for (const int& num : numbers)
    {
        if (isEven(num))
        {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;

    std::vector<int> evenNumbers;
    // use the above declared lambda expression if you want to use it more than once
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evenNumbers), isEven1);
    std::cout << "Even numbers: ";
    for (const int& num : evenNumbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}