#include "Include.h"
#include "Agent.h"
#include "Environment.h"

using namespace std;

int sleep = 150;


int main(int argc, char* argv[]){
	
	Environment* environment = nullptr;
	Agent* agent = nullptr;
	Node* startNode = nullptr;
	
	int xCordForEnvironment = 10;
	int yCordForEnvironment = 10;

	//taking commandline parameter to set up size of environment
	if (argc > 2){
		environment = new Environment( atoi(argv[1]), atoi(argv[2]) );
	} else { environment = new Environment(xCordForEnvironment, yCordForEnvironment); }

	agent = new Agent(environment);
	
	//running.
	if(agent->Run() == 1) {
		cout << "It is very clean now!" << endl;
	} else {
		cout << "Can not clean everything!" << endl;
	}

	//Cleaning up
	delete environment;
	delete agent;

	return 0;
}