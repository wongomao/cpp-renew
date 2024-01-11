#include <concepts>
#include <iostream>

/* Four methods for using consepts and functions
    NOTE: ALL OF THESE USE 'requires' CLAUSE
    The book must be wrong, because all these are the same, and they all use 'requires' clause
    There is no 'concept' keyword here as mentioned in the book
    https://en.cppreference.com/w/cpp/keyword/concept
    https://en.cppreference.com/w/cpp/language/constraints
 */

template <typename T>
    requires std::integral<T>
void functionWithRequiresClause(T value)
{
    std::cout << "Method 1: Requires Clause - Integral Type: " << value << std::endl;
}


template <typename T>
    requires std::floating_point<T> && (sizeof(T) >= 4)
void functionWithTrailingRequiresClause(T value)
{
    std::cout << "Method 2: Trailing Requires Clause - Floating Point Type: " << value << std::endl;
}


template <typename T>
    requires std::integral<T>
void functionWithAbbreviatedTemplate(T value)
{
    std::cout << "Method 3: Abbreviated Function Templates - Integral Type: " << value << std::endl;
}


template <typename T>
    requires std::floating_point<T>
void functionWithConstrainedTemplateParameter(T value)
{
    std::cout << "Method 4: Constrained Template Parameter - Floating Point Type: " << value << std::endl;
}

// ===================================================================================================

// Declaration of the concept "Hashable", which is satisfied by any type 'T'
// such that for values 'a' of type 'T', the expression std::hash<T>{}(a)
// compiles and its result is convertible to std::size_t
template<typename T>
concept Hashable = requires(T a)
{
    { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};
 
struct meow {};
 
// Constrained C++20 function template:
template<Hashable T>
void f(T) {}
//
// Alternative ways to apply the same constraint:
// template<typename T>
//     requires Hashable<T>
// void f(T) {}
//
// template<typename T>
// void f(T) requires Hashable<T> {}
//
// void f(Hashable auto /*parameterName*/) {}
 
// ===================================================================================================


int main()
{
    int intValue = 42;
    float floatValue = 3.14f;

    functionWithRequiresClause(intValue);
    functionWithTrailingRequiresClause(floatValue);
    functionWithAbbreviatedTemplate(intValue);
    functionWithConstrainedTemplateParameter(floatValue);

    using std::operator""s;
    f("abc"s); // OK, std::string satisfies Hashable
    // f(meow{}); // Error: meow does not satisfy Hashable

    return 0;
} 