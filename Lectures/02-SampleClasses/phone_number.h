#include <iostream>
using namespace std;

class PhoneNumber {
public:
//	 PhoneNumber() {a_code = 0; exch = 0; subscr = 0; category = "";}
/*	 PhoneNumber(int one , int two, int three, string name) {
		a_code = one;
		exch = two;
		subscr = three;
		category = name;
	} */

//	PhoneNumber(int one, int two, int three) {a_code = one; exch = two; subscr = three; category = "";}
	

	PhoneNumber(): a_code(0), exch(0), subscr(0), category("") {}
	PhoneNumber(int one, int two, int three, string name): a_code(one), exch(two), subscr(three), category(name) {}
	PhoneNumber(int one, int two, int three): a_code(one), exch(two), subscr(three), category("") {}

	int get_area_code() {return a_code;}
	int get_exchange() {return exch;}
	int get_subscriber() {return subscr;}
	string get_category() {return category;}

	void print() {
		cout << "(" << get_area_code() << ")-" << get_exchange() << "-" << get_subscriber() <<  " (" << get_category() << ")" << endl;
	}
private:
	int a_code, exch, subscr;
	string category;

};
