#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        try
        {
            throw std::runtime_error("Exception 1");
        }
        catch(const std::logic_error& e) // logic_error is a base class of runtime_error
        {
            std::cout << "Caught logic_error: " << e.what() << std::endl;
        }
        catch (const std::runtime_error& e)
        {
            std::cout << "Caught runtime_error: " << e.what() << std::endl;

            throw; // rethrow the exception
        }
        
    }
    catch(const std::runtime_error& e)
    {
        std::cout << "Caught rethrown exception: " << e.what() << std::endl;
    }

    return 0;
}