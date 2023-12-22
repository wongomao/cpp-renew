#include <iostream>

int main()
{
    int myInt{ 0 };
    int *pMyInt{ &myInt };
    std::cout << "myInt = " << myInt << std::endl;
    std::cout << "pMyInt = " << pMyInt << std::endl;
    int *my_ptr = new int{ 55 };
    std::cout << "my_ptr = " << my_ptr << std::endl;
    std::cout << "*my_ptr = " << *my_ptr << std::endl;
    *my_ptr = 66;
    std::cout << "*my_ptr = " << *my_ptr << std::endl;
    delete my_ptr;
    my_ptr = nullptr;
    std::cout << "--------------------------" << std::endl;
    int *pInt{ nullptr }; // initially pointer to int points nowhere
    pInt = new int; // allocate memory for an int on heap, but unititialized
    std::cout << "non-initialized pInt" << std::endl;
    std::cout << "pInt = " << pInt << std::endl; // show address of allocated memory
    std::cout << "*pInt = " << *pInt << std::endl; // show value at allocated memory
    *pInt = 391; // assign value to allocated memory
    std::cout << "initialized *pInt = " << *pInt << std::endl;
    delete pInt; // free allocated memory
    pInt = nullptr; // reset pointer to nullptr
    std::cout << "--------------------------" << std::endl;

    int *pIntArray = new int[3]{ 55, 66, 77 };
    std::cout << "pIntArray = " << pIntArray << std::endl;
    std::cout << "*pIntArray = " << *pIntArray << std::endl;
    for (size_t i = 0; i < 3; i++)
    {
        std::cout << "pIntArray[" << i << "] = " << pIntArray[i] << std::endl;
        std::cout << "*(pIntArray + " << i << ") = " << *(pIntArray + i) << std::endl;
    }
    delete[] pIntArray;
    pIntArray = nullptr;
    
    return 0;
}