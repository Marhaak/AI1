
#include "Include.h"
#include "Environment.h"
#include "Node.h"



Environment::Environment(int _x, int _y){

	srand( time(NULL) );
	map.resize( _x, std::vector<int>(_y, Node) );

	for (int i = 0; i < _x; i++){
		for (int j = 0; j < _y; j++){
			map[i][j].setValue( rand() % 3 );
		}
	}

	for (int i = 0; i < _x; i++){
		for (int j = 0; j < _y; j++){
			
			if (map[i][j].getValue() == 0){std::cout << "# ";}
			if (map[i][j].getValue() == 1){std::cout << "- ";}
			if (map[i][j].getValue() == 2){std::cout << "+ ";}

		}
		std::cout << std::endl;
	}

}


Environment::~Environment(){


}
