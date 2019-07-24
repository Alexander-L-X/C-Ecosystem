#pragma once
#include "Biogeocenose.h"
class Wolf :
	public Biogeocenose
{
public:
	Wolf();
	~Wolf();
	void animalshow();
	void prey(int x, int y);
	friend class Activity;
};

