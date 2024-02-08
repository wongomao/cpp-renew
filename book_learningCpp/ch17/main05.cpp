#include <iostream>
#include <stdexcept>
#include <cmath>

double calculateSquareRoot(double num)
{
    if (num < 0)
    {
        throw std::invalid_argument("Input must be a non-negative number");
    }
    return sqrt(num);
}

int main()
{
    try
    {
        double result = calculateSquareRoot(-5.0);
        std::cout << "Square root: " << result << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}