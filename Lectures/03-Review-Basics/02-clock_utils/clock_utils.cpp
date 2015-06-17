#include <ctime>
#include <sstream>
#include "clock_utils.h"
#include <iostream>

using namespace std;


Duration all(clock_t t) {
	int ticks = t % CLOCKS_PER_SEC;
	int seconds = t / CLOCKS_PER_SEC;
	int minutes = seconds / 60;
	seconds %= 60;
	int hours = minutes / 60;
	minutes %= 60;
    
    Duration dura;
    
    dura.hours = hours;
    dura.minutes = minutes;
    dura.seconds = seconds;
    dura.ticks = ticks;
    
    return dura;
}


std::string asString(Duration duration) {
    
	ostringstream oss;
    
	oss << duration.hours << ":" << duration.minutes << ":" << duration.seconds << ":" << duration.ticks << endl;
    
	return oss.str();
    
}