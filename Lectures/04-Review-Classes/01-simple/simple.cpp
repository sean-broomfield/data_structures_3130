#include <iostream>

#include "simple.h"

using namespace std;

ostream &operator << (std::ostream &os, const Simple &simple) {
	os << simple.val;
	return os;
}

istream &operator >> (std::istream &in, Simple &simple) {
        in >> simple.val;
	return in;
}

Simple::Simple(int val) : val(val) {}

int Simple::get() const {return val;}
