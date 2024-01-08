#include <iostream>

// this does not link!!!

template <typename T, std::size_t Size>
class FixedSizeArray
{
private:
    T elements[Size];

public:
    FixedSizeArray()
    {
        for (std::size_t i = 0; i < Size; ++i)
        {
            elements[i] = T();
        }
    }

    T& operator[](const std::size_t index)
    {
        return elements[index];
    }

    std::size_t getSize() const
    {
        return Size;
    }
};

int main()
{
    FixedSizeArray<int, 5> numbersArray;
    for (std::size_t i = 0; i < numbersArray.getSize(); ++i)
    {
        numbersArray[i] = i + 1;
        std::cout << numbersArray[i] << " ";
    }
    std::cout << std::endl;

    FixedSizeArray<char, 3> charactersArray;
    for (std::size_t i = 0; i < charactersArray.getSize(); ++i)
    {
        charactersArray[i] = 'a' + i;
        std::cout << charactersArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}