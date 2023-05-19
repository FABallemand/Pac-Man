#ifndef _LOGGER_H__
#define _LOGGER_H__

#include <iostream>

#define BORANGE "\033[1;33m" // ORANGE BOLD
#define BRED "\033[1;31m"    // RED BOLD
#define BGREEN "\033[1;32m"  // GREEN BOLD
#define BBLUE "\033[1;34m"   // BLUE BOLD
#define BPURPLE "\033[1;35m" // PURPLE BOLD
#define BCYAN "\033[1;36m"   // CYAN BOLD
#define RESET "\e[0m"        // RESET

/**
 * \enum LogType
 * 
 * \brief Type of log message
 *
 */
enum LogType
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    GAME
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
 * \remark Inspired by: https://stackoverflow.com/questions/5028302/small-logger-class
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
     * \tparam T Type of the log message
     * \param msg Log message content
     * \return LOG& Reference to the log message
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
    std::string getHeader(LogType type);
};

#endif