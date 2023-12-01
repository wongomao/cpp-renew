#include <iostream>
#include <fstream>

bool is_prime(unsigned int number)
{
    if (number == 2)
        return true;
    else if (number % 2 == 0)
        return false;
    else
    {
        for (unsigned int i = 3; i < number; i += 2)
        {
            if (number % i == 0)
                return false;
        }
        return true;
    }
}

int main()
{
    unsigned int bottom_range{ 0 };
    unsigned int top_range{ 0 };
    std::cout << "Please enter a bottom range: ";
    std::cin >> bottom_range;
    std::cout << "Please enter a top range: ";
    std::cin >> top_range;

    std::string filename{ "prime_numbers.txt" };
    std::ofstream prime_file{ filename };
    if (!prime_file)
    {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    for (unsigned int i = bottom_range; i < top_range; i++)
    {
        if (is_prime(i))
        {
            prime_file << i << " ";
        }
    }
    prime_file << std::endl;
    prime_file.close();
}