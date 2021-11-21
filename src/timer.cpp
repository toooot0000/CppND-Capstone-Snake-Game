#include "timer.h"
#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>

Timer::Timer()
    : interval(1)
{
}

Timer::Timer(unsigned int microSec)
    : interval(microSec)
{
}

void Timer::Timing(int microSec)
{
    auto start = std::chrono::system_clock().now();
    auto interval = std::chrono::microseconds(microSec);
    while (true)
    {
        {
            std::unique_lock<std::mutex> uLock(interruptMut);
            if (interupt)
            {
                break;
            }
        }
        auto cur = std::chrono::system_clock().now();
        if (cur - start >= interval)
        {
            break;
        }
    }
    std::unique_lock<std::mutex> uLock(runningMut);
    isRunning = false;
}

bool Timer::Start(int sec)
{
    {
        std::unique_lock<std::mutex> uLock(runningMut);
        if (isRunning)
        {
            return false;
        }
    }
    {
        std::unique_lock<std::mutex> runningLock(runningMut, std::defer_lock), interruptLock(interruptMut, std::defer_lock);
        std::lock(runningLock, interruptLock);
        interupt = false;
        isRunning = true;
    }
    if (sec != -1)
    {
        interval = sec;
    }
    if (thd.joinable())
    {
        thd.join();
    }
    thd = std::thread(&Timer::Timing, this, interval);
    return true;
}

bool Timer::Stop()
{
    {
        std::unique_lock<std::mutex> uLock(runningMut);
        if (!isRunning)
        {
            return false;
        }
    }
    {
        std::unique_lock<std::mutex> uLock(interruptMut);
        interupt = true;
    }
    if (thd.joinable())
    {
        std::cout << "Join the running thread!\n";
        thd.join();
    }
    return true;
}

bool Timer::IsTimeOut()
{
    std::unique_lock<std::mutex> uLock(runningMut);
    return !isRunning;
}

void Timer::Restart(int microSec)
{
    Stop();
    Start(microSec);
}

Timer::~Timer()
{
    if (thd.joinable())
    {
        thd.join();
    }
}