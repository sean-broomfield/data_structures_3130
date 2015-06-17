#include "radix.h"
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

int exponent(int power) {
    int ans = 1;
    int count = 0;
    
    if(power == 0)
        return ans;
    else
        while(count < power) {
            ans = ans * 10;
            count++;
        }
    
    return ans;
}

void radixSort(int arr[], int size) {
    queue<int> buckets[10];
    int temp;
    int m = 0;
    
    for(int i = 0; i < 5; i++){
        queue<int> buckets[10];
        //PUSHES INTO BIN
        for(int j = 0; j < size; j++) {
            temp = (arr[j]/exponent(i)) %10;
            buckets[temp].push((arr[j]));
        }
        //RELOADS INTO ARRAY
        for(int l = 0; l < 10; l++) {
            while(!buckets[l].empty()){
                arr[m] = buckets[l].front();
                buckets[l].pop();
                m++;
            }
        }
        
        m = 0;
        
    }
}

void print(int arr[]) {
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    
    cout << endl << endl;
}