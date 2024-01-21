#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
 
int main() 
{
    std::vector<int> numbers = { 5, 3, 1, 4, 2 };

    auto sortNumbers = numbers;
    std::ranges::sort(sortNumbers); // note that we needed to use <algorithm> sort

    auto filterEven = numbers | std::views::filter([](int n) { return n % 2 == 0; });

    auto squareAndSort = numbers | std::views::transform([](int n) { return n * n; });
    // build new container from range
    std::vector<int> squareAndSortContainer(squareAndSort.begin(), squareAndSort.end());
    std::ranges::sort(squareAndSortContainer);

    auto takeFirstThree = numbers | std::views::take(3);

    std::cout << "Original numbers: ";
    for (int number : numbers) 
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted numbers: ";
    for (int number : sortNumbers) 
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    std::cout << "Filtered even numbers: ";
    for (int number : filterEven) 
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    std::cout << "Squared and sorted numbers: ";
    for (int number : squareAndSortContainer) 
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    std::cout << "First three numbers: ";
    for (int number : takeFirstThree) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}