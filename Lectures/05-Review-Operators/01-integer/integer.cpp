#include <iostream>

#include "integer.h"

using namespace std;

void operator --(Integer &i1) {
	i1.val--;	
}

void operator --(Integer &i1, int) {
	i1.val--;
}

void operator ++(Integer &i1) {
	i1.val++;
}

void operator ++(Integer &i1, int) {
	i1.val++;
}

ostream &operator <<(ostream &os, const Integer &integer) {
	os << integer.val;
	return os;
}

istream &operator >>(istream &is, Integer &integer) {
	is >> integer.val;
	return is;
}

Integer operator +(const Integer &i1, const Integer &i2) {
	Integer result = i1;
	return result += i2;
}

Integer &Integer::operator +=(const Integer &other) {
	val += other.val;
	return *this;
}

Integer operator *(const Integer &i1, const Integer &i2) {
	Integer result = i1;
	return result *= i2;
}

Integer &Integer::operator *=(const Integer &other) {
	val *= other.val;
	return *this;
}

Integer &Integer::operator /=(const Integer &other) {
	val /= other.val;
	return *this;
}

Integer operator /(const Integer &i1, const Integer &i2) {
	Integer result = i1;
	return result /= i2;
}

Integer &Integer::operator -=(const Integer &other) {
	val -= other.val;
	return *this;
}

Integer operator -(const Integer &i1, const Integer &i2) {
	Integer result = i1;
	return result -= i2;

}

Integer operator -(const Integer &i1) {
	Integer result = -(i1.val);
	return result;	
}

bool operator ==(const Integer &i1, const Integer &i2) {
	Integer result = i1;
	
	if(result.val == i2.val)
		return true;
	else 
		return false;
}
	
bool operator >(const Integer &i1, const Integer &i2) {
	Integer result = i1;
	
	if(result.val > i2.val)
		return true;
	else
		return false;
}



bool operator <(const Integer &i1, const Integer &i2) {
	Integer result = i1;

	if (result.val < i2.val)
		return true;
	else 
		return false;
}

