#include <iostream>
#include <memory> // for std::unique_ptr

// A simple class with a constuctor and some methods.
class Simple
{
public:
    Simple()
    {
        std::cout << "Simple constructor called!" << std::endl;
    }

    ~Simple()
    {
        std::cout << std::endl << "Simple destructor called!" << std::endl;
    }

    void PrintSomething()
    {
        std::cout << "Something" << std::endl;
    }
};

// Declares a function named processObject that takes a reference to a unique_ptr<int>
// as a parameter.
void processObject(std::unique_ptr<int>& ptr)
{
    std::cout << "Processing object: " << *ptr << std::endl;
    *ptr += 10;
}

int main()
{
    // ---------------------------------------------------------------------
    std::cout << "---------------------------------------" << std::endl;
    // Create a unique_ptr to a Simple object and assign it to mySimple.
    //std::unique_ptr<Simple> mySimple(new Simple());
    std::unique_ptr<Simple> mySimple = std::make_unique<Simple>();
    // Call a method on the object pointed to by mySimple.
    mySimple->PrintSomething();


    // ---------------------------------------------------------------------
    std::cout << "---------------------------------------" << std::endl;
    // we can use std::unique_ptr on other types
    std::unique_ptr<int> p1(new int(5));
    std::cout << "*p1: " << *p1 << std::endl;

    // ---------------------------------------------------------------------
    std::cout << "---------------------------------------" << std::endl;
    std::unique_ptr<int> ptr1 = std::make_unique<int>(23);
    std::cout << "Initial value for ptr1: " << *ptr1 << std::endl;
    processObject(ptr1); // ptr1 is passed by reference
    std::cout << "Processed value for ptr1: " << *ptr1 << std::endl;
    // std::move transfers ownership of the memory pointed to by ptr1 to ptr2
    std::unique_ptr<int> ptr2 = std::move(ptr1); // ptr2 is now the unique owner of the memory pointed to by ptr1
    if (!ptr1)
    {
        std::cout << "Original unique_ptr ptr1 is empty" << std::endl;
    }
    if (ptr2)
    {
        std::cout << "Transferred unique_ptr ptr2 value: " << *ptr2 << std::endl;
    }
    ptr2.reset(); // ptr2 is now empty
    if (!ptr2)
    {
        std::cout << "Transferred unique_ptr ptr2 is empty" << std::endl;
    }

    // ---------------------------------------------------------------------
    std::cout << "---------------------------------------" << std::endl;
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(37);
    std::shared_ptr<int> sharedPtr2 = sharedPtr1; // sharedPtr1 and sharedPtr2 now both own the memory pointed to by the shared pointer
    std::cout << "sharedPtr1: " << *sharedPtr1 << std::endl;
    std::cout << "sharedPtr2: " << *sharedPtr2 << std::endl;

    // unique_ptr will automatically deallocate the object when it goes out of scope.
    // just before the end of main, unique_ptr will automatically deallocate the objects

    // ---------------------------------------------------------------------
    std::cout << "---------------------------------------" << std::endl;
    std::shared_ptr<int> ptr4(new int(65));
    std::weak_ptr<int> weakPtr = ptr4; // ptr4 still owns the memory pointed to by ptr4, but now we have a weak pointer to it as well
    return 0;
}