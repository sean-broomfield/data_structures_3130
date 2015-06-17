#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>
#include "radix.h"
using namespace std;


int main() {
  
    const int MAX = 10;
    int sort[MAX];
    queue<int> arr[MAX];
    string filename;
    
    cout << "Reading from num.txt file.... " << endl << endl;
    
    ifstream infile("num.txt");
    if (!infile){
        cout << "Error no file. Exitting program." << endl;
        exit(1);
    }
    while(!infile.eof()) {
        for(int i = 0; i < MAX; i++)
            infile >> sort[i];
    }
    
    int size = 10;
        
    cout << "Unsorted Array: ";
    print(sort);
        
    radixSort(sort, size);
    
    cout << "Sorted Array: ";
    print(sort);

    return 0;
    
}



