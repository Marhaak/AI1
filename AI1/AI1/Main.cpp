#include "Include.h"
#include "Agent.h"
#include "Environment.h"

using namespace std;

int main(int argc, char* argv[]){
	
<<<<<<< HEAD
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
=======
	Environment* environment = NULL;
	Agent* agent = NULL;
	Node* startNode = nullptr;

	//taking commandline parameter to set up size of environment
	if (argc > 2){
		environment = new Environment( atoi(argv[1]), atoi(argv[2]) );
	} else { environment = new Environment(); }

	agent = new Agent(environment);
	
	//running.
>>>>>>> b37c7c9b8beb4c36d30d0549c8372cb7e4349211
	if(agent->Run() == 1) {
		cout << "It is very clean now!" << endl;
	} else {
		cout << "Can not clean everything!" << endl;
	}

<<<<<<< HEAD
	//Cleaning up
=======
>>>>>>> b37c7c9b8beb4c36d30d0549c8372cb7e4349211
	delete environment;
	delete agent;

	return 0;
}