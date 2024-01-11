#include <iostream>
#include <functional>


int main()
{
    // define a lambda function 'add' that takes two integers
    std::function<int(int, int)> add = [](int a, int b)
    {
        return a + b;
    };

    int result = add(5, 3);
    std::cout << "5 + 3 = " << result << std::endl;

    return 0;
}