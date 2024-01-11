#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "Our original vector {1,2,3,4,5}" << std::endl;
    std::vector<int> v{1,2,3,4,5};
    int factor = 2;
    std::for_each(v.begin(), v.end(), [factor](int& n)
        {
            n *= factor;
        });
    
    std::cout << "After multiplying each element by " << factor << ": " << std::endl;
    for (auto& n : v)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}