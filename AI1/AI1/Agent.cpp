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

int Agent::Run(){

	running = true;

	//infinite running loop :D
	while (running) {
		Vacuum();
		Move(world);

		steps++;
		if(steps > 1000) {
			running = false;
		}
	}

	return 1;
};

void Agent::Vacuum() {

	if ( positionNode->getValue == 0 ) {
		Sleep(1000);
		cout << "Node is clean";
	}
	else {
		Sleep(1000);
		std::cout<< "I am vacuuming here now, soon clean"<< std::endl;
		Sleep(1000);
		std::cout<< "Clean!"<< std::endl;
		positionNode->setValue = 0;
	}
}

void Agent::Move(Environment* _world) {

	Sleep(1000);
	std::cout<< "Moving to next"<< std::endl;
	Sleep(1000);

	// up
	positionNode = _world->isMoveAble(posX+1, posY);
	if(positionNode != nullptr) {
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
