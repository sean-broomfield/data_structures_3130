#include <iostream>

#include "array.h"
#include "array_exception.h"

using namespace std;

int main() {
	Array <int>arr(10);
	
	try {
		cout << arr[arr.getSize()];
		throw "oUT OF BOUNDS.";
	} catch (ArrayException e) {
		cout << "Caught expected ArrayException: " << e << endl;
	}

	for (int i = 0; i < 1000; i++)
		arr+= i;

	cout << arr << endl;

	for(int i = 0; i < 20; i++)
		cout << i << ": " << arr[i] << endl;

	for (int i = 0; i < 20; i++)
		arr[i] = arr[i] * -1;
	
	for (int i = 0; i < 20; i++)
		cout << i << ": " << arr[i] << endl;

	return 0;
}
