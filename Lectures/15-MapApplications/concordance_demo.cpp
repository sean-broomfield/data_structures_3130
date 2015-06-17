#include <iostream>
#include <utility>
#include "concordance.h"
#include <string>

using namespace std;

int main() {
	Concordance c;
	c.add("concordance.cpp");
	
	cout << "Using provided concordance.cpp" << endl << endl;
    
	cout << c << endl;
	cout << endl;

	cout << "'return' occurs: " << c["return"] << " times" << endl;
	cout << "'>>' occurs: " << c[">>"] << " times" << endl;
    cout << "'void' occurs: " << c[">>"]<< " times" << endl;

	cout << endl << endl;
	cout << c << endl << endl;

	return 0;
}
