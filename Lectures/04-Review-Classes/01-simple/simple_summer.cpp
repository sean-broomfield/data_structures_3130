#include <iostream>
#include "simple.h"

using namespace std;

int main() {
	Simple s, s_total;

	for (s.set(0); s.get() < 10; s.set(s.get() +1))
		s.total.set(s_total.get() + s.get());
	cout << s_total << endl;

	return 0;
}
