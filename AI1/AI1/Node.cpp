#include "Include.h"
#include "Node.h"

using namespace std;

Node::Node(int init){

	//Creation
	value = init;
	visited = false;
}

Node::~Node(){
	//Destruction
}


int Node::getValue(){
	return value;
}

int Node::setValue(int _new){
	value = _new;
	return value;
}

void Node::visit(){
	visited = true;
}

bool Node::getVisit(){
	return visited;
}