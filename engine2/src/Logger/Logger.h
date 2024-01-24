#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
    public:
        static void Log(const char* message);
        static void Err(const char* message);
};

#endif
