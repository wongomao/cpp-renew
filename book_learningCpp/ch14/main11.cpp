#include <chrono>
#include <iostream>

int main()
{
    auto start = std::chrono::steady_clock::now();
    auto timeout = std::chrono::seconds(2);

    std::cout << "Waiting for 2 seconds..." << std::endl;
    while (std::chrono::steady_clock::now() - start < timeout)
    {
        // do nothing
    }
    std::cout << "Timeout reached!" << std::endl;

    std::cout << "--------------------------------------------" << std::endl;
    auto countdown_duration = std::chrono::seconds(10);
    for (int i = countdown_duration.count(); i > 0; --i)
    {
        std::cout << i << " seconds remaining..." << std::endl;
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        auto start_time = std::chrono::steady_clock::now();
        while (std::chrono::steady_clock::now() - start_time < std::chrono::seconds(1))
        {
            // wait for 1 second
        }
    }
    std::cout << "Lift off!" << std::endl;

    return 0;
}