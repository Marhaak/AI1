
#include "Include.h"
#include "Agent.h"
#include "Enviorment.h"

int main(){


	Enviorment* enviorment = NULL;
	Agent* agent = NULL;

	enviorment = new Enviorment();
	agent = new Agent();

	if(agent->Run(enviorment) == 1) {

		std::cout<< "It is very clean now!"<< std::endl;
	}

	std::cout << "Hello World!" << std::endl;

	return 0;
}