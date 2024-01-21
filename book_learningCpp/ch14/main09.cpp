#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>

int main()
{
    auto duration1 = std::chrono::seconds(5);
    auto duration2 = std::chrono::seconds(10);

    auto duration_sum = duration1 + duration2;

    bool is_equal = duration1 == duration2;
    std::cout << "Duration 1: " << duration1.count() << " seconds" << std::endl;
    std::cout << "Duration 2: " << duration2.count() << " seconds" << std::endl;
    std::cout << "Duration sum: " << duration_sum.count() << " seconds" << std::endl;
    std::cout << "Duration 1 is equal to duration 2: " << std::boolalpha << is_equal << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;


    auto now = std::chrono::system_clock::now();
    auto future_time = now + std::chrono::hours(6); // six hours from now
 
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now); // convert to time_t
    std::time_t future_time_t = std::chrono::system_clock::to_time_t(future_time);
 
    std::string now_str = std::ctime(&now_time_t); // convert time_t to string
    std::string future_str = std::ctime(&future_time_t);
 
    now_str.erase(now_str.find('\n')); // remove newline character
    future_str.erase(future_str.find('\n'));
 
    std::cout << "Current time: " << now_str << std::endl;
    std::cout << "Time in 6 hours: " << future_str << std::endl;

    return 0;
}