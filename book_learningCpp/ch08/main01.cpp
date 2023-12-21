#include <iostream>
#include <string>
#include <algorithm>

/*
The inline keyword is used to suggest to the compiler that the function body
should be embedded directly at each place the function is called.

It is important to note that the decision of whether to inline the function
is ultimately made by the compiler and not guaranteed by the keyword alone.
*/
inline void SetLower(std::string& s) { std::transform(s.begin(), s.end(), s.begin(), tolower); }

int main()
{
    std::string test{ "AbcDEFghi" };
    std::cout << "Before calling SetLower(): " << test.c_str() << std::endl;
    SetLower(test);
    std::cout << "After calling SetLower(): " << test.c_str() << std::endl;

    return 0;
}