#include <iostream>
#include <deque>

void showDeque(const std::string &name, const std::deque<int> &deq)
{
    std::cout << name << ": ";
    for (const auto &element : deq)
        std::cout << element << " ";
    std::cout << std::endl;
}


int main()
{
    std::deque<int> num{ 10, 20, 30, 40, 50 };
    showDeque("num", num);

    num.pop_back();
    std::cout << "num.pop_back()" << std::endl;
    showDeque("num", num);

    num.pop_front();
    std::cout << "num.pop_front()" << std::endl;
    showDeque("num", num);
}