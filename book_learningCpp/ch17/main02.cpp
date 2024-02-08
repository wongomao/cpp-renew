#include <iostream>

void performDivision(int dividend, int divisor)
{
    if (divisor == 0)
    {
        throw "Division by zero is not allowed.";
    }

    int result = dividend / divisor;
    std::cout << "Result of division: " << result << std::endl;
}

int main()
{
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    {
        try
        {
            // function call logically enclosed within the try block
            // not physically enclosed
            performDivision(num1, num2);
        }
        catch(const char* errorMessage)
        {
            std::cout << errorMessage << std::endl;
        }
    }
    
    std::cout << "Program continues after the try-catch block." << std::endl;

    return 0;
}