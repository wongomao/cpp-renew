#include <iostream>
 
int Calc(int num1, int num2)
{
    int result = num1 + num2;
    return result;
}
int Calc(int& num1, int& num2)
{
    int result = num1 + num2;
    return result;
}
 
int main()
{
    int num1{ 5 };
    int num2{ 10 };
    int result{};
    result = Calc(num1, num2);
}