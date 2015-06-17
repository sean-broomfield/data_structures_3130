#include <iostream>

#include "phone_number.h"

using namespace std;

int main() {
	PhoneNumber phone_number(123, 456, 7890, "Home");
	phone_number.print();
	cout << endl;
	cout << phone_number.get_area_code() << endl;
	cout << phone_number.get_exchange() << endl;
	cout << phone_number.get_subscriber() << endl;

	PhoneNumber phone_number2;
	phone_number2.print();
	cout << endl;
	
	PhoneNumber(234, 567, 8901).print();
	cout << endl;

	return 0;
}
