#include <iostream> 
#include <type_traits> 

// type_traits helps us to check the type of a template parameter
template<typename T>
typename std::enable_if<std::is_integral<T>::value && !std::is_reference<T>::value>::type
process(T value)
{ 
    std::cout << "Processing an integral value: " << value << std::endl; 
} 

template<typename T>
typename std::enable_if<!std::is_integral<T>::value && !std::is_reference<T>::value>::type
process(T value)
{ 
    std::cout << "Processing a non-integral value: " << value << std::endl; 
} 

template<typename T>
typename std::enable_if<std::is_integral<T>::value&& std::is_reference<T>::value>::type
process(T value)
{ 
    std::cout << "Processing an integral reference: " << value << std::endl; 
} 

template<typename T>
typename std::enable_if<!std::is_integral<T>::value&& std::is_reference<T>::value>::type
process(T value)
{ 
    std::cout << "Processing a non-integral reference: " << value << std::endl; 
} 

int main() 
{ 
    int x = 42; 
    const double& y = 3.14; 
 
    process(x);
    process(y);
    process<int>(x);
    process<const double&>(y);
 
    return 0; 
}
/*output:
Processing an integral value: 42
Processing a non-integral value: 3.14
Processing an integral value: 42
Processing a non-integral reference: 3.14
*/