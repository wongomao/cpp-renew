#include <iostream>

// demonstrate passing a function as an argument to another function
// and how the callback is executed
// note: regular functions calling function callbacks without lambda
void performTask(void (*callbackFunction)())
{
    std::cout << "Performing the main task..." << std::endl;

    callbackFunction();
}

void callbackFunction()
{
    std::cout << "Performing the callback task..." << std::endl;
}

int main()
{
    performTask(callbackFunction);

    return 0;
}