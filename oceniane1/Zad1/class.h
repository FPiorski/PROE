#pragma once
class Timer{
private:
    time_t start_, elapsed_;
    bool running_;
public:
    Timer();
    void start();
    void pause();
    double stop();
    double stop(const std::string& s);
};
