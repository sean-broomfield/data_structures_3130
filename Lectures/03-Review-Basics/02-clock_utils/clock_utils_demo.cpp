#include <iostream>

#include "clock_utils.h"

using namespace std;

int main() {
	cout << CLOCKS_PER_SEC << endl;
    
	clock_t start_time = clock();
	for (int i = 0; i < 1000000; i++)
		i / 17;
	clock_t end_time = clock();
    
	clock_t duration = end_time - start_time;
    
    Duration timing = all(duration);
    
    cout << "As string: ";
    string s = asString(timing);
    cout << s;

	start_time = clock();
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000000; j++)
			i / 17;
	end_time = clock();
    
	duration = end_time - start_time;

    timing = all(duration);
    s = asString(timing);
    cout << "As string: ";
    cout << s;

	return 0;
}
