#include <iostream>
#include <span>

void arrayDecay(int *arr)
{
    std::cout << "Modified size of array is by passing by value: ";
    std::cout << sizeof(arr) << std::endl;
}
 
void pointerDecay(int(*ptr)[7])
{
    std::cout << "Modified size of array by passing by pointer: ";
    std::cout << sizeof(ptr) << std::endl;
}

/*
Using std::span (C++20) we no longer need to explicitly pass the size of
the array to the function. std::span is a view of a contiguous sequence
of objects, which can be an array or a container. It is a non-owning
view, so it doesn't manage the lifetime of the array. It is a lightweight
object, so it can be passed by value.
It carries both the pointer to the array and its size.
When using std::span we must include the <span> header.
*/

void my_function(std::span<int> my_span)
{
    std::cout << "my_span.size() = " << my_span.size() << std::endl;
    for (const int &value : my_span)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
 
int main()
{
    int numbers[7] = { 8, 7, 3, 1, 10, 16, 2 };
 
    std::cout << "Actual size of array is: ";
    std::cout << sizeof(numbers) << std::endl;
 
    arrayDecay(numbers);
 
    pointerDecay(&numbers);
    std::cout << "--------------------------" << std::endl;

    // using std::span
    my_function(numbers);
 
    return 0;
}