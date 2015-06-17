#ifndef BAG_H
#define BAG_H

class Bag {
    
private:
};
#include <iostream>

#include "linked_list.h"

using namespace std;

template <typename T>
class Bag {
	friend ostream &operator <<(ostream &os, const Bag &bag) {
		os << "{";
		os << bag.linkedList;
		os << "}";
		return os;
	}
public:
	void clear() {linkedList.clear();}
	bool contains(const T &val) { return linkedList.contains(val);}
	void add(const T &val) {linkedList.insertFront(val);}
	bool isEmpty() {return linkedList.isEmpty();}
	int getSize() {return linkedList.getSize();}
private:
	LinkedList linkedList;
};

#endif