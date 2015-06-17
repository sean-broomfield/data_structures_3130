#include <iostream>

#include "simple.h"

using namespace std;

int main() {
	Simple s1(1), s2 = 4, s3, s4;

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "S3: " << s3 << endl;

	cin >> s4;

	cout << "S4: " << s4 << endl;
	cout << "s1.get(): " << s1.get() << endl;

	s1.set(s2.get()+1);
	cout << "after s1.set(s2.get()) - s1: " << s1 << endl;
}
