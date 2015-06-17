#include <iostream>
#include "array.h"

using namespace std;

int main() {
	int place = 3;	
	Array array;

	array.addNumber(PhoneNumber(123,456,7890, "Home"));				//adds number to array
	array.addNumber(PhoneNumber(324,238,0277, "Work"));
	array.addNumber(PhoneNumber(111,111,1111));
	array.setNumber(PhoneNumber(567,892, 2367, "HOME"), 3);			//sets number
	cout << "Size is " << array.getSize() << endl;					//prints out number of elements added to array
	array.print();								//prints elements of array

	PhoneNumber uno = array.getNumber(place);					//gets the 3rd entry
	cout << "New Number is in place " << place << " is ";
	uno.print();
	

	return 0;

}
