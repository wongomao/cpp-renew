#include <iostream>
#include <list>
#include <algorithm>

void printList(const std::string listname, const std::list<int> &list)
{
    std::cout << listname << ": ";
    for (const auto &element : list)
        std::cout << element << " ";
    std::cout << std::endl;
}

/*
'list' is a doubly-linked list, not contiguous in memory
Thus, accessing elements by index is not efficient, it is best
to use iterators
Lists are good for inserting and removing elements in the middle
Vectors are good for accessing elements by index and appending
*/

int main()
{
    std::list<int> list1;
    std::list<int> list2(5); // 5 elements with default value
    std::list<int> list3(5, 2); // 5 elements with value 2
    std::list<int> list4(list3); // copy of list3
    std::list<int> list5(list3.begin(), list3.end()); // copy of list3
    std::list<int> list7({1, 2, 3, 4, 5}); // initializer list

    printList("list1", list1);
    printList("list2", list2);
    printList("list3", list3);
    printList("list4", list4);
    printList("list5", list5);
    printList("list7", list7);

    std::cout << "---------------------------------------------" << std::endl;

    std::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_front(5);
    myList.push_front(3);
    printList("myList", myList);
    
    // must include <algorithm> to use std::find
    auto it = std::find(myList.begin(), myList.end(), 5);
    if (it != myList.end())
    {
        myList.insert(++it, 7); // insert 7 after 5; ++it is the position after 5
    }
    printList("myList", myList);
    myList.reverse();
    printList("myList reversed", myList);

    return 0;
}