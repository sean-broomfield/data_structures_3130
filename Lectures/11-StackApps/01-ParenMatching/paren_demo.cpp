#include <iostream>
#include <stack>
#include <string>
#include "paren.h"

using namespace std;

int main() {
    
    string rand = "(Cars)";
    string rand2 = "<c)";
    
    cout << "String is: " << rand << endl;
    
    paren(rand);
    
    cout << "String is: " << rand2 << endl;
    paren(rand2);
    

    return 0;
    
    
}