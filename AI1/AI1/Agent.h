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
	bool moveToWhere[3];
	Node* positionNode;
	Environment* world;

	// Functions
	void Vacuum();	// This function will vacuum if there is dirty
	void Move();	// This function will move the agent to a new place
	

public:
	// Variables

	// Functions
	Agent(Environment* _world);
	~Agent();

	int Run();	// The main loop of the agent

};

