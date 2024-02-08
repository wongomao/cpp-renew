#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <format>
#include "logger.hpp"

#define LOGFILENAME "craps.log"

std::string formatTimestamp(const std::chrono::system_clock::time_point& now)
{
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::tm timeInfo;
    localtime_s(&timeInfo, &t);
    std::stringstream ss;
    ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << '.' << std::setfill('0') << std::setw(3) << milliseconds.count();
    return ss.str();
}

void Logger::log(const char* message)
{
    const std::string filename = LOGFILENAME;
    std::ofstream logFile(filename, std::ios::app); // open file in append mode
    if (!logFile)
    {
        std::cerr << "Error opening log file." << std::endl;
        return;
    }
    
    const auto now = std::chrono::system_clock::now();
    const std::string timestamp = formatTimestamp(now);
    std::ostringstream output;
    output << timestamp << " " << message << std::endl;
    logFile << output.str();
    logFile.close();
}