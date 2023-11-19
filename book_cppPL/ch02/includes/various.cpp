#include <iostream>
using namespace std;

void action1() {
    double sizes[4] = { 7.332, 9.221, 5.091, 6.322 };
    cout << "sizes:\t";
    for ( auto size : sizes) {
        cout << size << '\t';
    }
    cout << endl;
    cout << "----------------" << endl;
}

bool accept3() {
    int tries = 1;
    while (tries < 4) {
        cout << "Do you want to proceed? (y or n): ";
        char answer = 0;
        cin >> answer;
        cout << endl;

        switch (answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "Sorry, I don't understand that." << endl;
            ++tries;
        }
    }
    cout << "I'll take that for a no." << endl;
    
    return false;
}

void examineReference() {
    cout << "setting x to 0" << endl;
    int x = 0;
    int& r = x;
    int* p = &x;
    cout << "x = " << x << endl;
    cout << "r = " << r << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "&r = " << &r << endl;
    cout << "&x = " << &x << endl;
    cout << "&p = " << &p << endl;
    cout << "----------------" << endl;
    cout << "setting r to 5" << endl;
    r = 5;
    cout << "x = " << x << endl;
    cout << "r = " << r << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "&r = " << &r << endl;
    cout << "&x = " << &x << endl;
    cout << "&p = " << &p << endl;
    cout << "----------------" << endl;
    cout << "setting *p to 6" << endl;
    *p = 6;
    cout << "x = " << x << endl;
    cout << "r = " << r << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "&r = " << &r << endl;
    cout << "&x = " << &x << endl;
    cout << "&p = " << &p << endl;
    cout << "----------------" << endl;
    cout << "setting p to point to y" << endl;
    int y = 0;
    p = &y;
    cout << "x = " << x << endl;
    cout << "r = " << r << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "&r = " << &r << endl;
    cout << "&x = " << &x << endl;
    cout << "&p = " << &p << endl;
    cout << "----------------" << endl;
    cout << "setting r to 7" << endl;
    r = 7;
    cout << "x = " << x << endl;
    cout << "r = " << r << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "&r = " << &r << endl;
    cout << "&x = " << &x << endl;
    cout << "&p = " << &p << endl;
}