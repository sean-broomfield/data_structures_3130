#include <iostream>
#include "array.h"

using namespace std;

class Contact {
public:
	Contact (string name1, string name2): first(name1), last(name2), array() {}
	Contact(): first(""), last(""), array(){}	

	string getFirst() {return first;}
	string getLast() {return last;}

	 void add(PhoneNumber x) {
		array.addNumber(x);
	}

	void print() {
		cout << first << " " << last << endl;
		array.print();	
	}

private:
	Array array;
	string first, last;
};
