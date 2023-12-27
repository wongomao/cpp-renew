#include <iostream>
#include <array>

using namespace std;

// valid for c-style arrays
// void ProcessArray(int arr[], int size)
// {
//     cout << "Processing c-style Array: ";
//     for (int i = 0; i < size; ++i)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// valid for c-style arrays
void ProcessArray(const int *arr, size_t size)
{
    cout << "Processing c-style Array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// valid for std::array
void ProcessArray(array<int, 5>& arr)
{
    // using std::array
    cout << "Processing std::array Array: ";
    for (const auto& val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

// -------------------------------------------------------------------------
// using std::array - passing an array to a function by reference and value

// Template
template<typename T, size_t size>
struct ArrayWrapper
{
    T arr[size]; // c-style array of type T and size
};

// modifyArray is a template function that takes an ArrayWrapper by value
// and modifies the underlying (wrapped) array
template<typename T, size_t size>
void modifyArray(ArrayWrapper<T, size> arrayWrapper)
{
    // loop through each element of the array inside the wrapper and set it to 1
    for (auto& val : arrayWrapper.arr)
    {
        val = 1;
    }
 
    std::cout << "Inside the function, modified array: ";
    for (const auto& val : arrayWrapper.arr)
    {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
}



int main()
{
    int myCArr[]{ 1, 2, 3, 4, 5 }; // c-style array
    int size = sizeof(myCArr) / sizeof(myCArr[0]); // get size of array
    size_t size2 = size; // size_t is an unsigned integer type
    ProcessArray(myCArr, size);
    ProcessArray(myCArr, size2);

    array<int, 5> arr{ 1, 2, 3, 4, 5 }; // using std::array
    array<int, 5> copyOfArray = arr; // easily copy an array
    ProcessArray(copyOfArray);
    cout << "------------------------------------------------------------" << endl;

    // using templates above
    // initialize an ArrayWrapper with a C-style array
    ArrayWrapper<int, 5> arrayWrapper = { {1, 2, 3, 4, 5} };
 
    std::cout << "Original array: "; // before modification
    // loop through each element of the original array and print it
    for (const auto& val : arrayWrapper.arr)
    {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
 
    modifyArray(arrayWrapper); // pass the ArrayWrapper by value to the function
 
    std::cout << "Outside function, original array remains unchanged: ";
    // Loop through each element of the original array and print it
    for (const auto& val : arrayWrapper.arr)
    {
        std::cout << val << ' ';
    }
    std::cout << std::endl;


    return 0;
}