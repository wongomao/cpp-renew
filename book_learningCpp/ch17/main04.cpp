#include <iostream>
#include <exception>

class DivideByZeroException : public std::runtime_error
{
public:
    // message "Division by zero" is passed to the base class constructor
    // and is used to initialize the base class part of the object
    // and will be used as the default return value of the what() function
    DivideByZeroException() : std::runtime_error("Division by zero") {}
    // override the what() function for a custom message
    const char* what() const noexcept override
    {
        return "DivideByZeroException is a custom exception for division by zero.";
    }
};

int main()
{
    try
    {
        int x = 0;
        if (x == 0)
        {
            throw DivideByZeroException();
        }
        std::cout << 5 / x << std::endl;
    }
    catch(const DivideByZeroException& e)
    {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }
    return 0;
}