#include <iostream>
#include <deque>

using namespace std;

template <typename T>
ostream &operator <<(ostream &os, deque<T> &q) {
    deque<T> hold;
    os << "[";
    while(!q.empty()) {
        T t = q.front();
        hold.push_front(t);
        q.pop_front();
        os << t << (!q.empty() ? ", " : "");
    }
    os << "]";
    while (!hold.empty()) {
        q.push_front(hold.back());
        hold.pop_back();
    }
    return os;
}

template <typename T>
bool contains(deque<T> &q, T sent) {
    deque<T> hold;
    bool holder = false;
    
    while(!q.empty()) {
        T t = q.front();
        hold.push_front(t);
        
        if(hold.front() == sent) {
            holder = true;
            while(!hold.empty()) {
                q.push_back(hold.back());
                hold.pop_back();
            }
            return holder;
        } else
            q.pop_front();
    
}
}


int main() {
	cout << boolalpha;
    
	deque<int> si;
    
	for (int i = 0; i < 20; i++)
		si.push_front(i);
    
	cout << si << endl;
    
    cout << "si contains 15: " << contains(si, 15) << endl;
    cout << "si contains 23: " << contains(si, 23) << endl;
    
    
	const int ARR_SIZE = 4;
	string arr[ARR_SIZE] = {"cat", "dog", "cow", "elephant"};
    
	cout << endl;
    
	deque<string> ss;
    
	for (int i = 0; i < ARR_SIZE; i++)
		ss.push_front(arr[i]);
    
	cout << ss << endl;
    
	cout << "si contains \"dog\": " << contains(ss, string("dog")) << endl;
	cout << "si contains \"muskrat\": " << contains(ss, string("muskrat")) << endl;
    
    
    string arr2[ARR_SIZE] = {"John", "Tim", "Ralph", "Jimmy"};
    
    cout << endl;
    
    deque<string> s3;
    
    s3.push_front(arr2[2]);
    s3.push_front(arr2[1]);
    s3.push_front(arr2[3]);
    
    cout << s3 << endl;
	cout << "s3 contains \"Tim\": " << contains(s3, string("Tim")) << endl;
	cout << "s3 contains \"Joshua\": " << contains(s3, string("Joshua")) << endl;

    
	return 0;
}