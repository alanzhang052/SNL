// Alan Zhang 3/12/20
// SNL.h

#ifndef SNL_H
#define SNL_H

#include <iostream>
#include <vector>
#include <queue>

struct Vertex {
	std::vector<int> paths;
};

class SNL {
public:
	void createBoard(int n);
	void printPath();

	std::vector<int> ladders;
	std::vector<int> snakes;

	std::queue<int> q;
	std::vector<bool> visitors;
	std::vector<int> prev;

private:
	std::vector<Vertex> board;
};

#endif