#pragma once

#include "Include.h"

class Node {

private:
	// Variables
	int value;
	bool visited;

	// Functions

public:

	// Variables

	// Functions
	Node(int init);
	~Node();
	bool enter();
	int getValue();			// Returns the valus of the node
	int setValue(int _new);	// Sets a new value
	void visit();			// Sets the node til visited
	bool getVisit();		// Returns the visit status
};