#include "stdafx.h"
#include "Wolf.h"

Wolf::Wolf()
{
	//�ǵĻ�����Ϣ
	name = "��";
	life = 7;
	scope = 7;
}


Wolf::~Wolf()
{
}


void Wolf::animalshow()
{
	Push(range_x, range_y);
	cout << "��";
}


void Wolf::prey(int x, int y)
{
	SetColor(12);
	Push(range_x, range_y);
	cout<<"  ";
	range_x = x;
	range_y = y;
	animalshow();
	life = 7;
	scope = 7;
	age++;
	if (age == 3) reproduce = true;
}