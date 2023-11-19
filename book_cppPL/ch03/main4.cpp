#include <iostream>
#include "includes/Vector.h"
using namespace std;

class Container {
public:
    virtual double& operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};

class Vector_Container : public Container {
    Vector v;
public:
    Vector_Container(int s) : v(s) {}
    ~Vector_Container() {}
    double& operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};

void use(Container& c) {
    const int sz = c.size();
    for (int i = 0; i != sz; ++i)
        cout << c[i] << '\n';
}

// the below function is not part of the book
// it is used to output the binary representation of a double
void double_output_as_binary(const double d) {
    unsigned char rawBytes[sizeof(double)];
    memcpy(rawBytes, &d, sizeof(double));

    // the C++ standard does not guarantee that char is 8 bits
    // but it is on most platforms
    unsigned char startMask = 1;
    while (0 != static_cast<unsigned char>(startMask<<1)) {
        startMask <<= 1;
    }
    bool hasLeadBit = true; // set this to true if you want to see the leading zeros

    size_t byteIndex;
    for (byteIndex=0; byteIndex<sizeof(double);++byteIndex) {
        unsigned char bitMask=startMask;
        while (0 != bitMask) {
            if (0!=(bitMask&rawBytes[byteIndex])) {
                cout << "1";
                hasLeadBit = true;
            } else if (hasLeadBit) {
                cout << "0";
            }
            bitMask >>= 1;
        }
    }
    if (!hasLeadBit) {
        cout << "0";
    }
    cout << endl;
}

int main() {
    int count = 10;
    Vector_Container vc(count);
    vc[0] = 1.0;
    // vc[1] = 2.2;
    // vc[2] = 3.3;
    use(vc);
    for (int i = 0; i != count; ++i) {
        double_output_as_binary(vc[i]);
    }
}

