#include <iostream>
using namespace std;

// note : this is just an early implementation of Vector class - it is not complete
// We need release memory and add error handling, etc.
// chapter 3 will show how to do this properly
class Vector {
public:
    Vector(int s) :elem{ new double[s] }, sz{ s } {}
    double& operator[](int i) { return elem[i]; }
    int size() { return sz; }
    double sum() {
        double sum = 0;
        for (int i = 0; i < sz; ++i)
            sum += elem[i];
        return sum;
    }
private:
    double* elem;
    int sz;
};

// enums
enum class Color { red, blue, green };
enum payment_type { cash, credit, debit };

int main()
{
    Vector v(3);
    cout << "v.size() = " << v.size() << endl;
    cout << "enter " << v.size() << " numbers: " << endl;
    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
    cout << v[0];
    for (int i = 1; i < v.size(); ++i) {
        cout << " + " << v[i];
    }
    cout << " = " << v.sum() << endl;
    cout << "-------------------------" << endl;

    Color col = Color::red;
    cout << "col = " << static_cast<int>(col) << endl;
    int x = payment_type::debit;
    cout << "the payment type is " << x << endl;

    return 0;
}


