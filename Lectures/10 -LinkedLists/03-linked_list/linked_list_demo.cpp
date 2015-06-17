#include <iostream>
#include <iomanip>

#include "linked_list.h"

using namespace std;

int main() {
	LinkedList<int> li, li2;
    
    Node<int> *p = new Node<int>(0);
    Node<int> *r = new Node<int>(0);
    Node<int> *s = new Node<int>(0);
    li.insert(r, 59);
    li.insert(p, 35);
    cout << endl << li << endl;
    cout << "Size of list is " << li.getSize() << endl << endl;
    bool value = li.isEmpty();
    cout << "Is li empty? " << value << endl;
    
    value = li2.isEmpty();
    cout << "Is li2 empty? " << value << endl;
    
    cout << "Li2 = Li" << endl;
    li2 = li;
    cout << "Printing li2" << endl;
    cout << li2 << endl;
    
    li2.insert(s, 129);
    cout << "Inserting node into li2 " << endl;
    cout << li2 << endl;
    
    int num = li2.remove(s);
    cout << "Value of node removed is " << num << endl;
    cout << li2 << endl;
    cout << "Size of li2 is " << li.getSize() << endl;
    
    value = li.remove(35);
    cout << "Removing node containing 35 from list. " << value << endl;
    cout << li << endl;
    
 	return 0;
}