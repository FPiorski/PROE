#include <ctime>
#include <string>
#include <stdexcept>
#include "class.h"

Timer::Timer()
{
    running_ = false;
    elapsed_ = (time_t) 0;
}

void Timer::start()
{
    running_ = true;
    time(&start_);
    if (start_ == -1)
        throw std::runtime_error("Time measurment failed");
}

void Timer::pause()
{
    if (!running_)
        start();
    else {
        running_ = false;
        elapsed_ += difftime(time(NULL), start_);
    }
}

double Timer::stop()
{
    if (running_)
        pause();
    return (double) elapsed_;
}

double Timer::stop(const std::string& s)
{
    double factor;
    if (s == "s" || s == "seconds")
        factor = 1;
    else if (s == "ms" || s == "milliseconds")
        factor = 0.001;
    else if (s == "us" || s == "microseconds")
        factor = 0.000001;
    else if (s == "m" || s == "min" || s == "minutes")
        factor = 60;
    else if (s == "h" || s == "hours")
        factor = 3600;
    else if (s == "d" || s == "days")
        factor = 86400;
    else if (s == "w" || s == "weeks")
        factor = 604800;
    else if (s == "mo" || s == "months")
        factor = 18144000;
    else if (s == "y" || s == "years")
        factor = 220752000;
    else
        factor = 1;
    return stop()/factor;
}
