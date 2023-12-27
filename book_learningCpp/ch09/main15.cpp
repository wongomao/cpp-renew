#include <iostream>
#include <memory>
 
struct Object
{
    int value;
};
 
int main()
{
    // dynamically allocate an object of type Object and assign its address to a unique_ptr
    std::shared_ptr<Object> sharedPtr = std::make_shared<Object>();
    sharedPtr->value = 42;
 
    std::weak_ptr<Object> weakPtr = sharedPtr;
    // Use the lock() member function of the weak_pter to obtain a shared_ptr that 
    // shares ownership of the object.
    if (auto lockedPtr = weakPtr.lock())
    {
        std::cout << "Value: " << lockedPtr->value << std::endl;
    }
    else
    {
        std::cout << "Object is no longer valid." << std::endl;
    }
 
    // the lockedPtr does not prevent the object from being deleted - it is still a weak pointer
    // just allowing access to the object
    sharedPtr.reset(); // release the shared pointer - makes the object invalid
 
    // Again attempt to access the object using the weak pointer. The object is no longer
    // valid so the weak pointer returns an empty shared pointer (nullptr)
    if (auto lockedPtr = weakPtr.lock())
    {
        std::cout << "Value: " << lockedPtr->value << std::endl;
    }
    else
    {
        std::cout << "Object is no longer valid." << std::endl;
    }
 
    return 0;
}