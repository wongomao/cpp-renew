#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5, 6 };

    int j;
    std::cout << "Accesing elements Without iterators ";
    for (j = 0; j < v.size(); ++j)
    {
        std::cout << v[j] << " ";
    }
    std::cout << std::endl;

    std::cout << "Accesing elements with iterators ";
    std::vector<int>::iterator i;
    for (i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << " "; // dereference the iterator to get the value
    }
    std::cout << std::endl;

    return 0;
}