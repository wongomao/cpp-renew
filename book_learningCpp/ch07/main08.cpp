#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string sample1{ "Time flies like an arrow, but fruit flies like a banana." };
    string sample2{ "Time flies like an arrow, but fruit flies like bananas." };
    cout << "sample1: " << sample1 << endl;
    cout << "sample2: " << sample2 << endl;

    cout << "-- simple comparison --" << endl;
    // notice that here the strings are compared using their default lexicographic comparison,
    // i.e. uppercase letters are less than lowercase letters
    if (sample1 < sample2)
    {
        cout << "\"" << sample1 << "\" is less than \"" << sample2 << endl;
    }
    else
    {
        cout << "\"" << sample2 << "\" is less than \"" << sample1 << endl;
    }

    cout << "-- case insensitive comparison / <=> spaceship comparison --" << endl;
    const auto order = sample1 <=> sample2;
    if (is_lt(order))
    {
        cout << "sample1 is less than sample2" << endl;
    }
    else if (is_gt(order))
    {
        cout << "sample1 is more than sample2" << endl;
    }
    else
    {
        cout << "sample1 is equal to sample2" << endl;
    }

    cout << "----------------------------------------" << endl;
    // spaceship operator can be used to compare any two objects that have a default comparison operator
    // it saves multiple comparisons and is more efficient

    // comparison of vectors of strings
    vector<string> v1{ "apple", "banana", "cherry", "date", "elderberry", "fig" };
    vector<string> v2{ "apple", "banana", "cherry", "blueberry", "fig", "grape" };
    cout << "v1: ";
    for (const auto& s : v1)
    {
        cout << s << " ";
    }
    cout << endl;
    cout << "v2: ";
    for (const auto& s : v2)
    {
        cout << s << " ";
    }
    cout << endl;

    const auto orderV = v1 <=> v2;
    if (is_lt(orderV))
    {
        cout << "v1 is lexicographically less than v2" << endl;
    }
    else if (is_gt(orderV))
    {
        cout << "v1 is lexicographically greater than v2" << endl;
    }
    else
    {
        cout << "v1 is lexicographically equal to v2" << endl;
    }

    cout << "----------------------------------------" << endl;
    string s1{ "apple" };
    string s2{ "apple" };
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    if (s1.compare(s2) < 0)
    {
        cout << "s1 is less than s2" << endl;
    }
    else if (s1.compare(s2) > 0)
    {
        cout << "s1 is greater than s2" << endl;
    }
    else
    {
        cout << "s1 is equal to s2" << endl;
    }

    return 0;
}