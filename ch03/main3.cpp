#include <iostream>
#include "includes/Container.h"
#include "includes/Vector_Container.h"
using namespace std;

// Using Container, as purely abstract class
void use(Container& c) {
    const int sz = c.size();
    for (int i = 0; i != sz; ++i)
        cout << c[i] << '\n';
}

int main() {
    Vector_Container vc(3);
    // ... fill vc ...
    vc[0] = 1.1;
    vc[1] = 2.2;
    vc[2] = 3.3;
    use(vc);
}

// This does not compile because the wrong things are placed in headers.