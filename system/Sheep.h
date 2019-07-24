#pragma once
#include "Biogeocenose.h"
class Sheep :
	public Biogeocenose
{
public:
	Sheep();
	~Sheep();
	void animalshow();
	void prey(int x, int y);
	friend class Activity;
};

