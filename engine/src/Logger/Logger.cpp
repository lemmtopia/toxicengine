#include "Logger.h"

#include <ctime>
#include <iomanip>
#include <iostream>

void Logger::Log(const char* message) {
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);

	std::cout << "\x1b[36mLOG: " << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << " - " << message << "\x1b[0m\n"; 
}

void Logger::Err(const char* message) {
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);

	std::cout << "\x1b[31mERR: " << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << " - " << message << "\x1b[0m\n"; 
}
