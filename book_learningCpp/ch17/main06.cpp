#include <iostream>
#include <vector>
#include <stdexcept> 

int main()
{
    std::vector<int> numbers = { 10, 20, 30, 40, 50 };

    try 
    {
        int value = numbers.at(10);
        std::cout << "Value at index 10: " << value << std::endl;
    }
    catch (const std::out_of_range& e) 
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
/*
Output:
Error: vector::_M_range_check: __n (which is 10) >= this->size() (which is 5)
*/