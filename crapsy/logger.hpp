// logger.hpp
#ifndef LOGGER_HPP
#define LOGGER_HPP

enum class Level
{
    INFO,
    DEBUG,
    WARNING,
    ERROR
};

struct Logger
{
    static void log(Level level, const char* message);
};


#endif // LOGGER_HPP