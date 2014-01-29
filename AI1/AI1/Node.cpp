#include "Include.h"
#include "Node.h"


Node::Node(){

	//Creation
	int value = 0;
}

Node::~Node(){

	//Destruction

}

bool Node::enter(){

	//Assuming 0 means you can't enter the node
	//1,2,3... for visited, clean, dirty whatevs.
	return value;
}

int Node::getValue(){

	return value;
}

int Node::setValue(int _new){

	value = _new;
	return value;
}