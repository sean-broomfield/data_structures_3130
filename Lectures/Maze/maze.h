#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>

struct Location  {
	friend std::ostream &operator <<(std::ostream &os, const Location &location) {
		os << "(" << location.x << ", " << location.y << ")";
		return os;
	}
    
    
	bool operator ==(const Location &rhs) const {return x == rhs.x && y == rhs.y;}
	bool operator !=(const Location &rhs) const {return !(*this == rhs);}
	operator bool() const {return x >= 0;}
	Location(int x=-1, int y=-1) : x(x), y(y) {}
	int x, y;
    
    Location &operator =(const Location &other) {
        this->x = other.x;
        this->y = other.y;
    }
};

class Maze;

Maze load(std::string filename);

class Maze {
	friend std::ostream &operator <<(std::ostream &os, const Maze &maze);
	friend Maze load(std::string filename);
    public:
    Maze(): start(Location()), finish(Location()), spec(0){}
    Maze(const Maze &other);
    bool solve();
    void print();
    
    private:
    int height() const {return spec.size();}
	int width() const {return spec[0].size();}
    
    std::vector<std::vector<bool> > spec;
    Location start, finish;
    Location current;
    
	bool isPath(const Location &location);
    void printBarriers();
    std::vector<Location> path;
};

#endif
