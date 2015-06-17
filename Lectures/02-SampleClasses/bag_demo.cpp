#include <iostream>
#include "bag.h"

using namespace std;

int main() {
	
	Bag bag;

	bag.add(Contact("John", "Don"));
	bag.add(Contact("Gerald", "Weiss"));
	bag.add(Contact("Joe", "Free"));	

	bag.print();

	bool value = bag.checker(Contact("John", "Don"));

	cout << "If value is one then contact was found else contact doesnt exist. Value is " << value << endl;	

	return 0;

}
