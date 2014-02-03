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

	//Setting up internal map.
	std::deque<Node*> temp;
	for (int x = 0; x < 3; x++){
		temp.push_back( new Node(1) );
	}
	for (int x = 0; x < 3; x++){
		internalMap.push_back(temp);
	}
	internalMap[1][1] = positionNode;
	
	internOffsetX = 1;
	internOffsetY = 1;

}

Agent::~Agent(void){

	delete positionNode;
}

void Agent::Draw(int x, int y){

	std::cout << "\nInternal Map:\n";
	for(unsigned int i = 0; i < internalMap.size(); i++){
		for (unsigned int j = 0; j < internalMap[i].size(); j++){

			if (i == x && j == y){
				std::cout << "0";
			} else {
				if (internalMap[i][j]->getValue() == 0){std::cout << "x";}
				if (internalMap[i][j]->getValue() == 1){std::cout << " ";}
				if (internalMap[i][j]->getValue() == 2){std::cout << "#";}
			}
		}
		std::cout << std::endl;
	}
	std::cout << "End of internal Map\n";
}

int Agent::Run(){

	running = true;
	
	//running until environment is clean
	while (running) {
		system("CLS");
		world->draw(posX, posY);
		Draw(posX, posY);
		Vacuum();
		Move();
		
		//will end if taking more than 1k steps.
		steps++;
		if(steps > 100) {
			running = false;
			return 1;
		}
	}
	return 0;
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
		world->AddCleanedNode();
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
	//Sleep(sleep);

}
