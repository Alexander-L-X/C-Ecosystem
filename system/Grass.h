#pragma once
#include "Biogeocenose.h"
class Grass :
	public Biogeocenose
{
public:
	Grass();
	~Grass();
	void animalshow();
	friend class Activity;
};

