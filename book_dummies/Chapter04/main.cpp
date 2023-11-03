#include <iostream>

using namespace std;

int main() {
    int first = 29;
    int second = 4;
    cout << first << " / " << second << " = " << first / second << endl;
    cout << first << " % " << second << " = " << first % second << endl;
    cout << " -------------------------- " << endl;
    cout << "Printable ASCII [32..126]:\n";
    for (char c{' '}; c <= '~'; ++c) {
        cout << "    \'" << c << "\':" << int(c) << ((c + 1) % 8 ? ' ' : '\n');
    }
    cout << '\n';
    cout << " -------------------------- " << endl;
    string s1 = "Good";
    string s2 = "Morning";
    cout << s1 << " " << s2 << " strings." << endl;
    cout << " -------------------------- " << endl;
    first = 29;
    second = 4;
    int result = (first > second) ? first : second;
    cout << "The bigger number of " << first << " and " << second << " is " << result << endl;
    cout << " -------------------------- " << endl;
    cout << "Type your favorite number:";
    cin >> first;
    cout << "Your favorite number is " << first << endl;
}