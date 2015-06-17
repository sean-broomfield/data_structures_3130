#include <iostream>

#include "bubble_sort.h"

using namespace std;

void swap(int &a, int &b);

void bubbleSort(int arr[], int n) {
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

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
