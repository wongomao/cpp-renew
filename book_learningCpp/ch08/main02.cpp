#include <iostream>

using namespace std;

// function overloading

int CalcSum(int x, int y)
{
    return x + y;
}

int CalcSum(int x, int y, int z)
{
    return x + y + z;
}

float CalcSum(float x, float y)
{
    return x + y;
}

int main()
{
    cout << CalcSum(1, 2) << endl;
    cout << CalcSum(1, 2, 3) << endl;
    cout << CalcSum(1.6f, 2.7f) << endl;

    return 0;
}