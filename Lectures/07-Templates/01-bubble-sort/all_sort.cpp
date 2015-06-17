#include "bubble_sort.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){

	int intSize = 0, stringSize = 0, doubleSize = 0;
    int *value;
    string *stringstr;
    double *doubles;

	cout << endl  << endl;

/*	int integers[n];
	double doubles[n];
	string strings[10];

	for (int i = 0; i < n; i++)
		integers[i] = rand();
	for (int i = 0; i < n; i++)
		doubles[i] = rand();

	bubbleSort(integers, n);
	cout << "Integers : " << endl;
	print(integers, n);
	cout << endl;

	bubbleSort(doubles, n);
	cout << "Doubles: " << endl;
	print(doubles, n);
	cout << endl;
   	
	int *value = load(pick, size);
	cout << "Value " << value[0] << " " << value[1] << " " << value[2]<< endl;
	cout << "Size is " << size << endl; 
	cout << pick<< endl;

*/

	cout << "Integers Before Sort: " << endl;
	value = load<int>("integers.txt", intSize);
	print(value, intSize);
	bubbleSort(value, intSize);
	cout << "Integers After Sort: " << endl;
	print(value, intSize);


	
	int *newArr = new int[intSize];
	for(int i = 0; i < intSize; i++)
		newArr[i] = value[i];
	
	delete [] value;
	value = newArr;

	cout << "Doubles before sort: " << endl;
	doubles = load<double>("doubles.txt", doubleSize);
	print(doubles, doubleSize);
	cout << "Doubles after sort: " << endl;
	bubbleSort(doubles, doubleSize);
	print(doubles, doubleSize);

	double *dubArr = new double[doubleSize];
	for(int i = 0; i < doubleSize; i++)
		dubArr[i] = doubles[i];

	delete [] doubles;
	doubles = dubArr;

	cout << "Strings before sort: " << endl;
	stringstr = load<string>("strings.txt", stringSize);
	print(stringstr, stringSize);
	bubbleSort(stringstr, stringSize);
	cout << "Strings after sort: " << endl;
	print(stringstr, stringSize);	
	return 0;
}	

