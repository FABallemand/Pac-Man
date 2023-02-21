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

/**
 * \brief Type of log message
 *
 */
enum LogType
{
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

/**
 * \brief Global configuration of the logger
 *
 */
struct LogConf
{
    bool headers = true;
    LogType level = DEBUG;
};

extern LogConf LOGGER_CONFIG;

/**
 * \brief Logger class
 *
 */
class LOG
{
public:
    LOG() {}

    LOG(LogType type)
    {
        type_ = type;
        if (LOGGER_CONFIG.headers)
        {
            operator<<(getHeader(type));
        }
    }

    ~LOG()
    {
        if (open_)
        {
            std::cout << std::endl;
        }
        open_ = false;
    }

    /**
     * \brief
     *
     * \tparam T
     * \param msg
     * \return LOG&
     */
    template <class T>
    LOG &operator<<(const T &msg)
    {
        if (type_ >= LOGGER_CONFIG.level)
        {
            std::cout << msg;
            open_ = true;
        }
        return *this;
    }

private:
    bool open_ = false;    //!< State of the log
    LogType type_ = DEBUG; //!< Type of the log

    /**
     * \brief Get the header to use for a log message
     * 
     * \param type Type of the log message
     * \return std::string Header of the log message
     */
    inline std::string getHeader(LogType type)
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