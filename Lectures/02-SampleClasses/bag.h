#include <iostream>

#include "contact.h"
using namespace std;

class Bag {

public:
	Bag(): size(5), contacts(new Contact[20]) {}
	
	void add(Contact x) {
		contacts[size] = x;
		size++;
	}

	void print () {
		cout << "Bag contents are "<< endl;
		for (int i = 0; i < size; i++)
			contacts[i].print();
	}

	bool checker(Contact check) {
		
		for (int i = 0; i < size; i++) {
			if(contacts[i].getFirst() == check.getFirst())
				if(contacts[i].getLast() == check.getLast())
					return true;		
		}
		return false;
	}
 
private:
	Contact *contacts;
	int size;

};
