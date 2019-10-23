#include "Timer.h"
#include <time.h>

Timer::Timer() : theClock()
{
    //ctor
}

Timer::~Timer()
{
    //dtor
}

Timer::Timer(const Timer& other) : theClock(other.theClock)
{
    //copy ctor
}

Timer& Timer::operator=(const Timer& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->theClock = rhs.theClock;
    return *this;
}
void Timer::start() {
    theClock = clock();
}
long Timer::stop() {
    return (double)(clock() - this->theClock)*1000/CLOCKS_PER_SEC;
}
