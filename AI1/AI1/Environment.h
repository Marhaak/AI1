#pragma once

#include "Include.h"

class Environment {
private:
	std::vector< std::vector<int> > map;

public:
	Environment(int x = 5, int y = 5);
	~Environment(void);
};

