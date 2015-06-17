#include <iostream>
#include <iomanip>

#include "linked_list.h"

using namespace std;

int main() {
	LinkedList<int> li;
    
	cout << boolalpha;
	cout << li << endl;
	cout << "lize: " << li.getSize() << endl;
	cout << "isEmpty: " << li.isEmpty() << endl;
	cout << "contains(3): " << li.contains(3) << endl;
	cout << endl;
    
	li.insertFront(3);
	cout << li << endl;
	cout << "size: " << li.getSize() << endl;
	cout << "isEmpty: " << li.isEmpty() << endl;
	cout << "contains(3): " << li.contains(3) << endl;
	cout << "contains(20): " << li.contains(20) << endl;
    cout << "contains(35): " << li.contains(35) << endl;
	cout << endl;
    
	Node<int> *p = li.find(3);
	li.insertAfter(p, 20);
	cout << li << endl;
	cout << "size: " << li.getSize() << endl;
	cout << "isEmpty: " << li.isEmpty() << endl;
	cout << "contains(3): " << li.contains(3) << endl;
	cout << "contains(20): " << li.contains(20) << endl;
	cout << "contains(17): " << li.contains(17) << endl;
	cout << endl;
    
    //INSERT FUNCTION
    Node<int> *pq = li.find(3);
    li.insertIn(pq, 35);
    cout << "size: " << li.getSize() << endl;
	cout << "isEmpty: " << li.isEmpty() << endl;
	cout << "contains(3): " << li.contains(3) << endl;
	cout << "contains(20): " << li.contains(20) << endl;
	cout << "contains(17): " << li.contains(17) << endl;
    cout << "contains(35): " << li.contains(35) << endl;
    cout << "li: " << li << endl;
    cout << endl;
    
    //GET FUNCTION
    int nodecount = li.get(p,2);
    cout << "Value of node 2 is " << nodecount << endl << endl;
    cout << li << endl;
    
    //SET FUNCTION
    int nodevalue = li.set(p, 2, 433);
    cout << "Previous value of node 2 after set call is " << nodevalue << endl << endl;
    cout << "li: " << li << endl;
    
	LinkedList<int> li2 = li;
	cout << "After li2 declaration and copy constructor: " << endl;
	cout << "li: " << li << endl;
	cout << "li2: " << li2 << endl;
	cout << endl;
    
	LinkedList<int> li3;
	cout << "After li3 declaration: " << endl;
	cout << "li3: " << li3 << endl;
	li3 = li;
	cout << "After li3 = li assignment: " << endl;
	cout << "li: " << li << endl;
	cout << "li3: " << li3 << endl;
	cout << endl;
    
	li.insertFront(17);
	cout << li << endl;
	cout << "size: " << li.getSize() << endl;
	cout << "isEmpty: " << li.isEmpty() << endl;
	cout << "contains(3): " << li.contains(3) << endl;
	cout << "contains(20): " << li.contains(20) << endl;
	cout << "contains(17): " << li.contains(17) << endl;
	cout << "contains(57): " << li.contains(57) << endl;
	cout << endl;
    
	cout << "li: " << li << endl;
	cout << "li2: " << li2 << endl;
	cout << "li3: " << li3 << endl;
    
    LinkedList<int> car(li);
    cout << "Car list is: " << car << endl;
    
    //REMOVE FUNCTION
    cout << "Using remove function " << endl;
	li.remove(p, 433);
    cout << "Removed front of li" << endl;
    cout << "li: " << li << endl;
    li.removeFront();
    cout << "Removed front again of li" << endl;
    cout << "Car: " << car << endl;
    cout << "li: " << li << endl << endl;
    
	return 0;
}
