// using explicit constexpr with lambda
#include <iostream>

/*
The function add is declared as constexpr, indicating
that it can be evaluated at compile-time and used in
constant expressions.
*/
constexpr int add(int a, int b)
{
    return a + b;
}

int main()
{
    /*
    The lambda function is declared as constexpr, allowing it to
    be evaluated at compile-time. The lambda takes two integer 
    parameters and returns their sum.
    */
    constexpr auto lambda = [](int x, int y) constexpr
    {
        return x + y;
    };

    /*
    Both result1 and result2 are declared as constexpr variables,
    indicating that their values can be computed at compile-time.
    This is possible because add and lambda are constexpr and the
    arguments passed are known at compile-time. Therefore, the
    evaluations of add(5, 3) and lambda(5, 3) occur during 
    compilation rather than at runtime.
    */
    constexpr int result1 = add(5, 3);
    constexpr int result2 = lambda(5, 3);

    std::cout << "result1: 5 + 3 = " << result1 << std::endl;
    std::cout << "result2: 5 + 3 = " << result2 << std::endl;

    return 0;
}