#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
struct Node {
	friend std::ostream &operator <<(std::ostream &os, const Node<T> &node) {
		os << '[' << node.data << " | #" << node.next << ']';
		return os;
	}
	Node(const T &data, Node<T> *next=0) : data(data), next(next) {}
	T data;
	Node<T> *next;
};

#endif