#include <iostream>
#include "includes/calculations.h"

int main()
{
    int x{ get_integer() };
    char op{ get_operator() };
    int y{ get_integer() };

    int result{ 0 };
    switch (op)
    {
        case '+':
            result = add(x, y);
            break;
        case '-':
            result = sub(x, y);
            break;
        default:
            std::cout << "Invalid operator\n";
            return 1;
    }

    show_result(result);

    return 0;
}