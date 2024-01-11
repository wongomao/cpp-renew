#include <iostream> 
#include <type_traits> 

template<typename T>
class MyClass 
{ 
    public:

    void f(T const& x)
    { 
        std::cout << "Called f(T const& x) with value: " << x << std::endl; 
    } 

    // perfect forwarding U&&
    /*Perfect forwarding is typically achieved using rvalue references && and 
    template metaprogramming. It allows us to write a single function 
    template that can accept any kind of argument, and pass it on to another 
    function without unnecessary copying or losing the original value category. 
    To achieve perfect forwarding, we typically use function templates.*/
    template<typename U = T, typename = std::enable_if_t<!std::is_reference_v<U>>> 
    void f(U&& x)  
    { 
        std::cout << "Called f(U&& x) with value: " << x << std::endl; 
    } 
};


// rvalue reference
// see: https://learn.microsoft.com/en-us/cpp/cpp/rvalue-reference-declarator-amp-amp?view=msvc-170
void testa(int &&a) // 'a' is an rvalue reference
{
    std::cout << "testa(int &&a) " << a << std::endl; 
}

int main() 
{
    using MyClassOnRef = MyClass<int&>;
    int i = 0;
    MyClassOnRef x;
    x.f(i);

    int rr = 17;
    testa(19);

    return 0; 
}
/*output:
Called f(T const& x) with value: 0

see Move Constructors and Move Assignment Operators here:
https://learn.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=msvc-170
*/