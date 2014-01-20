#include "Agent.h"
#include "Environment.h"


Agent::Agent(void){

	steps = 0;

}


Agent::~Agent(void){

	delete this;

}


int Agent::Run(Environment* world){
	running = true;

	//infinite running loop :D
	while (running){




	}

	return 0;
};