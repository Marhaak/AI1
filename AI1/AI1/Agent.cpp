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
	positionNode = _world->SetStartNode();
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
		Vacuum();
		Move();
		Sleep(2500);
		
		steps++;
		if(steps > 1000) {
			running = false;
		}
		cin.get();
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

	//Sleep(1000);

	//// Down
	//if(world->isMoveAble(posX+1, posY)->getValue() != 2) {
	//	cout<< "Down\n";
	//	if(!world->isMoveAble(posX+1, posY)->getVisit() ) {
	//		posX += 1;
	//		beenHere = false;
	//		cout<< "Down not visited\n";
	//	} else {
	//		posXBeenHere += 1;
	//		beenHere = true;
	//	}
	//}

	//// right
	//else if(world->isMoveAble(posX, posY+1)->getValue() != 2) {
	//	cout<< "Right\n";
	//	if(!world->isMoveAble(posX, posY+1)->getVisit() ) {
	//		posY += 1;
	//		beenHere = false;
	//	} else {
	//		posYBeenHere += 1;
	//		beenHere = true;
	//	}
	//}

	//// down
	//else if(world->isMoveAble(posX-1, posY)->getValue() != 2) {
	//	cout<< "Up\n";
	//	if(!world->isMoveAble(posX-1, posY)->getVisit() ) {
	//		posX -= 1;
	//		beenHere = false;
	//	} else {
	//		posXBeenHere -= 1;
	//		beenHere = true;
	//	}
	//}

	//// left
	//else if(!world->isMoveAble(posX, posY-1)->getValue() != 2) {
	//	cout<< "Left\n";
	//	if(world->isMoveAble(posX, posY-1)->getVisit() ) {
	//	posY -= 1;
	//	beenHere = false;
	//	} else {
	//		posYBeenHere -= 1;
	//		beenHere = true;
	//	}
	//} 
	////stuck
	//else{
	//	cout << "Trapped bot is unhappy" << std::endl;
	//	running = false;
	//}

	srand( time(NULL) );
	int randomz = rand() % 3;
	if(randomz == 0) { // Down

		if(world->isMoveAble(posX+1, posY)->getValue() != 2) {
			posX += 1;
		}
	} 
	else if(randomz == 1) { // Right

		if(world->isMoveAble(posX, posY+1)->getValue() != 2) {
			posY += 1;
		}
	}
	else if(randomz == 2) { // Up

		if(world->isMoveAble(posX-1, posY)->getValue() != 2) {
			posX -= 1;
		}
	}
	else if(randomz == 3) { // Up

		if(world->isMoveAble(posX-1, posY)->getValue() != 2) {
			posY -= 1;

		}
	}

	//new position
	/*if(!beenHere) {*/
		positionNode = world->isMoveAble(posX, posY);
	/*} else {
		positionNode = world->isMoveAble(posXBeenHere, posYBeenHere);
	}*/

	positionNode->visit();
	std::cout<< "Moved to x: "<<posX<< " y: "<< posY<<std::endl;
	Sleep(1000);

}


