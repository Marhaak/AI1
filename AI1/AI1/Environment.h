#pragma once

#include "Include.h"
#include "Node.h"

class Environment {
private:
	// Variables
	int xSize;
	int ySize;
	std::vector< std::vector<Node*> > map;
	Node* dummy;

	// Functions

public:


	// Variables

	// Functions
	Environment(int _x = 5, int _y = 5);
	~Environment();
	Node* isMoveAble(int x, int y);
	void draw(int _x, int _y);
};

