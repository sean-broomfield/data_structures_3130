#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>

class Integer {
	friend std::ostream &operator <<(std::ostream &os, const Integer &integer);
	friend std::istream &operator >>(std::istream &is, Integer &integer);
	friend Integer operator +(const Integer &il, const Integer &i2);
	friend Integer operator *(const Integer &i1, const Integer &i2);
	friend Integer operator -(const Integer &i1, const Integer &i2);
	friend Integer operator /(const Integer &i1, const Integer &i2);
	friend Integer operator -(const Integer &i1);
	friend bool operator ==(const Integer &i1, const Integer &i2);
	friend bool operator <(const Integer &i1, const Integer &i2);
	friend bool operator >(const Integer &i1, const Integer &i2);
	friend void operator --(Integer &i1);	
	friend void operator --(Integer &i1, int);	
	friend void operator ++(Integer &i1);	
	friend void operator ++(Integer &i1, int);	
	
public:
	Integer(int val = 0) : val(val) {}
	Integer &operator +=(const Integer &other);
	Integer &operator -=(const Integer &other);
	Integer &operator *=(const Integer &other);
	Integer &operator /=(const Integer &other);
private:
	int val;

};

#endif
