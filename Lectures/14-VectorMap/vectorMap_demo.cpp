#include <iostream>
#include <utility>
#include <vector>
#include <sstream> 
#include <string>
#include "vectormap.h"

using namespace std;

int main() {
    
    //use boolalpha to prints true or false for booleans
    cout << boolalpha;
    
    
	VectorMap<string, int> Vmap;
    

    cout << "Values in Map: " << endl;
    
    Vmap["Dog"] = 1;
	Vmap["cow"] = Vmap["Dog"] + 1;
	Vmap["Dog"]++;
    Vmap["cat"] = 23;

    cout << Vmap << endl;
	
    cout << " The mumber of elements in map is: " <<  Vmap.sizeOf() << endl;
    
    cout << "Clearing Vector Map..." << endl << endl;
    
	Vmap.clear();
    
    cout << "Size of VectorMap is now: " << Vmap.sizeOf() << endl << endl;
 	cout << "Is VectorMap now clear? " << Vmap.empty() << endl << endl;
    
	cout << "Testing element adding with for loop" << endl;
	for (int i = 0; i < 10; i++) {
		ostringstream oss;
		oss << "string" << i;
		Vmap[oss.str()] = i;
	}
    cout << "Printing new VectorMap..."<< endl << endl;
	cout << Vmap << endl;
    
	return 0;
}
