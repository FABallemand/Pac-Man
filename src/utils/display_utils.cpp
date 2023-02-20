#include "display_utils.h"

using namespace std;

void printError(const char *fmt, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    cerr << BRED << "ERROR: " << RESET << buffer << endl;
}

void printWarning(const char *fmt, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    cerr << BORANGE << "WARNING: " << RESET << buffer << endl;
}