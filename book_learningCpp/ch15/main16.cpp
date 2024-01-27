#include <iostream>
#include <future> // async(), future, promise
#include <chrono>
#include <random>
#include <limits>

int main()
{
    char input = ' ';

    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count()); // current time as seed
    std::uniform_int_distribution<> dist(0, 2); // random number between 0 and 2 inclusive

    std::string answers[] = { "It is certain",
        "Without a doubt",
        "You may rely on it"
        };
    while (input != 'q' && input != 'Q')
    {
        std::cout << "Asking the Magin 8-Ball for an answer..." << std::endl;
        // create a new thread that selects a random answer from the array;
        // notice the [&](){} syntax. This is a lambda function that captures
        // all variables in the current scope by reference.
        std::future<std::string> fut = std::async([&]()
            {
                int idx = dist(gen);
                return answers[idx];
            });
        
        std::cout << "The Magic 8-Ball says: " << fut.get() << std::endl;
        std::cout << "Press 'q' to quit or any other key to ask another question." << std::endl;

        char cb[20]{};
        std::cin.readsome(cb, sizeof(cb));
        input = std::cin.get();
    }

    return 0;
}