#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        int num1, num2;
        std::cout << "Enter two numbers: ";
        std::cin >> num1 >> num2;

        try
        {
            if (num2 == 0)
            {
                throw std::logic_error("Division by zero");
            }
 
            int result = num1 / num2; // Perform division
            std::cout << "Result: " << result << std::endl;
        }
        catch (const std::logic_error& e)
        {
            std::cout << "Caught logic_error: " << e.what() << std::endl;
            throw; // rethrow the exception to catch in catch-all
        }
        catch (const std::runtime_error& e)
        {
            std::cout << "Caught runtime_error: " << e.what() << std::endl;
        }
    }
    catch (...) // catch all other exceptions
    {
        std::cout << "Caught an unknown exception" << std::endl;
    }

    return 0;
}