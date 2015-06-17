#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include "maze.h"
using namespace std;


//OVERLOADED <<
ostream &operator <<(std::ostream &os, const Maze &maze) {
    cout << "+";
    int count = 0;
    
/*    while(count != maze.length()){
        cout << "-";
        count++;
    }
*/
    
    while(count != maze.width()) {
        cout << "-";
        count++;
//        cout << "+" << endl;
    }
    cout << "+" << endl;
    
// printBarriers();
    
    int counter = 0;
    
    while (counter != maze.height()){
        cout << "|";
        for(int i = 0; i < maze.width(); i++){
            if(maze.spec[counter][i] == true){
                if((counter == maze.start.x) && (i == maze.start.y))            //CHECKS TO SEE IF ITS THE STARTING POSITION
                    cout << "S";
                else if((counter == maze.finish.x) && (i == maze.finish.y))     //CHECKS TFOR FINSIH POSITION
                    cout << "F";
                else
                    cout << "*";                                                //PRINTS PATHS
            }
            
            if(maze.spec[counter][i] == false)
                cout << " ";
        }
    
        cout << "|" << endl;
        counter++;
    }
    
    //printBarriers();
    
    cout << "+";
    int count1 = 0;
    while (count1 != maze.width()) {
        cout << "-";
        count1++;
    }
    
    cout << "+" << endl;
    
    return os;
    
}

Maze load(std::string file) {
    ifstream infile(file.c_str());
    if (!infile){
        cout << "Error no file. Exitting program." << endl;
        exit(1);
    }

    string sent;
    Maze maze;
	int xpos = 0, mazeSize = 0;
    
    
	while(!infile.eof()){
        
		getline(infile, sent);
	 	if (xpos == 0)
        mazeSize = sent.length();
        
		if (sent[0] == '+' || sent[0] == '|'){
			if (sent.length() != mazeSize) throw "Column sizes are wrong";              //CHECKS FOR MATCHING COLUMNS
        }
        
        if(sent[0] == '|') {
            vector<bool> rows;
            for(int x = 1; x < mazeSize-2; x++) {
                
                if(sent[x] == 'S') {                                            //SETS STARTING POSITION
                    maze.start = Location(xpos-1, x-1);                         //SETS MAZE STARTING POSITION TO THIS LOCATION
                    rows.push_back(true);
                }
                
                
                if(sent[x] == 'F'){                                             //SETS FINISH POSITION
                    maze.finish = Location(xpos-1, x-1);
                    rows.push_back(true);
                }
                
                
                if(sent[x] == ' ')
                    rows.push_back(false);
                else if (sent[x] == '*')                                        //CREATES PATHS
                    rows.push_back(true);
                
                
            }
            maze.spec.push_back(rows);
        } xpos++;
    }
    cout << "Maze Loaded" << endl;
    return maze;
}


//BARRIERS
void Maze::printBarriers() {
    stringstream os;
    int count = 0;
    
    os << "+";
    
    while(count != width()) {
        os << "-";
        count++;                                        //PRINTS - TO WIDTH
    }
    
    os << "+" << endl;
    cout << os.str();
}

//COPY CONSTRUCTOR
Maze::Maze(const Maze &maze) {
    this->start = maze.start;
    this->finish = maze.finish;
    this->spec = maze.spec;
}

//CHECKS FOR PATH
bool Maze::isPath(const Location &location) {
    for(int i = 0; i < path.size(); i++)
        if(path[i] == location)
            return true;
    return false;
}

bool Maze::solve() {
    vector<vector <bool> >exPath = spec;
    stack<Location> place;
    
    place.push(start);
    
    while(!place.empty()) {
        current = place.top();
        path.push_back(current);
        if(current == finish)
            return true;
        
        //CHECKS TO SEE IF PATH IS VALID AND MAKES SURE IT DOESNT GO PAST BARRIERS
        if(current.x > 0 && exPath[current.x-1][current.y] == true) {
            exPath[current.x][current.y] = false;
            current = Location(current.x-1, current.y);
            place.push(current);
        }
        
        else if (current.y < width()-1 && exPath[current.x][current.y+1] == true) {
            exPath[current.x][current.y] = false;
            current = Location(current.x, current.y+1);
            place.push(current);
        }
        
        else if (current.x < height()-1 && exPath[current.x+1][current.y] == true){
            exPath[current.x][current.y] = false;
            current = Location(current.x+1,current.y);
            place.push(current);
        }
        
        else if (current.y > 0 && exPath[current.x][current.y-1] == true){
            exPath[current.x][current.y] = false;
            current = Location(current.x,current.y-1);
            place.push(current);
        }
        
        else {
            exPath[current.x][current.y] = false;
            place.pop();
        }
        
    }
    
    return false;
}

void Maze::print() {
    
    bool value = solve();
    
    if(value == true) {
        printBarriers();
        
        int count = 0;
        
        while(count != height()) {
            cout << "|";
            for (int i = 0; i < width(); i++) {
                if(spec[count][i] == true) {
                    if (Location(count,i) == start) {
                        cout << "S";
                    } else if (Location (count, i) == finish) {
                        cout << "F" << endl;
                    } else if (isPath(Location(count, i))) {                //IF PATH IS TRUE PRINT o FOR SOLUTION
                        cout << "o";
                    } else
                        cout <<"*";
                    }
                if(spec[count][i] == false)
                    cout << " ";
                    }
            cout << "|" << endl;
            count ++;

            //cout << *this << endl;                    //prints after each step
        }
        printBarriers();
    }
}


    
