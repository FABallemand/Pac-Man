#ifndef _DISPLAY_UTILS_H__
#define _DISPLAY_UTILS_H__

#include <iostream>
#include <string>
#include <stdarg.h>

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
 * \brief Print error message in stderr
 */
void printError(const char *fmt, ...);

/**
 * \brief Print warning message in stderr
 */
void printWarning(const char *fmt, ...);

/**
 * \brief Print information message in stdout
 */
void printInfo(const char *fmt, ...);

#endif