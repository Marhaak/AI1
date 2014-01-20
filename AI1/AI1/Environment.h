#pragma once

#include "Include.h"

class Environment {
private:
	// Variables

	std::vector< std::vector<int> > map;

	// Functions

public:

	// Variables

	// Functions
	Environment();
	Environment(int x = 5, int y = 5);
	~Environment(void);
};

