#include "paren.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool paren(string rand) {
    
    stack<char> str;
    string openers = "([{<";
    string closers = ")]}>";
    
    for(int i = 0; i < rand.length(); i++) {
        if(isOpener(openers, rand[i])) {
            cout << "Opener is at position " << i << endl;
            str.push(rand[i]);
        }
        else if(isCloser(closers, rand[i])) {
            cout << "Closer is at position " << i << endl;
            if(str.empty()) {
                cout << "Empty Stack." << endl;
                return false;
            } else {
                if(matches(str.top(), rand[i])) {
                    cout << "There is a match for string " << rand << "!  " << str.top() << " " << rand[i] << endl << endl;
                    str.pop();
                    return true;
                } else {
                    cout << "There is no match for string " << rand << endl << endl;
                    return false;
                }
            }
            
        }
    }
    
    if(str.empty())
        return true;
    else
        return false;

}

bool isOpener(string &openers, char charac) {
    
    for(int i = 0; i < openers.length(); i++)
        if(charac == openers[i]) {
            cerr << "There is an opener!" << endl;
            return true;
        }
    
    cerr << "There is no opener!" << endl;
    return false;
            
    
}

bool isCloser(string &closers, char charac) {
    
    for(int i = 0; i < closers.length(); i++)
        if(charac == closers[i]) {
            cerr << "There is a closer!" << endl;
            return true;
        }
    
    cerr << "There is no closer!" << endl;
    return false;
    
}

bool matches(char charac, char charac2) {
    
    if(charac == '(' && charac2 == ')')
        return true;
    else if (charac == '[' && charac2 == ']')
        return true;
    else if (charac == '{' && charac2 == '}')
        return true;
    else if (charac == '<' && charac2 == '>')
        return true;
    else
        return false;
}
