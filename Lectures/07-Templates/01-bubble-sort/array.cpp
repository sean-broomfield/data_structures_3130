#include <iostream>

#include "array.h"
#include "array_exception.h"

using namespace std;

#define DEBUG true

template <typename T>
ostream &operator << (ostream &os, const Array<T> &array) {
	os << "{";
	for (int i = 0; i < array.size; i++)
		os << array.arr[i] << (i < array.size-1 ? ", " : "");
	os << "}";
	return os;
}

template <typename T>
Array<T>::Array(const Array<T> &other) : arr(new int[other.capacity]), capacity(other.capacity), size(other.size) {
	for (int i = 0; i < size; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator =(const Array<T> &rhs) {
	if (this == &rhs) return *this;
	delete arr;
	size = rhs.size;
	capacity = rhs.capacity;
	arr = new T[capacity];  // this was fixed; it was originaloly a local declaration
	for (int i = 0; i < size; i++)
		arr[i] = rhs.arr[i];
	return *this;
}

template <typename T>
int &Array<T>::operator [](int index) {
	if (index < 0 || index >= size) throw ArrayException("Index out of bounds");
	return arr[index];
}
template <typename T>
const int &Array<T>::operator [](int index) const {
	if (index < 0 || index >= size) throw ArrayException("Index out of bounds");
	return arr[index];
}

template <typename T>
Array<T> &Array<T>::operator +=(T val) {
	checkCapacity();
	arr[size] = val;
	size++;
	return *this;
}

template <typename T>
void Array<T>::checkCapacity() {
	if (size < capacity) return;
    
	capacity *= 2;
	int *newArr = new T[capacity];
	for (int i = 0; i < size; i++)
		newArr[i] = arr[i];
	delete [] arr;
	arr = newArr;
	if (DEBUG) cerr << "Increased array capacity to " << capacity << endl;
}
