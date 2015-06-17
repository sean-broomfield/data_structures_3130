#include <iostream>
#include <stack>

using namespace std;

template <typename T>
bool contains(stack<T> &s,  T sent) {
    stack<T> hold;
    bool holder = false;
    
    while(!s.empty()) {
        T t = s.top();
        hold.push(t);
        
        if(hold.top() == sent) {
            holder = true;
            while(!hold.empty()) {
                s.push(hold.top());
                hold.pop();
            }
            return holder;
        } else
            s.pop();
    }
    
    while(!hold.empty()) {
        s.push(hold.top());
        hold.pop();
    }
    
    return holder;
}

template <typename T>
ostream &operator <<(ostream &os, stack<T> &s) {
	stack<T> hold;
	os << "[";
	while (!s.empty()) {
		T t = s.top();
		hold.push(t);
		s.pop();
		os << t << (!s.empty() ? ", " : "");
	}
	os << "]";
	while (!hold.empty()) {
		s.push(hold.top());
		hold.pop();
	}
	return os;
}

int main() {
	cout << boolalpha;
    
	stack<int> si;
    
	for (int i = 0; i < 20; i++)
		si.push(i);
    
	cout << si << endl;
    
    cout << "si contains 15: " << contains(si, 15) << endl;
    cout << "si contains 23: " << contains(si, 23) << endl;
    

	const int ARR_SIZE = 4;
	string arr[ARR_SIZE] = {"cat", "dog", "cow", "elephant"};
    
	cout << endl;
    
	stack<string> ss;
    
	for (int i = 0; i < ARR_SIZE; i++)
		ss.push(arr[i]);
    
	cout << ss << endl;
    
	cout << "si contains \"dog\": " << contains(ss, string("dog")) << endl;
	cout << "si contains \"muskrat\": " << contains(ss, string("muskrat")) << endl;
    
    string arr2[ARR_SIZE] = {"John", "Tim", "Ralph", "Jimmy"};
    
    cout << endl;
    
    stack<string> s3;
    
    s3.push(arr2[2]);
    s3.push(arr2[1]);
    s3.push(arr2[3]);
    
    cout << s3 << endl;
	cout << "s3 contains \"Tim\": " << contains(s3, string("Tim")) << endl;
	cout << "s3 contains \"Joshua\": " << contains(s3, string("Joshua")) << endl;
    
	return 0;
}

