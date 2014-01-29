#include "Include.h"
#include "Node.h"
using namespace std;

Node::Node(int init){

	//Creation
	value = init;
}

Node::~Node(){

	//Destruction
}

bool Node::enter(){

	// 0 = clean, 1 = dirty, 2 = obstacle
	return value;
}

int Node::getValue(){
	return value;
}

int Node::setValue(int _new){

	value = _new;
	return value;
}