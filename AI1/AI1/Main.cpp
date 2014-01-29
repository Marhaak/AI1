
#include "Include.h"
#include "Agent.h"
#include "Environment.h"
using namespace std;

int main(int argc, char* argv[]){
	Environment* environment = NULL;
	Agent* agent = NULL;
	Node* startNode = nullptr;

	if (argc > 2){
		environment = new Environment( int(*argv[1])-48, int(*argv[2])-48 );
	} else { environment = new Environment(); }
	agent = new Agent(environment);
	
	if(agent->Run() == 1) {

		cout<< "It is very clean now!"<< endl;
	}

	//cin.get();

	delete environment;
	delete agent;

	return 0;
}