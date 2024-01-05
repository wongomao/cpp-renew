#include <iostream>
#include <forward_list>

void printList(const std::string listname, const std::forward_list<int> &list)
{
    std::cout << listname << ": ";
    for (const auto &element : list)
        std::cout << element << " ";
    std::cout << std::endl;
}

int main()
{
    std::forward_list<int> list1;
    std::forward_list<int> list2;
    std::forward_list<int> list3;

    list1.assign({ 5, 6, 7 });
    list2.assign({ 10, 20, 30 });
    list3.assign(list2.begin(), list2.end());

    printList("list1", list1);
    printList("list2", list2);
    printList("list3", list3);
}