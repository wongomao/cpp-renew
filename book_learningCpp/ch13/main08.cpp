#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>

// Our function template, catThinking, accepts a lambda to handle its operation
template <typename Func>
void catThinking(Func func)
{
    std::cout << std::endl << "Cat is thinking: ";
    func();
    std::cout << std::endl;
}

/*
The catDecides function is a callback function that accepts a
std::function, which can accommodate both stateless and stateful lambdas
*/
void catDecides(std::function<void()> callback)
{
    callback();
}

// where are the above functions used???

/*
In the overloaded function object, we're specifying that toys should be
compared based on their length (i.e., the cat prfers longer toy names)
*/
struct ToyLengthComparer
{
    template <typename T>
    bool operator()(const T& lhs, const T& rhs)
    {
        return lhs.size() < rhs.size();
    }
};

struct ToyAlphabeticalComparer
{
    template <typename T>
    bool operator()(const T& lhs, const T& rhs)
    {
        return lhs < rhs;
    }
};

int main()
{
    std::cout << "Enter toys for the cat separated by commas ";
    std::cout << "(e.g., 'ball, mouse, string, feather'):" << std::endl;

    std::string toys;
    std::getline(std::cin, toys);
    
    // Split the string into a vector of strings
    std::vector<std::string> toyVector;
    std::stringstream ss(toys);
    std::string toy;
    while (std::getline(ss, toy, ','))
    {
        toyVector.push_back(toy);
    }
    if (toyVector.empty())
    {
        std::cout << "No toys? The cat is sad." << std::endl;
        return 1;
    }

    // Sort the toys based on choice
    std::cout << "How should the cat sort the toys?";
    std::cout << " (enter 'length' or 'alphabetical'):" << std::endl;
    std::string choice;
    std::getline(std::cin, choice);
    if (choice == "length")
    {
        std::sort(toyVector.begin(), toyVector.end(), ToyLengthComparer());
    }
    else if (choice == "alphabetical")
    {
        std::sort(toyVector.begin(), toyVector.end(), ToyAlphabeticalComparer());
    }
    else
    {
        std::cout << "Invalid choice. The cat is sad." << std::endl;
        return 1;
    }

    for (auto& toy : toyVector)
    {
        std::cout << "The cat likes " << toy << std::endl;
    }

    return 0;
}