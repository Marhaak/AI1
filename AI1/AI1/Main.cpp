
#include "Include.h"
#include "Agent.h"
#include "Environment.h"
using namespace std;

int main(int argc, char* argv[]){
	
	Environment* environment = NULL;
	Agent* agent = NULL;
	Node* startNode = nullptr;

	//taking commandline parameter to set up size of environment
	if (argc > 2){
		environment = new Environment( atoi(argv[1]), atoi(argv[2]) );
	} else { environment = new Environment(); }

	agent = new Agent(environment);
	
	//running.
	if(agent->Run() == 1) {
		cout << "It is very clean now!" << endl;
	} else {
		cout << "Can not clean everything!" << endl;
	}


	delete environment;
	delete agent;

	return 0;
}