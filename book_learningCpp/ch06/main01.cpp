#include <iostream>
#include <vector>

using namespace std;

void show(const vector<unsigned int> &v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

void show2(const vector<unsigned int> &v)
{
    // v.begin() is a reference to the first element
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " "; // *i is the value of the element, i is the iterator, dereference it to get the value
    cout << endl;
}

int main()
{
    vector<unsigned int> scores(11, 0); // 11 buckets, all 0
    cout << "initial capacity: " << scores.capacity() << endl;
    for (int i = 0; i < 10; ++i)
    {
        scores.push_back(i);
        cout << "push_back added one; capacity: " << scores.capacity();
        cout << " size: " << scores.size() << endl;
    }
    show(scores);

    // insert and erase are expensive operations
    scores.insert(scores.begin() + 5, 100);
    cout << "*(scores.begin()) = " << *(scores.begin()) << endl; // 0

    for (int i = 0; i < scores.size(); ++i)
        cout << "&scores[" << i << "] = " << &scores[i] << endl;
    show(scores);
    scores.erase(scores.begin() + 5);
    show(scores);
    scores.insert(scores.end() - 3, 100);
    show(scores);
    scores.erase(scores.end() - 4);
    show(scores);
    scores.insert(scores.begin() + 5, 10, 100);
    show(scores);
    show2(scores);
    scores.erase(scores.begin() + 5, scores.begin() + 15);
    show(scores);
    cout << "scores.empty() = " << ((scores.empty()) ? "true" : "false") << endl;

    scores.resize(35);
    cout << "after resize scores.size() = " << scores.size() << endl;
    show(scores);
    scores.assign(10, 100);
    cout << "after assign scores.size() = " << scores.size() << endl;
    show(scores);

    cout << "-------------------" << endl;
    std::vector<unsigned int> v1;
    v1.reserve(40);
    cout << "after reserve(40), v1.capacity() = " << v1.capacity() << endl;
    v1.resize(35);
    cout << "after resize(35), v1.capacity() = " << v1.capacity() << endl;
    v1.shrink_to_fit(); // expensive operation
    cout << "after shrink_to_fit(), v1.capacity() = " << v1.capacity() << endl;


    return 0;
}