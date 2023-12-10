#include <iostream>
#include <string>

using namespace std;

int main()
{
    // using getline() allows multiple words; cin only allows a single word
    // string test{ "" };
    // cout << "Please type any sentence" << endl;
    // getline(cin, test);
    // cout << "your input was: " << test << endl;

    // string user_name{ "default" }, new_user_name{};
    // cout << "Please enter a new user name" << endl;
    // cin >> new_user_name;
    // user_name = new_user_name; // using copy
    // cout << "your new user name is " << user_name << endl;

    // concat using +
    string a{ "one" }, b{ "two" }, c{ "three" };
    a = a + b + c;
    cout << a << endl; // onetwothree
    // or use append
    a.append(b);
    cout << a << endl; // onetwothreetwo

    // starting section 7.3.3

    return 0;
}