#include <iostream>
#include <algorithm>
#include <vector>

// check if an array is sorted in ascending order
int main() 
{
    std::vector<int> numbers1 = { 1, 2, 3, 5, 4, 6 };
    bool isSorted = std::is_sorted(numbers1.begin(), numbers1.end());

    if (isSorted) 
    {
        std::cout << "The range is sorted in non-decreasing order." << std::endl;
    }
    else 
    {
        std::cout << "The range is not sorted in non-decreasing order." << std::endl;
    }

    return 0;
}