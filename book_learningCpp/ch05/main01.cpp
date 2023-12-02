#include <iostream>

int main()
{
    int score[5] = { 84, 92, 76, 81, 56 };
    score[3] = 87;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "score[" << i << "] = " << score[i] << std::endl;
    }
    char word[] = { 's', 'q', 'u', 'i', 'r', 'r', 'e', 'l', '\0' };
    std::cout << word << std::endl;
    int i{0};
    while (word[i] != '\0')
    {
        std::cout << word[i] << " ";
        i++;
    }
    std::cout << std::endl;

    std::cout << "-------------------------" << std::endl;

    int score2[5] = { 84, 92, 76, 81, 56 };
    int* ptr = score2;
    std::cout << "ptr = " << ptr << std::endl;
    std::cout << "*ptr = " << *ptr << std::endl;
    // adding 1 to ptr will add 4 to the address because the size of int is 4 bytes
    std::cout << "ptr + 1 = " << ptr + 1 << std::endl;
    std::cout << "*(ptr + 1) = " << *(ptr + 1) << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "score2[" << i << "] = " << *(ptr + i) << std::endl;
    }

    std::cout << "-------------------------" << std::endl;

    int arr[5] = { 1, 2, 3, 4, 5 };
    for (int i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}