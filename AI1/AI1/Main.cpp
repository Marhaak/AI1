
#include "Include.h"
#include "Agent.h"
#include "Environment.h"

int main(){

	Environment* environment = NULL;
	Agent* agent = NULL;

	environment = new Environment();
	agent = new Agent();

	if(agent->Run(environment) == 1) {

		std::cout<< "It is very clean now!"<< std::endl;
	}

	std::cout << "Hello World!" << std::endl;

	delete environment;
	delete agent;

	return 0;
}