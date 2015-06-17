#include <iostream>
#include "integer.h"

using namespace std;

int main () {
	
	Integer enter, holder, counter, zero;

	while ((enter > zero) || (enter == zero)) {
		
        cin >> enter;
        if ((enter > zero) || (enter == zero)) {
		cout << "Value entered is " << enter << endl;
            holder+=enter;
            counter++;
        }
	}

    cout << "Sum of values entered is " << holder << endl;
    cout << "The number of values entered is " << counter << endl;
	holder/=counter;
	cout << "Average of elements entered is " << holder << endl;
	
}
