#include "Agent.h"
#include "Environment.h"
#include "Include.h"


Agent::Agent(void){

	steps = 0;
	running = false;
	posX = 0;
	posY = 0;

}


Agent::~Agent(void){


}


int Agent::Run(Environment* world){
	running = true;

	//infinite running loop :D
	while (running) {

		/* 
		Rest of code here
		*/


		steps++;
		if(steps > 1000) {

			running = false;
		}
	}

	return 0;
};