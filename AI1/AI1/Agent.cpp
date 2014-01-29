#include "Agent.h"
#include "Environment.h"
#include "Include.h"

using namespace std;

Agent::Agent(Environment* _world, Node* _startPos){
	
	running = false;
	steps = 0;
	posX = 0;
	posY = 0;
	world = _world;
	positionNode = _startPos;
}

Agent::~Agent(void){

	delete positionNode;
}

int Agent::Run(){

	running = true;
	Vacuum();
	//infinite to 1k running loop :D
	while (running) {
		world->draw(posX, posY);
		Move();
		Vacuum();

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
		cout<< "I am vacuuming here now, soon clean"<< endl;
		Sleep(1000);
		cout<< "Clean!"<< endl;
		positionNode->setValue(0);
	}
}

void Agent::Move() {

	Sleep(1000);
	cout<< "Moving to next"<< endl;
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
	cout<< "Moved to x: "<<posX<< " y: "<< posY<<endl;
}


