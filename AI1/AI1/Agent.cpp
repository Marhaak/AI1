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
	//Y
	for (int y = 0; y < 3; y++){
		temp.push_back( new Node(3) );
	}
	//X
	for (int x = 0; x < 3; x++){
		internalMap.push_back(temp);
	}
	internalMap[1][1] = positionNode;
	
	internalMap[0][1] = world->isMoveAble(posX-1, posY); //up
	internalMap[2][1] = world->isMoveAble(posX+1, posY); //down
	internalMap[1][0] = world->isMoveAble(posX, posY-1); //left
	internalMap[1][2] = world->isMoveAble(posX, posY+1); //right
	
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

			if (i == x+internOffsetX && j == y+internOffsetY){
				std::cout << "A";
			} else {
				if (internalMap[i][j]->getValue() == 0){std::cout << " ";}
				if (internalMap[i][j]->getValue() == 1){std::cout << "~";}
				if (internalMap[i][j]->getValue() == 2){std::cout << "#";}
				if (internalMap[i][j]->getValue() == 3){std::cout << "x";}
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

	//Sleep(sleep);
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

	//Check the suroundings after move
	Recon();

	positionNode = world->isMoveAble(posX, posY);

	positionNode->visit();
	std::cout<< "Moved to x: "<<posX<< " y: "<< posY<<std::endl;
	//Sleep(sleep);

}


void Agent::Recon(){
	
	//Add to left of internal map.
	if(posY + internOffsetY-1 < 0){
		internOffsetY++;
		for(unsigned int x = 0; x < internalMap.size(); x++){
			internalMap[x].push_front( new Node(3) );
		}
	}

	//Add to right of internal map.
	if(posY + internOffsetY+1 >= internalMap[0].size() ){
		for(unsigned int x = 0; x < internalMap.size(); x++){
			internalMap[x].push_back( new Node(3) );
		}
	}

	//add to top of internal map.
	if(posX + internOffsetX-1 < 0 ){
		internOffsetX++;
		std::deque<Node*> temp;			
		for (int y = 0; y < internalMap[0].size(); y++){
			temp.push_back( new Node(3) );
		}
		internalMap.push_front( temp );
	}

	//add to bottom of internal map.
	if(posX + internOffsetX+1 >= internalMap.size() ){
		std::deque<Node*> temp;
		for (int y = 0; y < internalMap[0].size(); y++){
			temp.push_back( new Node(3) );
		}
		internalMap.push_back( temp );
	}

	internalMap[posX + internOffsetX-1][posY + internOffsetY] = world->isMoveAble(posX-1, posY); //up
	internalMap[posX + internOffsetX+1][posY + internOffsetY] = world->isMoveAble(posX+1, posY); //down
	internalMap[posX + internOffsetX][posY + internOffsetY-1] = world->isMoveAble(posX, posY-1); //left
	internalMap[posX + internOffsetX][posY + internOffsetY+1] = world->isMoveAble(posX, posY+1); //right

}
