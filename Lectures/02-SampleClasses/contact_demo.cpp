#include <iostream>
#include "contact.h"

using namespace std;

int main() {

	Contact contact("Gerald", "John");

	cout << "Contact's name is " << contact.getFirst() << " " << contact.getLast() << endl;

	contact.add(PhoneNumber(482,937,1308, "Home"));

	contact.print();

	return 0;

}
