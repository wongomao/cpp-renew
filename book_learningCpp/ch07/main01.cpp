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

    // erase and length
    a.erase(a.length() - 3, 3); // erase 3 characters starting at position -3
    cout << a << endl; // onetwothree
    a.clear(); // erase all characters
    cout << "after clear: " << a << endl; // empty string

    // substr
    a = "velociraptor";
    cout << "a = " << a << "; a.substr(3, 5) = " << a.substr(3, 5) << endl; // ocira
    cout << "a.substr(a.length() - 6, 6) = " << a.substr(a.length() - 6, 6) << endl; // raptor

    cout << "-------------------" << endl;
    // find
    cout << "a.find(\"raptor\") = " << a.find("raptor") << endl; // 6
    // find returns string::npos if not found; npos is a static member constant value with
    // the greatest possible value for an element of type size_t
    // npos = no position
    string my_string{ "This is a test" };
    string string_to_find{ "is" };
    size_t position{ my_string.find(string_to_find) };
    cout << "my_string = " << my_string << "; string_to_find = " << string_to_find << ";" << endl;
    if (position != string::npos)
        cout << "found " << string_to_find << " at position " << position << endl;
    else
        cout << "not found" << endl;
    // start searching from position 4
    cout << "start searching from position 4" << endl;
    position = my_string.find(string_to_find, 4);
    if (position != string::npos)
        cout << "found \"" << string_to_find << "\" at position " << position << endl;
    else
        cout << "not found" << endl;
    cout << "-------------------" << endl;
    // not found
    cout << "searching for \"square\" in \"" << my_string << "\"" << endl;
    string_to_find = "square";
    position = my_string.find(string_to_find);
    if (position != string::npos)
        cout << "found \"" << string_to_find << "\" at position " << position << endl;
    else
        cout << "not found" << endl;
    cout << "-------------------" << endl;

    // rfind with preprocessor directive
#ifdef _WIN32
    char path_separator{ '\\' };
    string full_path{ "C:\\Users\\nparker\\Documents\\debug.log" };
#else
    char path_separator{ '/' };
    string full_path{ "/home/nparker/Documents/debug.log" };
#endif
    cout << "full_path = " << full_path << endl;
    string base_filename = full_path.substr(full_path.rfind(path_separator) + 1);
    cout << "base_filename = " << base_filename << endl;

    return 0;
}