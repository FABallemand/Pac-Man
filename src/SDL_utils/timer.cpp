#include "timer.h"

Timer::Timer()
{
    // Initialize the variables
    start_ticks = 0;
    pause_ticks = 0;

    paused = false;
    started = false;
}

void Timer::start()
{
    // Start the timer
    started = true;

    // Unpause the timer
    paused = false;

    // Get the current clock time
    start_ticks = SDL_GetTicks();
    pause_ticks = 0;
}

void Timer::stop()
{
    // Stop the timer
    started = false;

    // Unpause the timer
    paused = false;

    // Clear tick variables
    start_ticks = 0;
    pause_ticks = 0;
}

void Timer::pause()
{
    // If the timer is running and isn't already paused
    if (started && !paused)
    {
        // Pause the timer
        paused = true;

        // Calculate the paused ticks
        pause_ticks = SDL_GetTicks() - start_ticks;
        start_ticks = 0;
    }
}

void Timer::unpause()
{
    // If the timer is running and paused
    if (started && paused)
    {
        // Unpause the timer
        paused = false;

        // Reset the starting ticks
        start_ticks = SDL_GetTicks() - pause_ticks;

        // Reset the paused ticks
        pause_ticks = 0;
    }
}

Uint32 Timer::getTicks()
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
            time = SDL_GetTicks() - start_ticks;
        }
    }

    return time;
}

bool Timer::isStarted()
{
    // Timer is running and paused or unpaused
    return started;
}

bool Timer::isPaused()
{
    // Timer is running and paused
    return paused && started;
}