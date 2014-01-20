#pragma once

#include "Include.h"
#include "Environment.h"

class Agent{

private:
	bool running;
	int steps;
	int posX;
	int posY;


public:
	Agent(void);
	~Agent(void);

	int Run(Environment* world);
};

