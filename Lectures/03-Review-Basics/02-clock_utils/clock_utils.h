#ifndef CLOCK_UTILS_H
#define CLOCK_UTILS_H

#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;

class Duration {
public:
    int hours;
    int minutes;
    int seconds;
    int ticks;
};

Duration all(clock_t t);
std::string asString(clock_t duration);
std::string asString(Duration dura);

#endif
