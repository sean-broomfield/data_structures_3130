#include <ctime>
#include <sstream>
#include "clock_utils.h"
#include <iostream>

using namespace std;

int ticks(clock_t t) 	{return t % CLOCKS_PER_SEC;}
int seconds(clock_t t) 	{return t / CLOCKS_PER_SEC % 60;}
int minutes(clock_t t) 	{return t / CLOCKS_PER_SEC / 60 % 60;}
int hours(clock_t t) 	{return t / CLOCKS_PER_SEC / 60 / 60;}

void all(clock_t t, int &hours, int &minutes, int &seconds, int &ticks) {
	ticks = t % CLOCKS_PER_SEC;
	seconds = t / CLOCKS_PER_SEC;
	minutes = seconds / 60;
	seconds %= 60;
	hours = minutes / 60;
	minutes %= 60;
}

std::string asString(clock_t duration) {

	ostringstream oss;

	oss << hours(duration) << ":" << minutes(duration) << ":" << seconds(duration) << ":" << ticks(duration) << endl;


	return oss.str();

}
