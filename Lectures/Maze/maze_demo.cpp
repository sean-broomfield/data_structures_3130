#include <iostream>
#include <vector>
#include "maze.h"
#include <string>

using namespace std;

int main() {
    
    string filename;
    
    cout << "Enter in name of the file." << endl;
    cin >> filename;
    cout << endl;
    
    Maze maze = load(filename);
    
    cout << maze << endl;
    
    cout << "Maze is possible to solve if 1: " << maze.solve() << endl << endl;
    
    cout << "Printing solution of maze." << endl;
    
    maze.print();
    
    return 0;
}