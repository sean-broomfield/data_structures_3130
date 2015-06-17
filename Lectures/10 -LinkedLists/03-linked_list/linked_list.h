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
    ~LinkedList();
    void insert(Node<T> *p, const T &val);
    T remove(Node<T> *p);
	LinkedList &operator =(const LinkedList &rhs);
   
    
	Node<T> contains(const T &val);
    bool remove(const T &val);
    
    void clear();

    
	bool isEmpty() const {return !head;}
    int getSize() const;
private:
	Node<T> *head;
    int size;
};

template <typename T>
LinkedList<T> &LinkedList<T>::operator =(const LinkedList &rhs) {
	if (this == &rhs) return *this;
	clear();
    Node<T> *hold = rhs.head, *q = 0;
    while(hold != q) {
        Node<T> *p = new Node<T>(0);
        this->insert(p, hold->data);
        q = rhs.head;
        hold = hold->next;
    }
	return *this;
}


template <typename T>
LinkedList<T>::~LinkedList() {clear();}

template <typename T>
void LinkedList<T>::clear() {
    Node<T> *q = head;
    
    while(!isEmpty()) {
        remove(q->next);
    }
    head = 0;
}

template <typename T>
int LinkedList<T>::getSize() const {
    Node<T> *hold = head, *q = 0;
    int count = 0;
    
    if(head == 0) {
        return 0;
    } else {
        while(q != hold) {
            hold = hold->next;
            q = head;
            count++;
        }
        return count;
    }
}

template <typename T>
LinkedList<T>::LinkedList() : head(0), size(0) {}

template <typename T>
void LinkedList<T>::insert(Node<T> *p, const T &val) {
    if(head != 0) {
        Node<T> *q = head->next, *r = head->next;
        while(q != head) {
            r = q;
            q = q->next;
        }
        p->next = q;
        p->prev = r;
        p->data = val;
        r->next = p;
        q->prev = p;
    } else if (head == 0) {
        p->data = val;
        p->next = p;
        p->prev = p;
        head = p;
    }
}

template <typename T>
T LinkedList<T>::remove(Node<T> *p) {
    Node<T> *hold = p, *q = p->next, *r = p->prev;
    if(q != p && r != p) {
        q->prev = p->prev;
        r->next = p->next;
        T value = p->data;
        delete p;
        return value;
    } else {
        T value = p->data;
        delete p;
        head = 0;
        return value;
    }
}

template <typename T>
bool LinkedList<T>::remove(const T &val) {
    Node<T> *p = head, *q = 0, *r = 0;
    
    if(head != 0) {
        while(p != q && p->data != val) {
            p = p->next;
            q = head;
        }
    
        if(p->data == val){
            r = p->prev;
            q = p->next;
            if(p == r && p == q) {
                head = 0;
                delete p;
                cout << "Removed." << endl;
                return true;
            } else {
                r->next = q;
                q->prev = r;
                cout << "Removed." << endl;
                return true;
            }
        } else {
            cout << "Did not exist." << endl;
            return false;
        }
    } else {
        cout << "Didn't exist." << endl;
        return false;
    }
}

template <typename T>
ostream &operator <<(ostream &os, const LinkedList<T> &linkedList) {
	os << "{";
	Node<T> *hold = linkedList.head, *q = 0;
	while (hold != q) {
        q = linkedList.head;
		os << hold->data << ((hold->next == q) ? "" : ",");
		hold = hold->next;
	}
	os << "}" << endl;
	return os;
}


#endif