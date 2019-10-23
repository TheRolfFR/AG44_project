#ifndef TIMER_H
#define TIMER_H
#include <time.h>


class Timer
{
    public:
        Timer();
        virtual ~Timer();
        Timer(const Timer& other);
        Timer& operator=(const Timer& other);
        void start();
        long stop();
    private:
        clock_t theClock;
};

#endif // TIMER_H
