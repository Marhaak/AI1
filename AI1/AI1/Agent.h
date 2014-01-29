#pragma once

#include "Include.h"
#include "Environment.h"

class Agent{

private:

	// Variables
	bool running;
	bool beenHere; // false if not been there, true if it has
	int steps;
	int posX;
	int posY;
	int posXBeenHere;
	int posYBeenHere;
	Node* positionNode;
	Environment* world;

	// Functions
	void Vacuum();
	void Move();
	

public:
	// Variables

	// Functions
	Agent(Environment* _world);
	~Agent();

	int Run();

};

