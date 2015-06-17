#include <list>
#include <iostream>

using namespace std;


template <typename T>
bool contains(list <T> &l, T sent) {
    bool value = false;
    
    for(typename list<T>::const_iterator iter = l.begin(); iter != l.end(); iter++) {
        if(*iter == sent) {
            value = true;
            return value;
        }
    }
    
    return value;
}

template <typename T>
ostream &operator <<(ostream &os, list<T> &s) {

    //special case is int. try bool.
    bool value = true;
    os << "[";
    for(typename list<T>::const_iterator iter = s.begin(); iter != s.end(); iter++){
        os << (value ? (value = false, "") : ", ") << *iter;
    }
    os << "]";
    return os;
}

int main() {
	cout << boolalpha;
    
	list<int> si;
    
	for (int i = 0; i < 20; i++)
		si.push_front(i);
    
	cout << si << endl << endl;
    
    bool value = true;
    cout << "Reverse Print: " << endl << "[";
    
    for(list<int>::reverse_iterator riter = si.rbegin(); riter != si.rend(); riter++)
        cout << (value ? (value = false,""):", ") << *riter;
    cout << "]" << endl << endl;
    
    cout << "si contains 15: " << contains(si, 15) << endl;
    cout << "si contains 23: " << contains(si, 23) << endl;
    
    
	const int ARR_SIZE = 4;
	string arr[ARR_SIZE] = {"cat", "dog", "cow", "elephant"};
    
	cout << endl;
    
	list<string> ss;
    
	for (int i = 0; i < ARR_SIZE; i++)
		ss.push_front(arr[i]);
    
	cout << ss << endl << endl;
    
    value = true;
    cout << "Reverse Print: " << endl << "[";
    
    for(list<string>::reverse_iterator riter = ss.rbegin(); riter != ss.rend(); riter++)
        cout << (value ? (value = false,""):", ") << *riter;
    cout << "]" << endl << endl;
    
	cout << "si contains \"dog\": " << contains(ss, string("dog")) << endl;
	cout << "si contains \"muskrat\": " << contains(ss, string("muskrat")) << endl;
    
    string arr2[ARR_SIZE] = {"John", "Tim", "Ralph", "Jimmy"};
    
    cout << endl;
    
    list<string> s3;
    
    s3.push_front(arr2[2]);
    s3.push_front(arr2[1]);
    s3.push_front(arr2[3]);
    
    cout << s3 << endl << endl;
    
    value = true;
    cout << "Reverse Print: " << endl << "[";
    
    for(list<string>::reverse_iterator riter = s3.rbegin(); riter != s3.rend(); riter++)
        cout << (value ? (value = false,""):", ") << *riter;
    cout << "]" << endl << endl;
    
	cout << "s3 contains \"Tim\": " << contains(s3, string("Tim")) << endl;
	cout << "s3 contains \"Joshua\": " << contains(s3, string("Joshua")) << endl;

    
	return 0;
}

