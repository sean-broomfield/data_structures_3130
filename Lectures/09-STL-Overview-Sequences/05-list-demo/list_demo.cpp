#include <list>
#include <iostream>

using namespace std;


template <typename T>
bool contains(list <T> &l, T sent) {
    list<T> hold;
    bool holder = false;
    
    while(!l.empty()) {
        T t = l.front();
        hold.push_front(t);
        
        if(hold.front() == sent) {
            holder = true;
            while(!hold.empty()) {
                l.push_front(hold.back());
                hold.pop_back();
            }
            return holder;
        } else
            l.pop_front();
    }
    
    while(!hold.empty()) {
        l.push_front(hold.back());
        hold.pop_back();
    }
    
    return holder;
}

template <typename T>
ostream &operator <<(ostream &os, list<T> &s) {
	list<T> hold;
	os << "[";
	while (!s.empty()) {
		T t = s.front();
		hold.push_front(t);
		s.pop_front();
		os << t << (!s.empty() ? ", " : "");
	}
	os << "]";
	while (!hold.empty()) {
		s.push_front(hold.back());
		hold.pop_back();
	}
	return os;
}

int main() {
	cout << boolalpha;
    
	list<int> si;
    
	for (int i = 0; i < 20; i++)
		si.push_front(i);
    
	cout << si << endl;
    
    cout << "si contains 15: " << contains(si, 15) << endl;
    cout << "si contains 23: " << contains(si, 23) << endl;
    
    
	const int ARR_SIZE = 4;
	string arr[ARR_SIZE] = {"cat", "dog", "cow", "elephant"};
    
	cout << endl;
    
	list<string> ss;
    
	for (int i = 0; i < ARR_SIZE; i++)
		ss.push_front(arr[i]);
    
	cout << ss << endl;
    
	cout << "si contains \"dog\": " << contains(ss, string("dog")) << endl;
	cout << "si contains \"muskrat\": " << contains(ss, string("muskrat")) << endl;
    
    string arr2[ARR_SIZE] = {"John", "Tim", "Ralph", "Jimmy"};
    
    cout << endl;
    
    list<string> s3;
    
    s3.push_front(arr2[2]);
    s3.push_front(arr2[1]);
    s3.push_front(arr2[3]);
    
    cout << s3 << endl;
	cout << "s3 contains \"Tim\": " << contains(s3, string("Tim")) << endl;
	cout << "s3 contains \"Joshua\": " << contains(s3, string("Joshua")) << endl;

    
	return 0;
}

