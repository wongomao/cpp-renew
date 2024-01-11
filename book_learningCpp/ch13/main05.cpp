#include <iostream>
#include <vector>
#include <algorithm>

// define a lambda function 'printer' with a template parameter T.
// This lambda takes a constant reference to an object of type T
// and prints it to the console.
constexpr auto printer = []<typename T> (const T& element)
    {
        std::cout << element << " ";
    };

// We define a function template 'printElements' that takes a 
// vector of type T by reference
template <typename T>
void printElements(const std::vector<T>& elements)
{
    std::for_each(elements.begin(), elements.end(), printer);
    std::cout << std::endl;
}

int main()
{
    std::vector<int> numbers = {1,2,3,4,5};
    std::vector<std::string> names = { "Alice", "Bob", "Charlie", "Dave", "Eve" };

    std::cout << "Numbers: ";
    printElements(numbers);
    std::cout << "Names: ";
    printElements(names);
}