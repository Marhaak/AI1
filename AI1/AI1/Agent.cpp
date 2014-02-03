#include "Agent.h"
#include "Environment.h"
#include "Include.h"

using namespace std;

Agent::Agent(Environment* _world){
	
	srand( time(NULL) );
	running = false;
	
	steps = 0;
	
	posX = 0;
	posY = 0;
	
	world = _world;
	positionNode = _world->SetStartNode();
}

Agent::~Agent(void){

	delete positionNode;
}

int Agent::Run(){

	running = true;
	
	//running until environment is clean
	while (running) {
		system("CLS");
		world->draw(posX, posY);
		Vacuum();
		Move();
		
		//will end if taking more than 1k steps.
		steps++;
		if(steps > 1000) {
			running = false;
			return 0;
		}
	}
	return 1;
};

void Agent::Vacuum() {

	if ( positionNode->getValue() == 0 ) {
		//Sleep(300);
		cout << "Node is clean" << std::endl;
	}
	else {

		//Sleep(300);
		std::cout<< "I am vacuuming here now, soon clean...";
		//Sleep(300);
		std::cout<< " Clean!"<< std::endl;

		positionNode->setValue(0);
		if(world->AddCleanedNode()) {

			world->SetNumSteps(steps);
			running = false;
		}
	}
}

void Agent::Move() {

	
	std::cout<< "Moving to next - ";



	bool moveAble = true;
	int randomz;
	while( moveAble ) {
		randomz = rand() % 4;
		if(randomz == 0) { // Down
			cout<< "Down wards\n";
			if(world->isMoveAble(posX+1, posY)->getValue() != 2) {
				posX += 1;
				moveAble = false;
			} else {
					cout<< "Its a wall\n";
				}
		} 
		else if(randomz == 1) { // Right
			cout<< "Right\n";
			if(world->isMoveAble(posX, posY+1)->getValue() != 2) {
				posY += 1;
				moveAble = false;
			} else {
					cout<< "Its a wall\n";
				}
		}
		else if(randomz == 2) { // Up
			cout<< "Up wards\n";
			if(world->isMoveAble(posX-1, posY)->getValue() != 2) {
				posX -= 1;
				moveAble = false;
			} else {
					cout<< "Its a wall\n";
				}
		}
		else if(randomz == 3) { // Left
			cout<< "Left\n";
			if(world->isMoveAble(posX, posY-1)->getValue() != 2) {
				posY -= 1;
				moveAble = false;
			} else {
					cout<< "Its a wall\n";
				}
		}

		else {

			cout<< "You are now stuck, getting a new position\n";
			positionNode = world->SetStartNode();
		}
	}

	positionNode = world->isMoveAble(posX, posY);

	positionNode->visit();
	std::cout<< "Moved to x: "<<posX<< " y: "<< posY<<std::endl;

	Sleep(sleep);
	
}
