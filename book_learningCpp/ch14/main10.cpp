#include <iostream>
#include <chrono>

int main()
{
    auto now = std::chrono::system_clock::now();

    auto current_zone = std::chrono::zoned_time(std::chrono::current_zone(), now);

    auto other_zone = std::chrono::zoned_time(std::chrono::locate_zone("Europe/London"), now);

    std::cout << "Current time zone: " << current_zone  << std::endl;
    std::cout << "London time zone: " << other_zone  << std::endl;

    return 0;
}