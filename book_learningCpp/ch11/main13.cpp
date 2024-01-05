#include <iostream>
#include <numeric>
#include <vector>

int main() 
{
    std::vector<int> v{ 2, 12, 30, 15, 33, 10, 78, 10 };
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "The sum of all the elements in the vector is " << sum << std::endl;
}