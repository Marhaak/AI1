
#include "Include.h"
#include "Agent.h"
#include "Environment.h"
using namespace std;

int main(){
	Environment* environment = NULL;
	Agent* agent = NULL;
	Node* startNode = nullptr;

	environment = new Environment();
	startNode = environment->SetStartNode();
	agent = new Agent(environment, startNode);

	if(agent->Run() == 1) {

		std::cout<< "It is very clean now!"<< std::endl;
	}

	cin.get();
<<<<<<< HEAD

=======
	
>>>>>>> a1e342cab1e896a66798acf8a17234615c03c9a4
	delete environment;
	delete agent;

	return 0;
}