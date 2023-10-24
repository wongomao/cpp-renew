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
}