#include "startinterface.h"
#include <windows.h>
#include"stdafx.h"

void startInterface::PrintFirst()//�ߴ���߳��ֵ���ȫ���ֵĹ���
{
	for (auto& point : starts)
	{
		point.Print();
		Sleep(speed);
	}
}

void startInterface::PrintSecond()
{
	for (int i = 10; i != 40; ++i) 
	{
		/*������һ��λ�ã�������ѹ��starts�У����Ƴ�������βȥ��*/
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		starts.emplace_back(Point(i, j));
		starts.back().Print();
		starts.front().Clear();
		starts.pop_front();
		Sleep(speed);
	}
}

void startInterface::PrintThird()//�ӽӴ��ұߵ���ʧ�Ĺ���
{
	while (!starts.empty() || textsystem.back().GetX() < 40) //���仹û��ʧ������û�ƶ���ָ��λ��
	{
		if (!starts.empty()) //�����û��ʧ�������ƶ�
		{
			starts.front().Clear();
			starts.pop_front();
		}
		ClearText();//�����������
		PrintText();//���Ƹ���λ�ú������
		Sleep(speed);
	}
}

void startInterface::PrintText()
{
	for (auto& point : textsystem)
	{
		if (point.GetX() >= 0)
			point.Print();
	}
}

void startInterface::ClearText()
{
	for (auto& point : textsystem) //�����ͬʱ���������������ƶ�һ��
	{
		if (point.GetX() >= 0)
			point.Clear();
		point.ChangePosition(point.GetX() + 1, point.GetY());
	}
}

void startInterface::Action()
{
	PrintFirst();
	PrintSecond();
	PrintThird();
}