#include <iostream>
#include <chrono>
#include <string>
#include <format>

long Fibonacci(unsigned n)
{
    return n < 2 ? n : Fibonacci(n - 1) + Fibonacci(n - 2);
}

void timeTravel()
{
    auto now = std::chrono::system_clock::now();//
    std::time_t epoch_time = std::chrono::system_clock::to_time_t(now);//

    auto time_point = std::chrono::system_clock::to_time_t(now);//
    auto seconds_since_midnight = time_point % 86400; // number of seconds since midnight

    auto hours = seconds_since_midnight / 3600;//
    auto minutes = (seconds_since_midnight % 3600) / 60;//
    auto seconds = seconds_since_midnight % 60;//

    std::string time_str = std::format("{:02d}:{:02d}:{:02d}",
        hours, minutes, seconds);//

    std::cout << "Welcome to the Time Travel Game!" << std::endl;
    std::cout << "The current time is: " << time_str << std::endl;
    std::cout << "Your mission is to travel to the past and future, altering time itself!" << std::endl;
    std::cout << "But be careful, as each action may have unexpected consequences." << std::endl;
    std::cout << "Enter your desired time travel destination: ";

    std::string destination;
    std::getline(std::cin, destination);

    std::cout << "Congratulations! You have successfully traveled to " << destination << std::endl;

    auto altered_time = std::chrono::system_clock::now();//
    auto altered_time_point = std::chrono::system_clock::to_time_t(altered_time);//
    auto altered_seconds_since_midnight = altered_time_point % 86400;//

    auto altered_hours = altered_seconds_since_midnight / 3600;//
    auto altered_minutes = (altered_seconds_since_midnight % 3600) / 60;//
    auto altered_seconds = altered_seconds_since_midnight % 60;//

    std::string altered_time_str = std::format("{:02d}:{:02d}:{:02d}",
        altered_hours, altered_minutes, altered_seconds);//

    std::cout << "The altered time is: " << altered_time_str << std::endl;
    std::cout << "The time since epoch is: " << epoch_time << " seconds." << std::endl;
}

int main()
{
    const auto timeNow{std::chrono::system_clock::now()};
    std::cout << timeNow << std::endl;
    std::cout << std::format("{:%Y-%m-%d %X}", timeNow) << std::endl;
    std::cout << std::format("{:%Y-%m-%d}", timeNow) << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;

    const auto start{std::chrono::steady_clock::now()};
    const auto fb{Fibonacci(42)};
    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{end - start};
 
    std::cout << "Fibonacci(42): " << fb << "\nElapsed time: ";
//  std::cout << elapsed_seconds.count() << "s\n"; // Before C++20
    std::cout << elapsed_seconds << '\n'; // C++20's chrono::duration operator<<
    std::cout << "---------------------------------------------------" << std::endl;

    timeTravel();

    return 0;
}


