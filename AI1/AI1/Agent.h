#pragma once

#include "Include.h"
#include "Enviorment.h"

class Agent
{
public:
	Agent(void);
	~Agent(void);
	
	int Run(Enviorment* world);
};

