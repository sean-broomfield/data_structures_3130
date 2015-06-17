#include <iostream>
#include <deque>

using namespace std;


template <typename T>
ostream &operator <<(ostream &os, deque<T> &q) {
    deque<T> hold;
    os << "[";
    for(typename deque<T>::const_iterator iter = q.begin(); iter != q.end(); iter++)
        os << *iter << (iter+1 != q.end() ? ", " : "");
    os << "]";
    return os;
}

template <typename T>
bool contains(deque<T> &q, T sent) {
    bool holder = false;
    
    for(typename deque<T>::const_iterator iter = q.begin(); iter != q.end(); iter++) {
        if (*iter == sent) {
            holder = true;
            return holder;
        }
    }
    return holder;
}


int main() {
	cout << boolalpha;
    
	deque<int> si;
    
	for (int i = 0; i < 20; i++)
		si.push_front(i);
    
	cout << si << endl << endl;
    
    cout << "Reverse Print: " << endl << "[";
    for(deque<int>::reverse_iterator riter = si.rbegin(); riter != si.rend(); riter++)
        cout << *riter << (riter+1 != si.rend() ? ", ": "");
    cout << "]" << endl << endl;
    
    cout << "si contains 15: " << contains(si, 15) << endl;
    cout << "si contains 23: " << contains(si, 23) << endl;
    
    
	const int ARR_SIZE = 4;
	string arr[ARR_SIZE] = {"cat", "dog", "cow", "elephant"};
    
	cout << endl;
    
	deque<string> ss;
    
	for (int i = 0; i < ARR_SIZE; i++)
		ss.push_front(arr[i]);
    
	cout << ss << endl << endl;
    
    cout << "Reverse Print: " << endl << "[";
    for(deque<string>::reverse_iterator riter = ss.rbegin(); riter != ss.rend(); riter++)
        cout << *riter << (riter+1 != ss.rend() ? ", ": "");
    cout << "]" << endl << endl;
    
	cout << "si contains \"dog\": " << contains(ss, string("dog")) << endl;
	cout << "si contains \"muskrat\": " << contains(ss, string("muskrat")) << endl;
    
    
    string arr2[ARR_SIZE] = {"John", "Tim", "Ralph", "Jimmy"};
    
    cout << endl;
    
    deque<string> s3;
    
    s3.push_front(arr2[2]);
    s3.push_front(arr2[1]);
    s3.push_front(arr2[3]);
    
    cout << s3 << endl << endl;
    
    cout << "Reverse Print: " << endl << "[";
    for(deque<string>::reverse_iterator riter = s3.rbegin(); riter != s3.rend(); riter++)
        cout << *riter << (riter+1 != s3.rend() ? ", ": "");
    cout << "]" << endl << endl;
    
	cout << "s3 contains \"Tim\": " << contains(s3, string("Tim")) << endl;
	cout << "s3 contains \"Joshua\": " << contains(s3, string("Joshua")) << endl;

    
	return 0;
}