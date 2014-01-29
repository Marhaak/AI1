
#include "Include.h"
#include "Environment.h"
#include "Node.h"


<<<<<<< HEAD

Environment::Environment(void){
=======
>>>>>>> 25ea51667c0321f7b4fe60a47725066798198432

Environment::Environment(int _x, int _y){

	srand( time(NULL) );
	
	//que?
	map.resize( _x, std::vector<int>(_y, 0) );

<<<<<<< HEAD


Environment::Environment(int x, int y){

	map.resize( x, std::vector<int>(y, 0) );
=======
	for (int i = 0; i < _x; i++){
		for (int j = 0; j < _y; j++){
			map[i][j] = new Node;
			map[i][j]->setValue( rand() % 3 );
		}
	}
>>>>>>> 25ea51667c0321f7b4fe60a47725066798198432

	for (int i = 0; i < _x; i++){
		for (int j = 0; j < _y; j++){
			
			if (map[i][j]->getValue() == 0){std::cout << "# ";}
			if (map[i][j]->getValue() == 1){std::cout << "- ";}
			if (map[i][j]->getValue() == 2){std::cout << "+ ";}

		}
		std::cout << std::endl;
	}

}


Environment::~Environment(){


}
