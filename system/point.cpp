#include "stdafx.h"
#include "point.h"
#include <iostream>

void Point::Print()//�������
{
	SetCursorPosition(x, y);
	cout << "��";
}

void Point::PrintCircular()//���Բ��
{
	SetCursorPosition(x, y);
	cout << "��";
}

void Point::Clear()//������
{
	SetCursorPosition(x, y);
	cout << "  ";
}

void Point::ChangePosition(const int x, const int y)//�ı�����
{
	this->x = x;
	this->y = y;
}