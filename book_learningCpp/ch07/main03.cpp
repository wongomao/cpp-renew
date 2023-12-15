#include <iostream>
#include <string>

using namespace std;

// it is necessary to build this with C++20
// g++ -o .\book_learningCpp\ch07\main03.exe .\book_learningCpp\ch07\main03.cpp -std=c++2a

int main()
{
    string str1{ "Give papa a cup of proper coffee in a copper coffee cup." };
    if (str1.starts_with("Give"))
    {
        cout << "\"" << str1 << "\" starts with \"Give\"" << endl;
    }
    if (str1.ends_with("cup."))
    {
        cout << "\"" << str1 << "\" ends with \"cup.\"" << endl;
    }

    return 0;
}