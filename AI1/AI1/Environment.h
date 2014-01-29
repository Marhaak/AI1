#pragma once

#include "Include.h"
#include "Node.h"

class Environment {
private:
	// Variables
	int xSize;
	int ySize;
	std::vector< std::vector<Node*> > map;

	// Functions

public:


	// Variables

	// Functions
	Environment(int _x = 5, int _y = 5);
	~Environment();
	bool isMoveAble(int x, int y);
};

