#include "Node.h"
#include "Include.h"
#include "Environment.h"

Environment::Environment(int _x, int _y){

	xSize = _x;
	ySize = _y;
	srand( time(NULL) );
	
	for (int i = 0; i < _x; i++){
		
		std::vector<Node*> temp;
		map.push_back( temp );

		for (int j = 0; j < _y; j++){
			Node* node = new Node( rand() % 3 );
			map[i].push_back( node );
		}
	}

	for (int i = 0; i < _x; i++){
		for (int j = 0; j < _y; j++){
			
			if (map[i][j]->getValue() == 0){std::cout << "  ";}
			if (map[i][j]->getValue() == 1){std::cout << "~ ";}
			if (map[i][j]->getValue() == 2){std::cout << "# ";}

		}
		std::cout << std::endl;
	}
	std::cin >> xSize;
}

Environment::~Environment(){

}

bool Environment::isMoveAble(int _x, int _y) {

	if(_x > xSize) {
		return false;
	} else if(_y > ySize) {
		return false;
	}
	return true;
}
