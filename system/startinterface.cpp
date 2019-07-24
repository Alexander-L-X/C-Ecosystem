#include "startinterface.h"
#include <windows.h>
#include"stdafx.h"

void startInterface::PrintFirst()//蛇从左边出现到完全出现的过程
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
		/*计算下一个位置，并将其压入starts中，绘制出来，将尾去掉*/
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		starts.emplace_back(Point(i, j));
		starts.back().Print();
		starts.front().Clear();
		starts.pop_front();
		Sleep(speed);
	}
}

void startInterface::PrintThird()//从接触右边到消失的过程
{
	while (!starts.empty() || textsystem.back().GetX() < 40) //当其还没消失或文字没移动到指定位置
	{
		if (!starts.empty()) //如果还没消失，继续移动
		{
			starts.front().Clear();
			starts.pop_front();
		}
		ClearText();//清除已有文字
		PrintText();//绘制更新位置后的文字
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
	for (auto& point : textsystem) //清除的同时将文字整体向右移动一格
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