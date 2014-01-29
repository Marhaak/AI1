
#include "Include.h"
#include "Agent.h"
#include "Environment.h"
using namespace std;

int main(){

	Environment* environment = NULL;
	Agent* agent = NULL;

	environment = new Environment();
	agent = new Agent(environment);

	if(agent->Run() == 1) {

		std::cout<< "It is very clean now!"<< std::endl;
	}


	delete environment;
	delete agent;

	return 0;
}