#pragma once

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

