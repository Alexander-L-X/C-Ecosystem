#include "stdafx.h"
#include "Biogeocenose.h"


Biogeocenose::Biogeocenose()
{
	age = 0;
	orientation = 0;
	reproduce = false;
}


Biogeocenose::~Biogeocenose()
{
}


void Biogeocenose::getx(int x)
{
	range_x = x;
}


int Biogeocenose::putx()
{
	return range_x;
}


void Biogeocenose::gety(int y)
{
	range_y = y;
}


int Biogeocenose::puty()
{
	return range_y;
}


void Biogeocenose::animalshow()
{
}


void Biogeocenose::move(int t)
{
	Push(range_x, range_y);
	printf("  ");
	switch (t)
	{
	case 0:range_x += 1; break;
	case 1:range_x -= 1; break;
	case 2:range_y -= 2; break;
	case 3:range_y += 2; break;
	}
	animalshow();
	age++;//��������
	if (age == 3) reproduce = true;//�������ڿ�ʼ��ֳ
	life--;//������ʼ�½�
	scope = life / 2;//��ʳ��Χ���������Ӽ���
}


string Biogeocenose::s_name()
{
	return name;
}


void Biogeocenose::prey(int x, int y)
{
}


int Biogeocenose::s_scope()
{
	return scope;
}


int Biogeocenose::s_life()
{
	return life;
}


bool Biogeocenose::s_reproduce()
{
	return reproduce;
}


