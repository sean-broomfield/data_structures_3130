#include <iostream>
#include "bag.h"

using namespace std;

class AddressBook {
public:
	
	AddressBook(): bag(){}

	void add(Contact x) {
		bag.add(x);	
	}

	bool checker(Contact x) {
		return (bag.checker(x));
	}

	void print() {
		bag.print();
	}

private:
	Bag bag;
};
