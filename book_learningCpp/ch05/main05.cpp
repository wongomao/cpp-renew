#include <iostream>
#include <array>

void showArray(const std::array<int, 5>& myArray)
{
    // for (int i = 0; i < myArray.size(); ++i)
    // {
    //     std::cout << myArray[i] << " ";
    // }
    std::cout << "{ ";
    for (auto i : myArray)
    {
        std::cout << i << " ";
    }
    std::cout << " }" << std::endl;
}

int main()
{
    std::array<int, 5> myArray{ 7, 3, 1, 9, 5 };
    std::array<int, 5> myArray2;
    myArray2 = { 1, 2, 3, 4, 5 };

    for (int i = 0; i < myArray.size(); ++i)
    {
        std::cout << '(' << myArray[i] << ",";
        std::cout << myArray2[i] << ") ";
    }
    std::cout << std::endl << "----------------------------------" << std::endl;

    std::array<char, 10> a;
    a[0] = 's';
    a[1] = 'q';
    a[2] = 'u';
    a[3] = 'i';
    a[4] = 'r';
    a[5] = 'r';
    a[6] = 'e';
    a[7] = 'l';
    a[8] = 's';
    //a[9] = '.';

    for (char c : a) // range-based for loop
    {
        std::cout << c << " ";
    }
    std::cout << "sizeof(a)=" << sizeof(a) << "; size(a)=" << a.size() << std::endl;
    std::cout << std::endl << "----------------------------------" << std::endl;

    std::array<int, 5> myArray3{ 7, 3, 1, 9, 5 };
    // use size_t for array indexing, useful on all platforms and containers
    for (std::size_t i = 0; i < myArray3.size(); ++i)
    {
        std::cout << i << " " << myArray3[i] << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    // use auto for array indexing, useful on all platforms and containers
    for (auto i = 0; i < myArray3.size(); ++i)
    {
        std::cout << i << " " << myArray3[i] << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    std::array<int, 5> c1{ 1, 2, 3, 4, 5};
    std::array<int, 5> c2{ 10, 20, 30, 40, 50};
    std::cout << "before swap: c1 = ";
    showArray(c1);
    std::cout << "before swap: c2 = ";
    showArray(c2);
    c1.swap(c2);
    std::cout << "after swap: c1 = ";
    showArray(c1);
    std::cout << "after swap: c2 = ";
    showArray(c2);
    std::cout << "-------------------------" << std::endl;
    std::array<std::array<double, 5>, 5> gr1 =
    {{
        {1.0, 2.0, 3.0, 4.0, 5.0},
        {6.0, 7.0, 8.0, 9.0, 10.0},
        {11.0, 12.0, 13.0, 14.0, 15.0},
        {16.0, 17.0, 18.0, 19.0, 20.0},
        {-1.0, -1.0, -1.0, -1.0, -1.0}
    }};
    for (auto& row : gr1)
    {
        for (auto& col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}