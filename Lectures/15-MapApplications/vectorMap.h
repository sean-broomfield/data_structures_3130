#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

template <typename T1, typename T2>
struct Pair {
	friend ostream &operator <<(ostream &os, const Pair<T1, T2> pair) {
			os << "[ \"" <<  pair.first  << "\" : " << pair.second << " ]";
			return os;
		}
		Pair(const T1 &first, const T2 &second) {
		this->first = first;
		this->second = second;
	}
	T1 first;
	T2 second;
};

template< typename T1, typename T2 >
class VectorMap {
	friend ostream &operator <<(ostream &os,const VectorMap<T1, T2> vm){
		os << "{";
		bool isFirstElement = true;
		for (typename vector<Pair<T1, T2> >::const_iterator iter = vm.v.begin(); iter != vm.v.end(); iter++)
			os << (isFirstElement ? isFirstElement = false, "" : " , ") << *iter;
		os << "}";
		return os;	
	}
public:
	 T2 &operator [](T1 key){
		
		for (typename vector<Pair<T1, T2> >::iterator iter = v.begin(); iter != v.end(); iter++)
			if (iter->first == key)
				return iter->second;

		v.push_back(Pair<T1, T2>(key, T2()));
		return v.back().second;	
		
}
	T2 find(T1 key){ 
		for (typename vector<Pair<T1, T2> >::iterator iter = v.begin(); iter != v.end(); iter++)
                         if (iter->first == key)
                                  return iter->second;
		return 0;
	}

	bool empty() {return v.size()==0;}
	int size() {return v.size();}
	void clear() {return v.clear();}
private:
    	vector<Pair<T1, T2> > v;
};

