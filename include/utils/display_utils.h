#ifndef _DISPLAY_UTILS_H__
#define _DISPLAY_UTILS_H__

/**
 * \remark Inspired by: https://stackoverflow.com/questions/5028302/small-logger-class
 */

#include <iostream>

#define BLACK "\033[0;30m"   // BLACK
#define RED "\033[0;31m"     // RED
#define ORANGE "\033[0;33m"  // ORANGE
#define BORANGE "\033[1;33m" // ORANGE BOLD
#define BRED "\033[1;31m"    // RED BOLD
#define GREEN "\033[0;32m"   // GREEN
#define YELLOW "\033[0;33m"  // YELLOW
#define BLUE "\033[0;34m"    // BLUE
#define BBLUE "\033[1;34m"   // BLUE BOLD
#define PURPLE "\033[0;35m"  // PURPLE
#define BPURPLE "\033[1;35m" // PURPLE BOLD
#define CYAN "\033[0;36m"    // CYAN
#define BCYAN "\033[1;36m"   // CYAN BOLD
#define WHITE "\033[0;37m"   // WHITE
#define RESET "\e[0m"        // RESET

enum typelog
{
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

struct structlog
{
    bool headers = true;
    typelog level = DEBUG;
};

extern structlog LOGGER_CONFIG;

class LOG
{
public:
    LOG() {}

    LOG(typelog type)
    {
        msglevel = type;
        if (LOGGER_CONFIG.headers)
        {
            operator<<(getHeader(type));
        }
    }

    ~LOG()
    {
        if (opened)
        {
            std::cout << std::endl;
        }
        opened = false;
    }

    template <class T>
    LOG &operator<<(const T &msg)
    {
        if (msglevel >= LOGGER_CONFIG.level)
        {
            std::cout << msg;
            opened = true;
        }
        return *this;
    }

private:
    bool opened = false;
    typelog msglevel = DEBUG;

    inline std::string getLabel(typelog type)
    {
        std::string label;
        switch (type)
        {
        case DEBUG:
            label = "DEBUG";
            break;
        case INFO:
            label = "INFO";
            break;
        case WARNING:
            label = "WARNING";
            break;
        case ERROR:
            label = "ERROR";
            break;
        }
        return label;
    }

    inline std::string getHeader(typelog type)
    {
        std::string header;
        switch (type)
        {
        case DEBUG:
            header = BPURPLE + std::string{"[DEBUG] "} + RESET;
            break;
        case INFO:
            header = BBLUE + std::string{"[INFO] "} + RESET;
            break;
        case WARNING:
            header = BORANGE + std::string{"[WARNING] "} + RESET;
            break;
        case ERROR:
            header = BRED + std::string{"[ERROR] "} + RESET;
            break;
        }
        return header;
    }
};

#endif