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

	delete this;

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

void Agent::Vacuum() {

	Sleep(1000);
	std::cout<< "I am vacuuming here now, soon clean"<< std::endl;
	Sleep(1000);
	std::cout<< "Clean!"<< std::endl;
}

void Agent::Move() {

	Sleep(1000);
	std::cout<< "Moving to next"<< std::endl;
	Sleep(1000);
	/* move code here*/

	std::cout<< "Moved to x: "<<posX<< " y: "<< posY<<std::endl;

}