#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    cout << "Hell O Squirreled!" << endl;
    cout << "5.9 is " << 5.9 << endl;
    int myNum;
    cout << "myNum is " << myNum << endl;
    return 0;
}