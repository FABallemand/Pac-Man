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
    Timer()
    {
        // Initialize the variables
        start_ticks = 0;
        pause_ticks = 0;

        paused = false;
        started = false;
    }

    Uint32 getTicks()
    {
        // The actual timer time
        Uint32 time = 0;

        // If the timer is running
        if (started)
        {
            // If the timer is paused
            if (paused)
            {
                // Return the number of ticks when the timer was paused
                time = pause_ticks;
            }
            else
            {
                // Return the current time minus the start time
                time = SDL_GetTicks64() - start_ticks;
            }
        }

        return time;
    }

    bool isStarted()
    {
        // Timer is running and paused or unpaused
        return started;
    }

    bool isPaused()
    {
        // Timer is running and paused
        return paused && started;
    }

    /**
     * \brief Start the timer
     */
    void start()
    {
        // Start the timer
        started = true;

        // Unpause the timer
        paused = false;

        // Get the current clock time
        start_ticks = SDL_GetTicks64();
        pause_ticks = 0;
    }
    /**
     * \brief Stop the timer
     */
    void stop()
    {
        // Stop the timer
        started = false;

        // Unpause the timer
        paused = false;

        // Clear tick variables
        start_ticks = 0;
        pause_ticks = 0;
    }

    /**
     * \brief Pause the timer
     */
    void pause()
    {
        // If the timer is running and isn't already paused
        if (started && !paused)
        {
            // Pause the timer
            paused = true;

            // Calculate the paused ticks
            pause_ticks = SDL_GetTicks64() - start_ticks;
            start_ticks = 0;
        }
    }

    /**
     * \brief Unpause the timer
     */
    void unpause()
    {
        // If the timer is running and paused
        if (started && paused)
        {
            // Unpause the timer
            paused = false;

            // Reset the starting ticks
            start_ticks = SDL_GetTicks64() - pause_ticks;

            // Reset the paused ticks
            pause_ticks = 0;
        }
    }

private:
    Uint32 start_ticks; //!< Clock time when the timer started
    Uint32 pause_ticks; //!< Ticks stored when the timer was paused
    bool paused;        //!< Timer pause status
    bool started;       //!< Timer start status
};

#endif