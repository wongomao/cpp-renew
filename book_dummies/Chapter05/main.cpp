#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 20; i = i + 3)
    {
        cout << i << '\t';
    }
    cout << endl;
    cout << "-------------------------" << endl;
    string A = "Hello";
    string B = "11223344556677";
    for (int i = 0, j = 0; i < 5; i++, j += 2)
    {
        cout << A[i] << '\t' << B[j] << endl;
    }
    cout << "-------------------------" << endl;
    int range[] = {1, 2, 3, 4, 5};
    for (int i: range)
    {
        cout << i << '\t';
    }
    cout << endl;
    for (int i=0; auto c = A[i]; i++)
    {
        cout << c << '\t';
    }
    cout << endl;
    for (int i=0; auto c = range[i]; i++)
    {
        cout << c << '\t';
    }
    cout << endl;
    cout << "-------------------------" << endl;
    int i = 0;
    while (i < 20)
    {
        cout << i << '\t';
        i = i + 3;
    }
    cout << endl;
    cout << "-------------------------" << endl;
    i = 0;
    bool done = false;
    while (!done)
    {
        cout << i << '\t';
        i = i + 3;
        done = (i >= 20);
    }
    cout << endl;
    cout << "-------------------------" << endl;
    i = 0;
    do
    {
        cout << i << '\t';
        i = i + 3;
    } while (i < 20);
    cout << endl;
    cout << "-------------------------" << endl;
    i = 0;
    do
    {
        cout << i << '\t';
        i = i + 3;
        if (i >= 80)
        {
            break;
        }
    } while (i < 200);
    cout << endl;
    cout << "-------------------------" << endl;
    i = 0;
    do
    {
        i = i + 3;
        if (i % 5 == 0) {
            cout << "fiver" << '\t';
            continue;
        }
        cout << i << '\t';
    } while (i < 200);
    cout << endl;
    cout << "-------------------------" << endl;
    return 0;
}
