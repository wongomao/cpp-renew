#include <iostream>
#include <string>

int main()
{
    // naked pointers
    int *pNum{ nullptr };
    int *pScore{}; // equivalent to int *pScore{ nullptr };
    wchar_t *pLetter{ nullptr };
    std::wstring *pName{ nullptr };
    double *pTemp{ nullptr };

    int num{};
    std::cout << "The address of num is: " << &num << std::endl;
    std::cout << "naked pointer, pNum = " << pNum << std::endl;
    std::cout << "naked pointer pScore initialized with *pScore{}, pScore = " << pScore << std::endl;
    // std::cout << "*pScore = " << *pScore << std::endl; // dereferencing a pointer that is not initialized will cause a runtime error
    std::cout << "&pNum = " << &pNum << std::endl;
    std::cout << "--------------------------" << std::endl;

    int anotherNum{ 55 };
    int *pAnotherNum{ &anotherNum }; // Initialize our pointer using the address-of operator (&)
    std::cout << "The value of anotherNum is: " << *pAnotherNum << std::endl;
    std::cout << "The pointer pAnotherNum points to the address: " << &anotherNum << std::endl;
    std::cout << "pAnotherNum = " << pAnotherNum << std::endl;

    // size of pointer is 8 bytes for 64-bit systems (8 * 8 = 64 bits)
    // size of pointer is 4 bytes for 32-bit systems (4 * 8 = 32 bits)
    std::cout << "--------------------------" << std::endl;

    int x5 = 10;
    int *i{ nullptr };
    std::cout << "The value of x is " << x5 << std::endl;
    i = &x5;
    int *j{ &x5};
    std::cout << "The value of *i is " << *i << std::endl;
    std::cout << "The value of *j is " << *j << std::endl;
    std::cout << "i = " << i << "; j = " << j << "; i == j : " << ((i == j) ? "true" : "false") << std::endl;
    std::cout << "--------------------------" << std::endl;

    const wchar_t mytext[] = L"this is my test text";
    const wchar_t *pText{ &mytext[0] };
    std::wcout << "mytext = " << mytext << "; pText = " << pText << std::endl;
    for (size_t i = 0; i < wcslen(mytext); i++)
    {
        const wchar_t *address = &(mytext[i]);
        std::wcout << "Character: " << mytext[i] << " Address: " << address << std::endl;
    }

    return 0;
}