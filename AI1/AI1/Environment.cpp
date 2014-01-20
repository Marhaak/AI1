
#include "Include.h"
#include "Environment.h"



Environment::Environment(int x, int y){

	srand( time(NULL) );
	map.resize( x, std::vector<int>(y, 0) );

	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			map[i][j] = rand() % 3;
		}
	}

	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			
			if (map[i][j] == 0){std::cout << "# ";}
			if (map[i][j] == 1){std::cout << "- ";}
			if (map[i][j] == 2){std::cout << "+ ";}

		}
		std::cout << std::endl;
	}

	std::cin >> map[0][0];
}


Environment::~Environment(void){


}
