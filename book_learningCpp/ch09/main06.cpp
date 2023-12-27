#include <iostream>
#include <span>

void print(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print(std::span<int> span)
{
    for (auto i : span)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // pointer arithmetic is discouraged - it is possible
    // to perform pointer arithmetic that goes beyond the bounds of the array
    print(arr, std::size(arr));
    int *p1 = &arr[0]; // point to the first element
    int *p2 = &arr[std::size(arr) - 1]; // point to the last element
    std::cout << "------------pointer arithmetic--------------" << std::endl;
    std::cout << "*p1 = " << *p1 << "; p1 = " << p1 << std::endl;
    std::cout << "*p2 = " << *p2 << "; p2 = " << p2 << std::endl;
    std::cout << "size of int = " << sizeof(int) << std::endl;
    std::cout << "p2 - p1 = " << p2 - p1 << std::endl;

    // std::span is a view of contiguous sequence of objects
    std::cout << "------------span arithmetic--------------" << std::endl;
    std::span<int> span{ arr, std::size(arr) };
    print(span);
    auto ptr_a = span.data() + 3;
    std::cout << "type of span.data() = " << typeid(span.data()).name() << std::endl;
    std::cout << "*ptr_a = " << *ptr_a << "; ptr_a = " << ptr_a << std::endl;
    auto ptr_b = span.data() + 7;
    std::cout << "*ptr_b = " << *ptr_b << "; ptr_b = " << ptr_b << std::endl;
    auto ptr_diff = ptr_b - ptr_a;
    std::cout << "ptr_b - ptr_a = " << ptr_diff << std::endl;
    ++(*span.data()); // increment the first element of the span
    std::cout << "After ++(*span.data()), *span.data() = " << *span.data() << std::endl;
    --(*span.data()); // decrement the first element of the span
    std::cout << "After --(*span.data()), *span.data() = " << *span.data() << std::endl;
    std::cout << "span.size() = " << span.size() << std::endl;
    std::cout << "span.size_bytes() = " << span.size_bytes() << std::endl;
    std::cout << "last element: *(span.data() + std::size(arr) - 1) = " << *(span.data() + std::size(arr) - 1) << std::endl;
    auto ptr_c = (span.data() + 8) - (span.data() + 3);
    std::cout << "(span.data() + 8) - (span.data() + 3) = " << ptr_c << std::endl;
    
    return 0;
}