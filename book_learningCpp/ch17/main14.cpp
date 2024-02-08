#include <chrono>
#include <fstream>
#include <iostream>
#include <format>

/*
This ia a function template declaration. The template parameters
are a pointer to a constant character string (const char*) which is the
format string for std::format, and a variadic parameter pack (Args...)
which are the arguments to be formatted.
*/
template<const char* format, typename... Args>
void WriteLogFile(const std::string& filename, const char* file, int line, Args&&... args)
{
    std::ofstream logFile(filename, std::ios_base::app); // output file stream, append mode
    if (!logFile)
    {
        std::cerr << "Failed to open log file." << std::endl;
        return;
    }

    auto now = std::chrono::system_clock::now();
    auto zonedTime = std::chrono::current_zone()->to_local(now);

    auto localDays = std::chrono::floor<std::chrono::days>(zonedTime);
    auto timeOfDay = zonedTime - localDays;

    auto ymd = std::chrono::year_month_day{ localDays };
    auto hms = std::chrono::hh_mm_ss{ timeOfDay };

    std::string formattedTime = std::format("{}-{}-{} {}:{}:{}",
        ymd.year(), ymd.month(), ymd.day(),
        hms.hours().count(), hms.minutes().count(), hms.seconds().count());
    std::string message = std::format(format, formattedTime, file, line, std::forward<Args>(args)...);

    logFile << message << std::endl; // write message to the log file
    std::cout << message << std::endl; // write message to the console

    logFile.close();
}

// global constant character string for the format of the log message
constexpr char coffee_format[] = "{} [{}:{}] - Brewing a cup of {} with {}ml of milk at {} degrees.";

void BrewCoffee(const std::string& coffeeType, int milkAmount, int temperature)
{
    // notice that everything after __LINE__ is a variadic parameter pack
    WriteLogFile<coffee_format>("coffeeMachine.log", __FILE__, __LINE__, coffeeType, milkAmount, temperature);
}

int main()
{
    BrewCoffee("Espresso", 0, 90);
    BrewCoffee("Cappuccino", 150, 85);

    return 0;
}

/*
output:
2024-Feb-03 14:35:38 [main14.cpp:48] - Brewing a cup of Espresso with 0ml of milk at 90 degrees.
2024-Feb-03 14:35:38 [main14.cpp:48] - Brewing a cup of Cappuccino with 150ml of milk at 85 degrees.
*/