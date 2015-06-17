#include <iostream>
#include "addressbook.h"

using namespace std;

int main () {

	AddressBook book;

	book.add(Contact("John", "Doe"));
	book.add(Contact("Gerald", "Weiss"));
	bool value = book.checker(Contact("Gerald", "Weiss"));
	bool value1 = book.checker(Contact("Jeffrey", "Dover"));
	book.print();
	cout << "If value is 1 then Gerald Weiss exists else it does not. Value is " << value << endl;
	cout << "If value is 1 then Jeffrey Dover exists else, it does not. Value is " << value1 << endl;
	return 0;
}
	
