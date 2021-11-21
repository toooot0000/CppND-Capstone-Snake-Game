#include <thread>
#include <mutex>
#include <memory>

class Timer
{
private:
    std::thread thd;
    unsigned int interval;

    std::mutex runningMut;
    bool isRunning{false};

    std::mutex interruptMut;
    bool interupt{false};

    void Timing(int nanosec);

public:
    Timer();
    ~Timer();
    Timer(unsigned int nanosec);

    bool Start(int nanosec = -1);
    bool Stop();
    bool Pause();

    void Restart(int nanosec = -1);

    bool IsTimeOut();
};