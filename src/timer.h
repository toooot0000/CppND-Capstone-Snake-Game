#include <thread>
#include <mutex>
#include <memory>

class Timer
{
private:
    std::thread thd;

    std::mutex runningMut;
    bool isRunning{false};

    std::mutex interruptMut;
    bool interupt{false};

    void Timing(int nanosec);

public:
    Timer();
    ~Timer();

    // can't be copied or moved
    Timer(const Timer &other) = delete;
    Timer &operator=(const Timer &other) = delete;
    Timer(Timer &&other) = delete;
    Timer &operator=(Timer &&other) = delete;

    /**
     * @brief if nanosec == -1, then use preset interval. Otherwise use nanosec;
     * 
     * @param nanosec 
     * @return true 
     * @return false 
     */
    bool Start(int nanosec);
    bool Stop();
    bool Pause();

    void Restart(int nanosec);

    bool IsTimeOut();
};