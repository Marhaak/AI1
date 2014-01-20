
#include "Include.h"
#include "Environment.h"



Environment::Environment(int x, int y){

	map.resize( x, std::vector<int>(y, 0) );



}


Environment::~Environment(void)
{
}
