#include "stdafx.h"
#include "Sheep.h"


Sheep::Sheep()
{
	//��Ļ�����Ϣ
	name = "��";
	life = 10;
	scope = 5;
}


Sheep::~Sheep()
{
}

void Sheep::animalshow()
{
	Push(range_x, range_y);
	cout << "��";
}

void Sheep::prey(int x, int y)
{
	SetColor(15);
	Push(range_x, range_y);
	cout << " ";
	range_x = x;
	range_y = y;
	animalshow();
	life = 10;
	scope = 5;
	age++;
	if (age == 3) reproduce = true;
}
