#include "timer.h"
#include <iostream>

using namespace std;
int main()
{
    Timer timer;
    auto start = chrono::system_clock().now();
    timer.Start(2000000);
    this_thread::sleep_for(chrono::microseconds(2000));
    timer.Stop();
    // while (!timer.IsTimeOut())
    // {
    // }
    auto end = chrono::system_clock().now();

    cout << "Start time: " << start.time_since_epoch().count() << "\n"
         << "End time: " << end.time_since_epoch().count() << "\n"
         << "Time laps: " << (end - start).count() << "\n"
         << "Is time out? :" << timer.IsTimeOut()
         << endl;

    timer.Restart(2000000);
    // timer.Restart(2000000);

    start = chrono::system_clock().now();

    timer.Restart(2000000);
    while (!timer.IsTimeOut())
    {
    }
    end = chrono::system_clock().now();

    cout << "Start time: " << start.time_since_epoch().count() << "\n"
         << "End time: " << end.time_since_epoch().count() << "\n"
         << "Time laps: " << (end - start).count() << endl;
}