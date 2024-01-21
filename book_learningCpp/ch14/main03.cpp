#include <iostream>
#include <vector>
#include <ranges>
#include <string>
#include <iterator>

template <typename Range>
class ReverseView
{
public:
    explicit ReverseView(Range& range) : range{range} {}
    auto begin()
    {
        return std::rbegin(range);
    }
    auto end()
    {
        return std::rend(range);
    }
private:
    Range& range;
};

template <typename Range>
ReverseView(Range&) -> ReverseView<Range>;

int main()
{
    std::string s = "Learning C++ by Michael Haephrati and Ruth Haephrati";
    std::cout << s << std::endl;

    // split the string into words
    auto r1 = s | std::views::split(' ') |
        // reverse each word; auto&& is a forwarding reference
        // A forwarding reference is a special kind of reference
        // that preserves the value category of a function argument,
        // making it possible to forward it by means of std::forward.
        // auto&& is a forwarding reference, and it can be used to
        // declare a function template that accepts any kind of argument.
        // auto&& deduces the type of the variable from its initializer
        // using the same rules as template type deduction.
        std::views::transform([](auto&& subrange)
            {
                return std::ranges::reverse_view(subrange);
            });
    
    for (const auto& word : r1)
    {
        for (const auto& letter : word)
        {
            std::cout << letter;
        }
        std::cout << " ";
    }
    std::cout << std::endl;

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    auto r2 = ReverseView(numbers);

    for (const auto& n : r2)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}