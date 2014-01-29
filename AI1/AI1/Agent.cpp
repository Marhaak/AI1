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
		world->draw(posX, posY);
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
	if(world->isMoveAble(posX+1, posY)->getValue() != 2) {
		posX += 1;
	}
	// right
	else if(world->isMoveAble(posX+1, posY)->getValue() != 2) {
		posY += 1;
	}
	// down
	else if(world->isMoveAble(posX+1, posY)->getValue() != 2) {
		posX -= 1;
	}
	// left
	else if(world->isMoveAble(posX+1, posY)->getValue() != 2) {
		posY -= 1;
	}
	//stuck
	else{
		cout << "Trapped bot is unhappy" << std::endl;
		running = false;
	}

	//new position
	positionNode = world->isMoveAble(posX, posY);
	std::cout<< "Moved to x: "<<posX<< " y: "<< posY<<std::endl;

}
