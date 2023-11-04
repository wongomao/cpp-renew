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