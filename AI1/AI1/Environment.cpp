
#include "Include.h"
#include "Environment.h"


Environment::Environment(void)
{



Environment::Environment(int x, int y){

	map.resize( x, vector<int>(y, 0) );



}


Environment::~Environment(void)
{
}
