#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <fstream>
#include <iostream>

template <typename T>
void swap(T &a, T &b);

template <typename T>
T* load(const char* x, int& size);

template <typename T>
void bubbleSort(T *arr, int n) {
    bool isSorted = false;
	for (int last = n-1; last > 0 && !isSorted; last--) {
		isSorted = true;
		for (int i = 0; i < last; i++)
			if (arr[i] > arr[i+1]) {
				swap(arr[i], arr[i+1]);
				isSorted = false;
			}
	}
}


template <typename T>
void print(T *arr, int n) {
    for (int i = 0; i < n; i ++)
        std::cout << arr[i] << " ";
    std::cout << std::endl<<std::endl;
}

template <typename T>
void swap(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}

template <typename T>
T* load(const char* x, int &size) {
    std::ifstream infile;
    infile.open(x);
    T c;
    
    
    infile >> c;
    size++;
    
    T *arr = new T[40];
    int i = 0;
    
    while(infile) {
        arr[i] = c;
        i++;
        size++;
        infile >> c;
    }
    size--;
    
    infile.close();

    return arr;
}

#endif

/*
 
 int* load(const char* x, int &size) {
    
    std::ifstream infile;
    infile.open(x);
    int c;
    
    infile >> c;
    size++;
    //std::cout << c << std::endl;
    
    int *a = new int[10];
    int i = 0;
    
    while(infile) {
        a[i] = c;
        std::cout << a[i] << " ";
        i++;
        size++;
        infile >> c;
    }
    std::cout << "Size " << size << std::endl;
    std::cout << std::endl;
    
    infile.close();
    
    return a;
} 

 */

/*
 
 template <typename T>
T load(int x) {
    std::fstream infile;
    
    infile.open("input.txt");
        T arr[10];
    while(infile) {
        infile >> arr[0];
    }
    infile.close();
    
    return arr;
}

*/

/*template <typename T>
 T* load(const char* x, int &size) {
 
 std::ifstream infile;
 infile.open(x);
 T c;
 
 
 infile >> c;
 size++;
 //std::cout << c << std::endl;
 
 T *arr = new T[size];
 int i = 0;
 
 while(infile) {
 arr[i] = c;
 std::cout << arr[i] << " ";
 i++;
 size++;
 infile >> c;
 }
 size--;
 std::cout << "Size " << size << std::endl;
 std::cout << std::endl;
 
 infile.close();
 
 delete[] arr;
 
 return arr;
 }
 
 #endif
*/
