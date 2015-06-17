#ifndef CONCORDANCE_H
#define CONCORDANCE_H

#include <iostream>
#include <fstream>
#include <string>
#include "vectorMap.h"

class Concordance {

	friend std::ostream &operator<< (std::ostream &os, const Concordance &concordance){
		os << concordance.m;
		return os;	
	}
    
public:	
	void add(std::string file_name);
	int operator [](std::string word);
    
private:

	VectorMap<std::string, int> m;
};

#endif
