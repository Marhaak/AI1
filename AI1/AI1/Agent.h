#pragma once

#include "Include.h"
#include "Environment.h"

class Agent{

private:

	// Variables
	bool running;
	int steps;
	int posX;
	int posY;

	// Functions
	void Vacuum();
	void Move();


public:
	// Variables

	// Functions
	Agent();
	~Agent();

	int Run(Environment* _world);

};

