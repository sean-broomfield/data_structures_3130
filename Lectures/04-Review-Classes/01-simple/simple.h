#ifndef SIMPLE_H
#define SIMPLE_H

#include <iostream>

class Simple {
	friend std::ostream &operator << (std::ostream &os, const Simple &simple);
	friend std::istream &operator >> (std::istream &in, Simple &simple);
public:
	Simple(int val = 0);
	int get() const;
	void set(int val) {this->val = val;}
private:
	int val;
};

#endif
