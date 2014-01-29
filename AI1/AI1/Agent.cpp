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
		Vacuum();
		Move();

		steps++;
		if(steps > 1000) {
			running = false;
		}
	}
	return 1;
};

void Agent::Vacuum() {

	if ( positionNode->getValue() == 0 ) {
		Sleep(1000);
		cout << "Node is clean";
	}
	else {
		Sleep(1000);
		std::cout<< "I am vacuuming here now, soon clean"<< std::endl;
		Sleep(1000);
		std::cout<< "Clean!"<< std::endl;
		positionNode->setValue(0);
	}
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
