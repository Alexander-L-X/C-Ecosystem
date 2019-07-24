#include "stdafx.h"
#include "Grass.h"


Grass::Grass()
{
	name = "²Ý";
	life = 5;
	reproduce = true;
}


Grass::~Grass()
{
}


void Grass::animalshow()
{
	SetColor(3);
	Push(range_x, range_y);
	cout << "¨ˆ";
}

