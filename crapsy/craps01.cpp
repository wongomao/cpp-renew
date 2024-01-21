#include <iostream>
#include <vector>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);

    unsigned int rollCount = 10000;
    std::vector<int> rollResults(6, 0);
    for (unsigned int i = 0; i < rollCount; ++i)
    {
        ++rollResults[dis(gen) - 1];
    }

    // display results
    for (auto result : rollResults)
    {
        std::cout << result << ' ';
    }
    std::cout << std::endl;

    // display results as percentages
    for (auto result : rollResults)
    {
        std::cout << static_cast<double>(result) / rollCount * 100 << "% ";
    }
    return 0;
}