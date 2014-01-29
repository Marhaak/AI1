#include "Agent.h"
#include "Environment.h"
#include "Include.h"

using namespace std;

Agent::Agent(Environment* _world){
	
	running = false;
	steps = 0;
	posX = 3;
	posY = 2;
	world = _world;
	positionNode = _world->SetStartNode();
}

Agent::~Agent(void){

	delete positionNode;
}

int Agent::Run(){

	running = true;
	//infinite to 1k running loop :D
	while (running) {
		world->draw(posX, posY);
		Vacuum();
		Move();
		
		steps++;
		if(steps > 1000) {
			running = false;
		}
		system("CLS");
	}
	return 1;
};

void Agent::Vacuum() {

	if ( positionNode->getValue() == 0 ) {
		Sleep(300);
		cout << "Node is clean" << std::endl;
	}
	else {
		Sleep(300);
		std::cout<< "I am vacuuming here now, soon clean...";
		Sleep(300);
		std::cout<< " Clean!"<< std::endl;
		positionNode->setValue(0);
	}
}

void Agent::Move() {

	Sleep(300);
	std::cout<< "Moving to next"<< std::endl;
	Sleep(1000);

	// Down
	if(world->isMoveAble(posX+1, posY)->getValue() != 2 && !world->isMoveAble(posX+1, posY)->getVisit() ) {
		posX += 1;
	}

	// right
	else if(world->isMoveAble(posX, posY+1)->getValue() != 2  && !world->isMoveAble(posX, posY+1)->getVisit()) {
		posY += 1;
	}

	// down
	else if(world->isMoveAble(posX-1, posY)->getValue() != 2  && !world->isMoveAble(posX-1, posY)->getVisit()) {
		posX -= 1;
	}

	// left
	else if(world->isMoveAble(posX, posY-1)->getValue() != 2  && !world->isMoveAble(posX, posY-1)->getVisit()) {
		posY -= 1;
	}
	//stuck
	else{
		cout << "Trapped bot is unhappy" << std::endl;
		running = false;
	}

	//new position
	positionNode = world->isMoveAble(posX, posY);
	positionNode->visit();
	std::cout<< "Moved to x: "<<posX<< " y: "<< posY<<std::endl;
	Sleep(1000);
}


