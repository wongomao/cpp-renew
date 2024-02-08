#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <format>
#include <cstdarg> // variadic function

std::string formatTimestamp(const std::chrono::system_clock::time_point& now)
{
    auto time = std::chrono::system_clock::to_time_t(now);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    std::tm timeInfo;
    localtime_s(&timeInfo, &time); // use localtime_s on Windows, std::localtime on *nix

    std::stringstream ss;
    ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << "." << std::setfill('0') << std::setw(3) << milliseconds.count();
    return ss.str();
}

void WriteLogFile(const std::string& filename,
    const char* file,
    int line,
    const char* format,
    ...) // variadic function
{
    // use name logFile for output stream;
    // flag std::ios_base::app to append to the file
    std::ofstream logFile(filename, std::ios_base::app);
    if (!logFile)
    {
        std::cerr << "Failed to open log file." << std::endl;
        return;
    }
    auto now = std::chrono::system_clock::now();
    std::string timestamp = formatTimestamp(now);

    va_list args; // declare a va_list
    // initialize the va_list with the first argument after 'format'
    va_start(args, format); // initialize the va_list
    int bufferSize = std::vsnprintf(nullptr, 0, format, args) + 1; // get the size of the buffer
    va_end(args); // reset the va_list
    if (bufferSize <= 0)
    {
        std::cerr << "Failed to format log message." << std::endl;
        return;
    }

    std::vector<char> buffer(bufferSize);
    va_start(args, format); // initialize the va_list again
    std::vsnprintf(buffer.data(), bufferSize, format, args); // format the message
    va_end(args); // reset the va_list

    std::ostringstream message;
    message << timestamp << " [" << file << ":" << line << "] - " << buffer.data();
    logFile << message.str() << std::endl; // write message to the log file
    std::cout << message.str() << std::endl; // write message to the console
    logFile.close();

    /*
    If we use std::string_view format instead of const char* format, we can use std::format to format the message:
    std::string message = std::format("{} [{}:{}] - {}", 
        timestamp, 
        file, 
        line, 
        std::format(format, args...));    
    */

    /* to use this function:
    WriteLogFile("application.log", __FILE__, __LINE__, "The value of x is {}", x);
    this will append a message to "application.log":
    "Tue Mar 16 14:00:00 2021 [main.cpp:10] - The value of x is 5"
    */
}

int main()
{
    std::string user{"John"};
    WriteLogFile("application.log", __FILE__, __LINE__, "User %s logged in", user.c_str());
    return 0;
}