#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array {
	friend std::ostream &operator << <>(std::ostream &os, const Array<T> &array);
public:
	Array(int capacity=100) : arr(new T [capacity]), capacity(capacity), size(0) {}
	Array(const Array &other);
	~Array() {delete [] arr;}
	Array & operator = (const Array &rhs);
	int &operator [] (int index);
	const int &operator [] (int index) const;
	Array &operator +=(T val);
	int getSize() {return size;}
private:
	void checkCapacity();
	T *arr;
	int capacity;
	int size;
};

#endif
