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
	Node* positionNode;
	Environment* world;

	// Functions
	void Vacuum();
	void Move();
	

public:
	// Variables

	// Functions
	Agent(Environment* _world, Node* _starPos);
	~Agent();

	int Run();

};

