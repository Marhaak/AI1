
#include "Include.h"
#include "Agent.h"
#include "Environment.h"
using namespace std;

int main(int argc, char* argv[]){
	
	Environment* environment = nullptr;
	Agent* agent = nullptr;
	Node* startNode = nullptr;
	
	// If there is two arguments from the comand line
	if (argc > 2){
		environment = new Environment( int(*argv[1])-48, int(*argv[2])-48 );
	} else { 
		environment = new Environment(); 
	}
	agent = new Agent(environment);
	
	// Starting up agent, vroom vroom
	if(agent->Run() == 1) {

		cout<< "It is very clean now!"<< endl;
	}

	//Cleaning up
	delete environment;
	delete agent;

	return 0;
}