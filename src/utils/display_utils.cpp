#include "display_utils.h"

#define DEBUG 1

void printError(const char *fmt, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    std::cerr << BRED << "ERROR: " << RESET << buffer << std::endl;
}

void printWarning(const char *fmt, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    std::cerr << BORANGE << "WARNING: " << RESET << buffer << std::endl;
}

void printInfo(const char *fmt, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    std::cerr << BBLUE << "INFO: " << RESET << buffer << std::endl;
}