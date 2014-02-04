#pragma once

#include "Include.h"
#include "Node.h"

class Environment {
private:
	// Variables
	int xSize;
	int ySize;
	int botX;
	int botY;
	int dirtCounter;		// Make a new dirt on the map when dirtCounter % x == 0
	int numOfDirts;			// Hold the current number of dirts
	int NumOfDirtsCleaned;	// Hold the number of cleaned dirts
	int numOfStepsUsed;		// Will hold the number of steps the agent used to clean the area
	std::vector< std::vector<Node*> > map; // The map that the agents lives in
	Node* dummy;
	
	// Functions
	

public:

	// Variables
	
	// Functions
	Environment(int _x = 10, int _y = 20, int _dirt = 20, int _obj = 10);
	~Environment();
	Node* isMoveAble(int x, int y); // Return the node that the agent can move to, or a dummy node
	void draw(int _x, int _y);		// Draws the map
	Node* SetStartNode();			// Returns a startnode that the agent will start on
	void AddCleanedNode();
	void SetNumSteps(int _i);
	void GetScore();
};
