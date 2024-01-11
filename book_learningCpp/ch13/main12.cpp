#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <functional>

#define SALSA "[S]"
#define LAMBADA "[L]"

int main()
{
    std::cout << "Dancing the Lambda" << std::endl;
    std::vector<std::string> dancers = 
    {
        "James", "Mary", "Will", "Bob",
        "Audrey", "Grace", "Marilyn", "Liz"
    };
    auto shuffle_dancers = [&]() // lambda; [&] is capture list (by reference)
    {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::shuffle(dancers.begin(), dancers.end(), generator);
        std::cout << "Shuffling the dancers..." << std::endl;
    };
    auto print_dancers = [&]() // lambda; [&] is capture list (by reference)
    {
        for (const auto& dancer : dancers)
        {
            std::cout << dancer << " ";
        }
        std::cout << std::endl;
    };
    auto prefers_salsa = [](const std::string& dancer) -> bool
    {
        return dancer.substr(0, 3) == SALSA; // dancer name starts with "[S]"
    };
    auto prefers_lambada = [](const std::string& dancer) -> bool
    {
        return dancer.substr(0, 3) == LAMBADA; // dancer name starts with "[L]"
    };

    shuffle_dancers();
    print_dancers();
    // assign dancers to salsa and lambada
    for (auto& dancer : dancers)
    {
        // insert space at the beginning of the string
        dancer.insert(0, " ");
        // insert salsa or lambada at the beginning of the string
        dancer.insert(0, (dancer.length() % 2 == 0) ? SALSA : LAMBADA);
    }

    std::cout << std::endl << "Let's partition our dancers into groups based on their dance preferences" << std::endl;
    auto lambada_end = std::partition(dancers.begin(), dancers.end(), prefers_lambada);
    for (auto& dancer : dancers)
    {
        // remove the space and the salsa/lambada tag from the beginning of the string
        dancer.erase(0, 4);
    }

    std::cout << "Lambada dancers: ";
    for (auto it = dancers.begin(); it != lambada_end; ++it)
    {
        std::cout << *it << (it != lambada_end - 2 ? " " : " and ");
    }
    std::cout << std::endl;
    std::cout << "Salsa dancers: ";
    for (auto it = lambada_end; it != dancers.end(); ++it)
    {
        std::cout << *it << (it != dancers.end() - 2 ? " " : " and ");
    }
    std::cout << std::endl;

    return 0;
}