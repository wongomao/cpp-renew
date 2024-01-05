#include <iostream>
#include <set>

void displaySet(const std::string &name, const std::set<int> &set)
{
    std::cout << name << ": ";
    for (const auto &element : set)
        std::cout << element << " ";
    std::cout << std::endl;
}

int main()
{
    std::set<int> num{ 10, 20, 30, 40, 50 };
    displaySet("num", num);

    num.erase(30);
    std::cout << "num.erase(30)" << std::endl;
    displaySet("num", num);

    num.insert(25);
    std::cout << "num.insert(25)" << std::endl;
    displaySet("num", num);

    num.insert(25);
    std::cout << "num.insert(25)" << std::endl;
    displaySet("num", num);

    num.erase(num.begin());
    std::cout << "num.erase(num.begin())" << std::endl;
    displaySet("num", num);

    num.erase(num.begin(), num.end());
    std::cout << "num.erase(num.begin(), num.end())" << std::endl;
    displaySet("num", num);
    std::cout << "------------------------------------------------" << std::endl;

    // note we ordered the set with std::greater<int>
    std::set<int, std::greater<int>> s;
    s.insert(-3);
    s.insert(3);
    s.insert(13);
    s.insert(33);
    s.insert(-33);
    s.insert(-33);

    auto last_elem = *s.rbegin(); // reverse begin
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        std::cout << *it << " ";
        if (*it == last_elem)
            std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}