#include <iostream>

// This is a simple program to test our code listing on
int main()
{
    // Print a greeting message
    std::cout << "Hello, World!" << std::endl;

    // TODO: Add more functionality
    int sum = 0;
    for (int i = 0; i < 10; ++i)
    {
        sum += i;
    }

    // Display the sum
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}