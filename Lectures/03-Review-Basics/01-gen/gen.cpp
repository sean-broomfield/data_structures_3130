#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << argv[0] << ": <how_many>" << endl;
        exit(1);
    }
    
    int range = atoi(argv[2]);
    
    int n = atoi(argv[1]);
    cout << n << endl << endl;
    for (int i = 0; i < n; i++)
        cout << rand() % range << " ";
}