#include <iostream>
#include <array>

// Define a function pointer type that matches the signature of the lambda
using LambdaFunctionPtr = int(*)(int, int);

int main()
{
    int num1 = 10;
    int num2 = 20;

    auto lambda_capture_value = [num1]()
    {
        std::cout << "Lambda capture by value: " << num1 << std::endl;
        // variable num1 is captured by value, so it is read-only
        // if we need to modify it, we need to use 'mutable' keyword
    };

    auto lambda_capture_reference = [&num2]()
    {
        std::cout << "Lambda capture by reference before modification: " << num2 << std::endl;
        num2 += 100;
        std::cout << "Lambda capture by reference after modification: " << num2 << std::endl;
    };

    lambda_capture_value();
    lambda_capture_reference();

    std::cout << "num1 after lambda call: " << num1 << std::endl;
    std::cout << "num2 after lambda call: " << num2 << std::endl;

    // ------------------------------------------------------------
    // mutable lambda
    std::cout << "\n\n------------------ mutable lambda --------------------" << std::endl;
    int counter = 0;
    auto incrementCounter = [counter]() mutable
    {
        counter++;
        std::cout << "Inside lambda - counter: " << counter << std::endl;
    };

    std::cout << "initial counter: " << counter << std::endl;
    incrementCounter();
    std::cout << "counter after first incrementCounter: " << counter << std::endl;
    incrementCounter();
    std::cout << "counter after second incrementCounter: " << counter << std::endl;

    // ------------------------------------------------------------
    // mixed capturing lambda
    std::cout << "\n\n------------------ mixed capturing lambda --------------------" << std::endl;
    int x = 42;
    int y = 0;
    auto lambda = [x, &y]() mutable
    {
        x = 10;
        y = 20;
    };
    lambda();
    std::cout << "Modified values x: " << x << ", y = " << y << std::endl;

    // ------------------------------------------------------------
    // lambda sizes
    std::cout << "\n\n------------------ lambda sizes --------------------" << std::endl;
    auto lambda1 = [](){};
    std::cout << "basic empty lambda size: " << sizeof(lambda1) << std::endl;
    
    std::array<char, 100> ar;
    auto lambda2 = [&ar](){};
    std::cout << "referenced array lambda size: " << sizeof(lambda2) << std::endl;
    
    auto lambda3 = [ar](){};
    std::cout << "value array lambda size: " << sizeof(lambda3) << std::endl;

    // ------------------------------------------------------------
    // lambda function pointer
    std::cout << "\n\n------------- lambda function pointer ---------------" << std::endl;
    auto lambda4 = [](int x, int y) -> int { return x + y; };
    auto lambda5 = [](int x, int y) -> int { return x - y; };

    // Assign the address of the (capture-less) lambda to a function pointer
    LambdaFunctionPtr funcPtr = [](int x, int y) -> int { return x * y; };

    // use the function pointer
    int result = funcPtr(5, 3);
    std::cout << "result: " << result << std::endl;
    /*Lambdas without captures can be easily assigned, and have the 
    same type, but lambdas with captures have their own unique types, 
    and cannot be assigned to each other directly.*/

    return 0;
}