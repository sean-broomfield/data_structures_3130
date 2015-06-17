#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool paren(string rand);
bool matches(char charac, char charac2);
bool isOpener(string &openers, char charac);
bool isCloser(string &closers, char charac);