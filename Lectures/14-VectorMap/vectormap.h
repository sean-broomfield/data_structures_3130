#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

template <typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;
    
    //Printer
    friend ostream &operator <<(ostream &os, const Pair<T1, T2> pair) {
        os << "[ " << pair.first << ": " << pair.second << "] ";
        return os;
    }
    
    //Gives values
    Pair(const T1 &first, const T2 &second) {
        this->first = first;
        this->second = second;
    }
    
};

template <typename T1, typename T2>
class VectorMap {
   
    
    friend ostream &operator <<(ostream &os, const VectorMap<T1, T2> vMap) {
        os << "{";
        bool value = true;
        for(typename vector<Pair<T1, T2> >::const_iterator iter = vMap.vect.begin(); iter != vMap.vect.end(); iter++)
            os << (value ? value = false, "" : ", ") << *iter;
        os << "}";
        return os;
    }
    
private:
    vector<Pair<T1, T2> > vect;

public:
    int sizeOf() {return vect.size();}
    void clear() {return vect.clear();}
    bool empty() {
        if (vect.size() == 0)
            return true;
        return false;
    }
    
    T2 find(T1 key) {
        for(typename vector<Pair<T1, T2> >::const_iterator iter = vect.begin(); iter != vect.end(); iter++) {
            if(iter->first == key)              //searches for match with key
                return iter->second;            //returns second
        }
    }
    
    T2 &operator [](T1 key){
        for(typename vector<Pair<T1, T2> >::iterator iter = vect.begin(); iter != vect.end(); iter++) {
            if(iter->first == key)              //searches for match with key
                return iter->second;            //returns second
        }
        
        vect.push_back(Pair<T1, T2>(key, T2()));            //If not found adds key in
        return vect.back().second;                          //returns newly added
    }
    
    
};