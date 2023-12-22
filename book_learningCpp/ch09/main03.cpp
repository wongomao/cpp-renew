#include <iostream>

/*
Passing arrays to functions
"array-to-pointer decay" - when an array is passed to a function, what
is actually passed is a pointer to the first element of the array.
I.e. a compile-time transformation of the array's name into a pointer.
This should be avoided because we lose the array's size.

Accessing array elements outside of the array's bounds is undefined
behavior. "bounds-unsafe"

Even keeping track of the size of the array is not enough to prevent
bounds-unsafe behavior. The size of the array is not part of the type
of the array, so the compiler doesn't know the size of the array.

The modern way is to use std::span (C++20)
*/
int sum_array(int *pArray, int size)
{
    int sum{ 0 };
    for (size_t i = 0; i < size; i++)
    {
        sum += pArray[i];
    }
    return sum;
}

int main()
{
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    int *pIntArray = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        pIntArray[i] = 2 * (i + 1); // notice the use of [] operator instead of *
    }
    std::cout << "array = [";
    int sum{ 0 };
    for (size_t i = 0; i < size; i++)
    {
        std::cout << " " << pIntArray[i];
        sum += pIntArray[i];
    }
    std::cout << " ]" << std::endl;
    std::cout << "sum = " << sum << std::endl;

    // using function
    std::cout << "sum_array(pIntArray, size) = " << sum_array(pIntArray, size) << std::endl;
    delete[] pIntArray;

    return 0;
}