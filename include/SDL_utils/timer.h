#ifndef __TIMER_H__
#define __TIMER_H__

#include <SDL.h>

/**
 * \class Timer
 * \brief
 */
class Timer
{
public:
    Timer();

    Uint32 getTicks();

    bool isStarted();

    bool isPaused();

    /**
     * \brief Start the timer
     */
    void start();

    /**
     * \brief Stop the timer
     */
    void stop();

    /**
     * \brief Pause the timer
     */
    void pause();

    /**
     * \brief Unpause the timer
     */
    void unpause();

private:
    Uint32 start_ticks; //!< Clock time when the timer started
    Uint32 pause_ticks; //!< Ticks stored when the timer was paused
    bool paused;        //!< Timer pause status
    bool started;       //!< Timer start status
};

#endif