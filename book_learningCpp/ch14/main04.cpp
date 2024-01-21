#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

/*
Example of combining views and actions
EAGER loading vs. LAZY loading

Use lazy loading when we do not expect to need all the items in a collection
to need processing; or when items do not need to be processed more than once.

Use eager loading to calculate all elements in a collection and when
we know they will be accessed often.
*/

int main() 
{
    std::vector<int> numbers = { 5, 3, 1, 4, 2 };

    auto evenView = numbers | std::views::filter([](int n) { return n % 2 == 0; });

    auto squareView = numbers | std::views::transform([](int n) { return n * n; });

    std::ranges::sort(numbers);

    std::cout << "Even numbers: ";
    for (int number : evenView) 
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    std::cout << "Squared numbers: ";
    for (int number : squareView) 
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted numbers: ";
    for (int number : numbers) 
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}