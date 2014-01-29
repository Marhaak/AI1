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


int Agent::Run(Environment* _world){

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

void Agent::Move(Environment* _world) {

	Sleep(1000);
	std::cout<< "Moving to next"<< std::endl;
	Sleep(1000);
	// up
	if(_world->isMoveAble(posX+1, posY)) {
		posX += 1;
	}
	// right
	if(_world->isMoveAble(posX, posY+1)) {
		posY += 1;
	}
	// down
	if(_world->isMoveAble(posX-1, posY)) {
		posX -= 1;
	}
	// left
	if(_world->isMoveAble(posX, posY-1)) {
		posY -= 1;
	}
	std::cout<< "Moved to x: "<<posX<< " y: "<< posY<<std::endl;

}
