#include <iostream>
#include <functional> // in order to use std::function

/*
Passing a pointer to a function to another function

While function pointers provide a basic mechanism for passing functions 
as parameters, they lack flexibility and can be cumbersome to use, 
especially when dealing with different function signatures. Additionally, 
they do not offer type safety and can lead to runtime errors if misused.
*/

typedef void (*OperationFunction)(int);

// PerformOperation takes an int `value` and a function pointer `operation`.
// It is responsible for performing the operation on the value by calling the
// specified function.
void PerformOperation(int value, OperationFunction operation)
{
    std::cout << "Performing operation on value: " << value << std::endl;
    operation(value);
}

// MultiplyByTwo takes an int `value` and prints the value multiplied by two.
// Note that this function matches the signature of OperationFunction.
void MultiplyByTwo(int value)
{
    std::cout << value << " multiplied by 2 is: " << (value * 2) << std::endl;
}

/******************************************************************************
INSTEAD
std::function is a flexible and type-safe way to store, pass, and invoke 
callable objects, such as functions, and function pointers.
Think of std::function as a special box that can store DIFFERENT TYPES of
functions.
*******************************************************************************/
// PerformOperation2 takes an int `value` and a std::function `operation`.
// The std::function object represents a function that takes an int and returns
// void.
void PerformOperation2(int value, std::function<void(int)> operation)
{
    std::cout << "Performing operation on value: " << value << std::endl;
    operation(value);
}



/******************************************************************************
 * MAIN
*******************************************************************************/
int main()
{
    int number = 5;
    // We call PerformOperation with number and a pointer to MultiplyByTwo.
    // This will call MultiplyByTwo(number) inside PerformOperation.
    PerformOperation(number, MultiplyByTwo); // Passing a pointer to MultiplyByTwo

    PerformOperation2(number, MultiplyByTwo); // Passing a std::function to MultiplyByTwo

    // We call PerformOperation2 with number and a lambda function that prints
    // the value multiplied by three. See this more in chapter 12.
    PerformOperation2(number, [](int value) { std::cout << value << " multiplied by 3 is: " << (value * 3) << std::endl; });

    return 0;
}