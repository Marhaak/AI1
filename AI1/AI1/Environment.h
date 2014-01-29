#pragma once

#include "Include.h"
#include "Node.h"

class Environment {
private:
	// Variables

	std::vector< std::vector<Node*> > map;

	// Functions

public:


	// Variables

	// Functions
	Environment();
	Environment(int _x = 5, int _y = 5);
	~Environment();
};

