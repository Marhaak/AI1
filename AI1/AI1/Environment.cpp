
#include "Include.h"
#include "Environment.h"


<<<<<<< HEAD
Environment::Environment(void){

{


=======
>>>>>>> 658106b25c767092d6f08287f344d4d5dcd5067d

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
