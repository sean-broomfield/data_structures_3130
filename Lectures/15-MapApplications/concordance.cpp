#include <iostream>
#include "concordance.h"
#include <algorithm>

using namespace std;

void Concordance::add(std::string file_name){
	ifstream ifs (file_name.c_str());
	if (!ifs) throw "No such file found";

	std::string word;
	ifs >> word;
	while (ifs){
		m[word]++;
		ifs >> word;
	}
}


int Concordance::operator [](std::string word) {
	return m.find(word);
}
