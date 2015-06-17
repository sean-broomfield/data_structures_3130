#include "bubble_sort.h"
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "clock_utils.h"

using namespace std;

int main() {


//PRIORITY QUEUE

	int n;
	int count = 0;
	//cin >> n;
	
	n = 10;

while (count != 3) {

	//cout << "Priority Queue: " << endl;

	int *a = new int[n];

	for (int i = 0; i < n; i++)
	//	cin >> a[i];
		a[i] = rand();

	priority_queue<int> pq;
	
	clock_t start_time = clock();

	for (int i = 0; i < n; i++)
		pq.push(a[i]);

	for (int i = n-1; i >= 0; i--) {
		a[i] = pq.top();
		pq.pop();
	}

	clock_t end_time = clock();
	clock_t duration = end_time - start_time;

//	for (int i =0; i < n; i++)
//		cout << a[i] << " ";

	cout << endl << "Priority Queue duration for array an of " << n << ": " << hours(duration) << ":" << minutes(duration) << ":" << seconds(duration)<< ":"  << ticks(duration);
	
	
//BUBBLE SORT
	
//	cout << "Bubble Sort: " << endl;

//	int *b = new int[n];

//	for (int i = 0; i < n; i++)
//		b[i] = rand();

	clock_t start_time1 = clock();
	
	bubbleSort(a, n);

	clock_t end_time1 = clock();
	duration = end_time1 - start_time1;	
	
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";

	cout << endl << "Bubble sort duration for an array of " << n << ": " << hours(duration) << ":" << minutes(duration) << ":" << seconds(duration) << ":" << ticks(duration);


//ALGORITHM
//	int *c = new int[n];

//	for (int i = 0; i < n; i++)
//		c[i] = rand();
	
//	cout << "Built-In Sort: ";
	start_time = clock();	

	sort(a, a+n);

	end_time = clock();

	duration = end_time - start_time;
	
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";	

	cout << endl << "Built-in sort duration for an array of " << n << ": " << hours(duration) << ":" << minutes(duration) << ":" << seconds(duration) << ":" << ticks(duration) << endl;
	count++;
	
	if (n == 10)
		n = 1000;
	else if (n == 1000)
		n = 1000000;

	}

	return 0;
}
