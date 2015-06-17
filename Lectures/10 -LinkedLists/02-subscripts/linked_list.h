#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

#include "node.h"
#include "linked_list_exception.h"

using namespace std;

template <typename T>
class LinkedList;

template <typename T>
ostream &operator << (ostream &os, const LinkedList<T> &linkedList);

template <typename T>
class LinkedList {
	friend ostream &operator << <>(ostream &os, const LinkedList<T> &linkedList);
public:
	LinkedList();
	LinkedList(const LinkedList &other);
	~LinkedList();
	LinkedList &operator =(const LinkedList &rhs);
    
	void insertAfter(Node<T> *nodeP, const T &val);
	void insertFront(const T &val);
	void removeAfter(Node<T> *nodeP);
	void removeFront();
    void insertIn(Node<T> *head, const T &val);
    void remove(Node<T> *head, const T &val);
    T& get(Node<T> *head, int i);
    T set(Node<T> *head, int i, const T &val);


    
	void clear();

    
	T &front() const {return head->data;}
    
	bool contains(const T &val) const {return find(val);}
	Node<T> *find(const T &val) const {return find(head, val);}
    
	bool isEmpty() const {return !head;}
	int getSize() const {return getSize(head);}
private:
	Node<T> *copyNodes(Node<T> *head) const;
	int getSize(Node<T> *head) const;
	Node<T> *find(Node<T> *head, const T &val) const;
	Node<T> *head;
};


template <typename T>
ostream &operator <<(ostream &os, const LinkedList<T> &linkedList) {
	os << "{";
	Node<T> *p = linkedList.head;
	while (p) {
		os << p->data << (p->next ? ", " : "");
		p = p->next;
	}
	os << "}";
	return os;
}

template <typename T>
LinkedList<T>::LinkedList() : head(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &other) {head = copyNodes(other.head);}

template <typename T>
LinkedList<T>::~LinkedList() {clear();}

template <typename T>
LinkedList<T> &LinkedList<T>::operator =(const LinkedList &rhs) {
	if (this == &rhs) return *this;
	clear();
	head = copyNodes(rhs.head);
	return *this;
}

template <typename T>
void LinkedList<T>::insertAfter(Node<T> *nodeP, const T &val) {
	if (!nodeP) throw LinkedListException("Attempting to insert after NULL");
	Node<T> *newNodeP = new Node<T>(val, nodeP->next);
	nodeP->next = newNodeP;
}

template <typename T>
T& LinkedList<T>::get(Node<T> *head, int i) {
    int count = 0;
    Node<T> *hold = head, *q = 0;
    
    while(hold != 0) {
        if(count == i)
            return hold->data;
        q = hold;
        hold = hold->next;
        count++;
    }
    
        cout << "Not enough nodes in linked list. Returning the value of the last node." << endl;
    return q->data;
}

template <typename T>
T LinkedList<T>::set(Node<T> *head, int i, const T &val) {
    int count = 0;
    T value;
    Node<T> *hold = head, *q = 0;

    while(hold != 0) {
        if(count == i) {
            value = hold->data;
            hold->data = val;
            return value;
        }
        count++;
        hold = hold->next;
    }
    
    cout << "Not enough nodes in list. Returning original value given." << endl;
    return val;
}

template <typename T>
void LinkedList<T>::insertIn(Node<T> *head, const T &val) {
    Node<T> *hold = head, *q = 0;

    while(hold != 0) {
        q = hold;
        hold = hold->next;
    }
    
    if(q == 0)
        insertFront(val);
    else
        insertAfter(q, val);
    
    delete hold;
    return;
}

template <typename T>
void LinkedList<T>::remove(Node<T> *head, const T &val) {
    Node<T> *hold = head, *q = 0, *p = 0;
    
    bool value = this->contains(val);
    if(value == false){
        cout << "Value not in list." << endl;
        return;
    } else {
        while(hold != 0 && val != hold->data){
            if(q != 0)
                p = hold;
            q = head;
            hold = hold->next;
        }
            if(p == 0)
                removeFront();
            else
                removeAfter(p);
        }
    return;
}

template <typename T>
void LinkedList<T>::insertFront(const T &val) {head = new Node<T>(val, head);}

template <typename T>
void LinkedList<T>::removeAfter(Node<T> *nodeP) {
	if (!nodeP) throw LinkedListException("Attempting to remove after NULL");
	if (!nodeP->next) throw LinkedListException("Attempting to remove nonexistent node");
	Node<T> *nextNodeP = nodeP->next;
	nodeP->next = nextNodeP->next;
	delete nextNodeP;
}

template <typename T>
void LinkedList<T>::removeFront() {
	Node<T> *hold = head;
	head = head->next;
	delete hold;
}

template <typename T>
void LinkedList<T>::clear() {
	while (!isEmpty())
		removeFront();
}

template <typename T>
Node<T> *LinkedList<T>::copyNodes(Node<T> *head) const {
	if (!head) return 0;
	return new Node<T>(head->data, copyNodes(head->next));
}

template <typename T>
Node<T> *LinkedList<T>::find(Node<T> *head, const T &val) const {
	if (!head) return 0;
	if (head->data == val) return head;
	return find(head->next, val);
}

template <typename T>
int LinkedList<T>::getSize(Node<T> *head) const {return head ? getSize(head->next) + 1 : 0;}

#endif