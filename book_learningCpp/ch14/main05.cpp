#include <iostream>
#include <iomanip>
#include <vector>
#include <ranges>
#include <algorithm>

int main()
{
    // std::vector<int> numbers = { 5, 3, 1, 4, 2 };
    // auto r = numbers | std::views::filter([](int n) { return n % 2 == 0; });
    // for (auto n : r)
    // {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    // NOTE that this from the book is incorrect:
    // auto r2 = numbers | std::ranges::remove_if([](int n) { return n % 2 == 0; });
    // for (auto n : r2)
    // {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;
    // The book incorrectly uses std::ranges::remove_if, which returns a range,
    // not a view. The correct view is std::views::filter.
    // see https://en.cppreference.com/w/cpp/algorithm/ranges/remove

    std::string v1{"No - Diagnostic - Required"};
    std::cout << std::quoted(v1) << std::endl;

    const auto ret = std::ranges::remove(v1, ' ');
    std::cout << std::quoted(v1) << std::endl;

    std::cout << "---------------------" << std::endl;

    // remove_if with custom unary predicate:
    auto rm = [](char c) { return !std::isupper(c); };
    std::string v2{"Substitution Failure Is Not An Error"};
    std::cout << std::quoted(v2) << " (v2, size: " << v2.size() << ")\n";
    const auto [first, last] = std::ranges::remove_if(v2, rm);
    std::cout << std::quoted(v2) << " (v2 after `remove_if`, size: " << v2.size() << ")\n";
    std::cout << ' ' << std::string(std::distance(v2.begin(), first), '^') << '\n';
    v2.erase(first, last);
    std::cout << std::quoted(v2) << " (v2 after `erase`, size: " << v2.size() << ")\n\n";

    std::cout << "---------------------" << std::endl;

    // creating a view into a container that is modified by `remove_if`:
    for (std::string s : {"Small Object Optimization", "Non-Type Template Parameter"})
        std::cout << std::quoted(s) << " => "
            << std::string_view{begin(s), std::ranges::remove_if(s, rm).begin()} << '\n';


    return 0;
}