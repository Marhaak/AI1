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
	int getValue();
	int setValue(int _new);
	void visit();
	bool getVisit();
};