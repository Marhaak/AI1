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
	internalMap[1][1]->visit();
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
}

int Agent::Run(){
	running = true;
	
	//running until environment is clean
	while (running) {
		system("CLS");
		world->draw(posX, posY);
		Recon();
		Draw(posX, posY);
		Vacuum();
		Move();
		
		//will end if taking more than 1k steps.
		steps++;
		if(steps > runtime) {
			running = false;
			return 1;
		}
	}
	return 0;
};

void Agent::Vacuum() {
	if ( positionNode->getValue() == 0 ) {
		cout << "Node is clean" << std::endl;
	}
	else {
		std::cout<< "I am vacuuming here now, soon clean...";
		Sleep(300);
		std::cout<< " Clean!"<< std::endl;
		positionNode->setValue(0);
		world->AddCleanedNode();
	}
}

void Agent::Move() {
	if( world->isMoveAble(posX+1, posY)->getValue() == 2 && world->isMoveAble(posX-1, posY)->getValue() == 2 &&
		world->isMoveAble(posX, posY+1)->getValue() == 2 && world->isMoveAble(posX, posY-1)->getValue() == 2 ){
			running = false;
			std::cout << "Trapped bot is sad bot" << std::endl;
			cin.get();
	} else {
		if(internalMap[posX+internOffsetX+1][posY+internOffsetY]->getValue() == 1){ posX++; }
		else if(internalMap[posX+internOffsetX-1][posY+internOffsetY]->getValue() == 1){ posX--; }
		else if(internalMap[posX+internOffsetX][posY+internOffsetY+1]->getValue() == 1){ posY++; }
		else if(internalMap[posX+internOffsetX][posY+internOffsetY-1]->getValue() == 1){ posY--; }
<<<<<<< HEAD

		//else if ( AStar() ){}
		
=======
>>>>>>> b9546785f6b76e7c0f80f7daf827d56a38947e25
		else{
			//Find shortest distance to unvisted node.
			float dist = 10000;
			int tempX;
			int tempY;
			for (unsigned int x = 0; x < internalMap.size(); x++){
				for (unsigned int y = 0; y < internalMap[0].size(); y++){

					if((internalMap[x][y]->getValue() == 0 || internalMap[x][y]->getValue() == 1) && !internalMap[x][y]->getVisit()){
						
						float temp = std::abs( std::sqrt( std::abs( int(posX+internOffsetX-x) ) * std::abs( int(posY+internOffsetY-y) ) ) );
						if (temp <= dist){
							dist = temp;
							tempX = x; tempY = y;
						}
					}

				}
			}
			//Found a target
			if(dist != 10000){				
				std::cout << "pos: " << posX+internOffsetX << " " << posY+internOffsetY << std::endl;
				std::cout << "Target: " << tempX << " " << tempY << std::endl;

				//Need to set up A* to target
				if (posX+internOffsetX-tempX > 0 && world->isMoveAble(posX-1, posY)->getValue() != 2){ posX--; }
				else if(posX+internOffsetX-tempX < 0 && world->isMoveAble(posX+1, posY)->getValue() != 2){ posX++; }
				else if (posY+internOffsetY-tempY > 0 && world->isMoveAble(posX, posY-1)->getValue() != 2){ posY--; }
				else if(posY+internOffsetY-tempY < 0 && world->isMoveAble(posX, posY+1)->getValue() != 2){ posY++; }
				
			}
			//no possible targets, unvisit all.
			else {
			
				for (unsigned int x = 0; x < internalMap.size(); x++){
					for (unsigned int y = 0; y < internalMap[0].size(); y++){
						internalMap[x][y]->visit(false);
					}
				}
				
				if(world->isMoveAble(posX, posY-1)->getValue() != 2){ posY--; }		
				else if(world->isMoveAble(posX+1, posY)->getValue() != 2){ posX++; }
				else if(world->isMoveAble(posX, posY+1)->getValue() != 2){ posY++; }
				else if (world->isMoveAble(posX-1, posY)->getValue() != 2){ posX--; }
			}
		}
	}
	positionNode = world->isMoveAble(posX, posY);
	std::cout<< "Moved to x: "<<posX<< " y: "<< posY<<std::endl;
	Sleep(sleep);
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
		for (unsigned int y = 0; y < internalMap[0].size(); y++){
			temp.push_back( new Node(3) );
		}
		internalMap.push_front( temp );
	}

	//add to bottom of internal map.
	if(posX + internOffsetX+1 >= internalMap.size() ){
		std::deque<Node*> temp;
		for (unsigned int y = 0; y < internalMap[0].size(); y++){
			temp.push_back( new Node(3) );
		}
		internalMap.push_back( temp );
	}

	internalMap[posX + internOffsetX-1][posY + internOffsetY]->setValue(world->isMoveAble(posX-1, posY)->getValue()); //up
	internalMap[posX + internOffsetX+1][posY + internOffsetY]->setValue(world->isMoveAble(posX+1, posY)->getValue()); //down
	internalMap[posX + internOffsetX][posY + internOffsetY-1]->setValue(world->isMoveAble(posX, posY-1)->getValue()); //left
	internalMap[posX + internOffsetX][posY + internOffsetY+1]->setValue(world->isMoveAble(posX, posY+1)->getValue()); //right

	//visit nodes.
	internalMap[posX+internOffsetX][posY+internOffsetY]->visit();
	if (internalMap[posX + internOffsetX-1][posY + internOffsetY]->getValue() == 2){ internalMap[posX + internOffsetX-1][posY + internOffsetY]->visit(); }
	if (internalMap[posX + internOffsetX+1][posY + internOffsetY]->getValue() == 2){ internalMap[posX + internOffsetX+1][posY + internOffsetY]->visit(); }
	if (internalMap[posX + internOffsetX][posY + internOffsetY+1]->getValue() == 2){ internalMap[posX + internOffsetX][posY + internOffsetY-1]->visit(); }
	if (internalMap[posX + internOffsetX][posY + internOffsetY-1]->getValue() == 2){ internalMap[posX + internOffsetX][posY + internOffsetY+1]->visit(); }
<<<<<<< HEAD

}



bool Agent::AStar(){
	
	//finding the target
	int dist = 10000;
	int targetX;
	int targetY;
	for (unsigned int x = 0; x < internalMap.size(); x++){
		for (unsigned int y = 0; y < internalMap[0].size(); y++){
			if((internalMap[x][y]->getValue() == 0 || internalMap[x][y]->getValue() == 1) && !internalMap[x][y]->getVisit()){
				
				int temp = std::abs( int(posX+internOffsetX-x) ) + std::abs( int(posY+internOffsetY-y) );
				if (temp <= dist){
					dist = temp;
					targetX = x; targetY = y;
				}
			}
		}
	}


	//pathfinding
	std::vector<Node*> Open;
	std::vector<Node*> Closed;

	Node* tempNode = positionNode;

	tempNode->ManhattanValue = dist*10;
	tempNode->thisX = posX+internOffsetX;
	tempNode->thisY = posY+internOffsetY;
	
	Open.push_back(tempNode);

	while(Open.size() > 0){
		
		//Search for lowest score
		int tempI = 0;
		std::cout << "target " << targetX << " " << targetY << endl;
		std::cout << "Position " << posX+internOffsetX << " " << posY+internOffsetY << endl;
		for(int i = 0; i < Open.size(); i++){

			std::cout << i << " " << Open[i]->ManhattanValue << endl;
			
			if(Open[i]->ManhattanValue <= tempNode->ManhattanValue){
				tempNode = Open[i];
				tempI = i;
			}
		}

		cin.get();
		//target found?
		if (tempNode->thisX == targetX && tempNode->thisY == targetY){
			std::cout << "yay" << endl;
			cin.get();
			
			return false;
		}

		//move from open to closed list
		Closed.push_back(tempNode);
		Open.erase(Open.begin() + tempI);
		

		//add 4 surounding nodes to open
		// x+1
		if(internalMap[tempNode->thisX+1][tempNode->thisY]->getValue() != 2 && NotIn(Closed, internalMap[tempNode->thisX+1][tempNode->thisY] ) ){
			Node* temp = internalMap[tempNode->thisX+1][tempNode->thisY];
			temp->thisX = tempNode->thisX+1; temp->thisY = tempNode->thisY;

			//adding manhattanvalue
			temp->ManhattanValue = (std::abs( int(temp->thisX-targetX) ) + std::abs( int(temp->thisY-targetY) ) ) * 10;
			temp->Parent = tempNode;
			Open.push_back( temp );
		}

		// x-1
		if(internalMap[tempNode->thisX-1][tempNode->thisY]->getValue() != 2 && NotIn(Closed, internalMap[tempNode->thisX-1][tempNode->thisY] ) ){
			Node* temp = internalMap[tempNode->thisX-1][tempNode->thisY];
			temp->thisX = tempNode->thisX-1; temp->thisY = tempNode->thisY;

			//adding manhattanvalue
			temp->ManhattanValue = (std::abs( int(temp->thisX-targetX) ) + std::abs( int(temp->thisY-targetY) ) ) * 10;
			temp->Parent = tempNode;
			Open.push_back( temp ); 
		}

		// y+1
		if(internalMap[tempNode->thisX][tempNode->thisY+1]->getValue() != 2 && NotIn(Closed, internalMap[tempNode->thisX][tempNode->thisY+1] ) ){
			Node* temp = internalMap[tempNode->thisX][tempNode->thisY+1];
			temp->thisX = tempNode->thisX; temp->thisY = tempNode->thisY+1;

			//adding manhattanvalue
			temp->ManhattanValue = (std::abs( int(temp->thisX-targetX) ) + std::abs( int(temp->thisY-targetY) ) ) * 10;
			temp->Parent = tempNode;
			Open.push_back( temp );
		}

		// y-1
		if(internalMap[tempNode->thisX][tempNode->thisY-1]->getValue() != 2 && NotIn(Closed, internalMap[tempNode->thisX][tempNode->thisY-1] ) ){
			Node* temp = internalMap[tempNode->thisX][tempNode->thisY-1];
			temp->thisX = tempNode->thisX; temp->thisY = tempNode->thisY-1;

			//adding manhattanvalue
			temp->ManhattanValue = (std::abs( int(temp->thisX-targetX) ) + std::abs( int(temp->thisY-targetY) ) ) * 10;
			temp->Parent = tempNode;
			Open.push_back( temp );
		}




	}
	return false;
}

bool Agent::NotIn(vector<Node*> vec, Node* node){
	for(int i = 0; i < vec.size(); i++){
		if(vec[i]->thisX == node->thisX && vec[i]->thisY == node->thisY){ return false; }
	}
	return true;
=======
>>>>>>> b9546785f6b76e7c0f80f7daf827d56a38947e25
}