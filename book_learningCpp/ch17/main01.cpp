#include <iostream>

int main()
{
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    try
    {
        if (num2 == 0)
        {
            throw "Division by zero is not possible.";
        }
        int result = num1 / num2;
        std::cout << "Result: " << result << std::endl;
    }
    catch(const char* errorMessage)
    {
        std::cerr << errorMessage << std::endl;
    }
    
    std::cout << "Program continues after handling the exception." << std::endl;

    return 0;
}