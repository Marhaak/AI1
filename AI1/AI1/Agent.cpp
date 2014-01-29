#include "Agent.h"
#include "Environment.h"
#include "Include.h"
using namespace std;

Agent::Agent(Environment* _world){
	
	running = false;
	steps = 0;
	posX = 0;
	posY = 0;
	world = _world;
	positionNode = nullptr;
}

Agent::~Agent(void){

	delete positionNode;
}

int Agent::Run(){

	running = true;

	//infinite running loop :D
	while (running) {

		/* 
		Rest of code here

		// Spør miljø om noden agenten står ovenfor om status
		// Reager etter forholdet som blir rapportert
		// Etter regel funn endres value til node og agent skal flyttes

		*/


		steps++;
		if(steps > 1000) {

			running = false;
		}
	}

	return 1;
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
	// up
	positionNode = world->isMoveAble(posX+1, posY);
	if(positionNode != nullptr) {
		posX += 1;
	}
	// right
	positionNode = world->isMoveAble(posX, posY+1);
	if(positionNode != nullptr) {
		posY += 1;
	}
	// down
	positionNode = world->isMoveAble(posX-1, posY);
	if(positionNode != nullptr) {
		posX -= 1;
	}
	// left
	positionNode = world->isMoveAble(posX, posY-1);
	if(positionNode != nullptr) {
		posY -= 1;
	}
	std::cout<< "Moved to x: "<<posX<< " y: "<< posY<<std::endl;

}
