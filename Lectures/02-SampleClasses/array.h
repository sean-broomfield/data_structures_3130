#include <iostream>
#include "phone_number.h"
using namespace std;

class Array {
public:
//	Array(int capacity, int size): arr(new PhoneNumber [capacity]), size(size)  {}			//default constructor

	Array(): arr(new PhoneNumber [20]), size(2) {}
	
	PhoneNumber getNumber(int i) {return arr[i];}		//returns phonenumber requested
	
	void setNumber(PhoneNumber number, int place) {
		arr[place] = number;}	//sets phone number

	void addNumber(PhoneNumber number) {					//adds number
		arr[size] = number;
		size++;
	}

	int getSize() {return size;}					//gets amount of numbers in the array

	void print() {							//prints array
		for (int i = 0; i < size; i++)
			arr[i].print();
	}
private:
	PhoneNumber *arr;
	int size;
};
