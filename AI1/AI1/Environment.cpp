#include "Node.h"
#include "Include.h"
#include "Environment.h"

using namespace std;

Environment::Environment(int _x, int _y){

	xSize = _x;
	ySize = _y;
	numOfDirts = 0;
	NumOfDirtsCleaned = 0;
	srand( time(NULL) );
	
	for (int i = 0; i < _x; i++){

		std::vector<Node*> temp;
		map.push_back( temp );

		for (int j = 0; j < _y; j++){

			Node* node = new Node( rand() % 3 );
			map[i].push_back( node );
			if (node->getValue() == 1) {

				numOfDirts++;
			}
		}
	}
}

Environment::~Environment(){
	
	//map = nullptr
	for (int x = 0; x < xSize; x++){
		for (int y = 0; y < ySize; y++){
			map[x][y] = nullptr;
		}
	}
}

//returns the node the bot is trying to move into
Node* Environment::isMoveAble(int _x, int _y) {

	//if outside the map, return a node that is a wall.
	if(_x+botX > xSize-1 || _x+botX < 0 || _y+botY > ySize-1 || _y+botY < 0) {
		return new Node(2);
	}
	//there is an offset to where the bot is, and where it thinks it is.
	else return map[_x+botX][_y+botY];
}


//draws the environment
void Environment::draw(int _x, int _y){

	for (int i = 0; i < xSize; i++){
		for (int j = 0; j < ySize; j++){
			
			if(i == _x+botX && j == _y+botY){ std::cout<< "O";}
			else{
				if (map[i][j]->getValue() == 0){std::cout << " ";}
				if (map[i][j]->getValue() == 1){std::cout << "~";}
				if (map[i][j]->getValue() == 2){std::cout << "#";}
			}
		}
		std::cout << std::endl;
	}


	dirtCounter++;
	if( dirtCounter!= 0 && dirtCounter % 5 == 0) {
		int xPosHolder = botX;
		int yPosHolder = botY;
		
		SetStartNode()->setValue(1);
		
		botX = xPosHolder;
		botY = yPosHolder;
		numOfDirts++;
	}

}

Node* Environment::SetStartNode() {

	Node* startNode = new Node(2);
	
	//set random start node that is not a wall.
	while(startNode->getValue() == 2) {
		botX= rand() % xSize;
		botY = rand() % ySize;
		startNode = map[botX][botY];
	}
	return startNode;
}

void Environment::AddCleanedNode() {
	
	numOfDirts--;
	cout<< "Num dirt: "<<numOfDirts<< " Num dirt C: "<< NumOfDirtsCleaned<< "\n";
}

void Environment::SetNumSteps(int _i) {
	numOfStepsUsed = _i;
}

void Environment::GetScore() {

	int numOfDirtsLeft = 0;

	for (int i = 0; i < xSize; i++){
		for (int j = 0; j < ySize; j++){
			
			if(map[i][j]->getValue() == 1) {

				numOfDirtsLeft++;
			}
		}
		std::cout << std::endl;
	}

	cout<< numOfDirtsLeft<< " dirts left\nOn a "<< xSize<< " x "<< ySize<< "map\n";
}
