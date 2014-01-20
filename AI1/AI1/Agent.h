#pragma once

#include "Include.h"
#include "Environment.h"

class Agent{

private:
	bool running;


public:
	Agent(void);
	~Agent(void);
	int Run(Environment world);
};

