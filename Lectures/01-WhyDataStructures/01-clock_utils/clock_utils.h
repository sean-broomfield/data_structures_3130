#ifndef CLOCK_UTILS_H
#define CLOCK_UTILS_H

#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;

int ticks(clock_t t);
int seconds(clock_t t);
int minutes(clock_t t);
int hours(clock_t t);

void all(clock_t t, int &hours, int &minutes, int &seconds, int &ticks);
std::string asString(clock_t duration);

#endif
