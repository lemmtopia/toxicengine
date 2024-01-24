#include "Logger.h"

#include <iostream>
#include <chrono>
#include <ctime>

void Logger::Log(const char* message) {
    auto time = std::chrono::system_clock::now();
    std::time_t date = std::chrono::system_clock::to_time_t(time);
    std::cout << "\x1b[32mLOG: " << std::ctime(&date) << "\t" << message << "\n\x1b[0m";
}

void Logger::Err(const char* message) {
    auto time = std::chrono::system_clock::now();
    std::time_t date = std::chrono::system_clock::to_time_t(time);
    std::cout << "\x1b[31mERR: " << std::ctime(&date) << "\t" << message << "\n\x1b[0m";
}
