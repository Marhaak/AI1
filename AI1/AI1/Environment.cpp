#include "Node.h"
#include "Include.h"
#include "Environment.h"
using namespace std;

Environment::Environment(int _x, int _y){

	dummy = new Node(2);
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

Node* Environment::isMoveAble(int _x, int _y) {

	if(_x > xSize) {
		return nullptr;
	} else if(_y > ySize) {
		return nullptr;
	}
	return map[_x][_y];
}
