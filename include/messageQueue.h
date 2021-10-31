#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

template <class T>
class MessageQueue
{
private:
    std::queue<T> q;
    std::mutex mtx;
    std::condition_variable cond;

public:
    MessageQueue() {}
    ~MessageQueue() {}

    T pop()
    {
        std::unique_lock<std::mutex> lock(mtx);
        cond.wait(lock, [this]()
                  { return !q.empty() });
        T ret = q.front();
        q.pop();
        return ret;
    }
    void push(T &&element)
    {
        std::scoped_lock<std::mutex> lock(mtx);
        q.emplace(std::move(element));
        cond.notify_one();
    }
};