#include "Agent.h"
#include "Environment.h"
#include "Include.h"
using namespace std;

Agent::Agent(void){
	
	running = false;
	steps = 0;
	posX = 0;
	posY = 0;
	positionNode = nullptr;
}

Agent::~Agent(void){

	delete positionNode;
}

int Agent::Run(Environment* _world){

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

void Agent::Move(Environment* _world) {

	Sleep(1000);
	std::cout<< "Moving to next"<< std::endl;
	Sleep(1000);

	// up
	if(_world->isMoveAble(posX+1, posY)->getValue() != 2) {
		posX += 1;
	}
	// right
	else if(_world->isMoveAble(posX+1, posY)->getValue() != 2) {
		posY += 1;
	}
	// down
	else if(_world->isMoveAble(posX+1, posY)->getValue() != 2) {
		posX -= 1;
	}
	// left
	else if(_world->isMoveAble(posX+1, posY)->getValue() != 2) {
		posY -= 1;
	}
	//stuck
	else{
		cout << "Trapped bot is unhappy" << std::endl;
	}

	//new position
	positionNode = _world->isMoveAble(posX, posY);
	std::cout<< "Moved to x: "<<posX<< " y: "<< posY<<std::endl;

}
