#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<int, char> map1;
    map1[1] = 'x';
    map1[2] = 'y';

    std::cout << "The bucket number of the first specified key is: " << map1.bucket(1) << std::endl;
    std::cout << "The bucket number of the second specified key is: " << map1.bucket(2) << std::endl;
}