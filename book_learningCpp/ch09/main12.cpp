#include <iostream>
#include <optional> // in order to use std::optional
#include <functional> // in order to use std::reference_wrapper

// addValueByReference takes a reference to an integer and an increment value.
// It modifies the referenced integer and returns it wrapped in
// an std::optional<std::reference_wrapper<int>>.
std::optional<std::reference_wrapper<int>> addValueByReference(int &value, int increment)
{
    value += increment;
    return std::optional<std::reference_wrapper<int>>{value};
}

// addValueByPointer takes a pointer to an integer and an increment value.
// It modifies the pointed integer and returns the pointer.
int *addValueByPointer(int *value, int increment)
{
    *value += increment;
    return value;
}

// addValueWithoutReturn takes a pointer to an integer and an increment value.
// It modifies the pointed integer and returns nothing.
void addValueWithoutReturn(int *value, int increment)
{
    *value += increment;
}

int main()
{
    int varb = 42;

    // We call addValueByReference with varb and 10, storing the result in refResult.
    // If the result has a value, we print the modified value using refResult.value().
    std::optional<std::reference_wrapper<int>> refResult = addValueByReference(varb, 10);
    if (refResult)
    {
        std::cout << "Value after modifying through reference: " << refResult.value() << std::endl;
    }
    else
    {
        std::cout << "Reference result is empty." << std::endl;
    }
    // Note that returning a reference allows us to directly modify the original variable, while
    // returning a pointer requires dereferencing the pointer to modify the original variable.

    // We call addValueByPointer with &varb and 10, storing the result in ptrResult.
    // If the result is not a nullptr, we print the modified value using *ptrResult.
    int* ptrResult = addValueByPointer(&varb, 10);
    if (ptrResult)
    {
        std::cout << "Value after modifying through pointer: " << *ptrResult << std::endl;
    }
    else
    {
        std::cout << "Pointer result is empty." << std::endl;
    }

    // We call addValueWithoutReturn with &varb and 10, printing the modified value.
    addValueWithoutReturn(&varb, 10);
    std::cout << "Value after modifying without return: " << varb << std::endl;

    return 0;
}