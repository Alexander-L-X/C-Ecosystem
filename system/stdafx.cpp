// infodafx.cpp : 只包括标准包含文件的源文件
// syinfoem.pch 将作为预编译标头
// infodafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 infoDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用


void HideCursor()//隐藏光标 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void Push(int y, int x)//设置光标位置函数
{
	COORD push;
	push.X = x;
	push.Y = y;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, push);
	return;
}
void edgemap()//打印地图
{
	int i, j;
	for (i = 0; i < 35; i++)
	{
		Push(i, 0);
		cout<<"┿";
		Push(i, 118);
		cout << "┿";
	}

	for ( j = 2; j < 120; j += 2)
	{
		Push(0, j);
		cout << "┿";
		Push(34, j);
		cout << "┿";
	}

}
//v3.1 新增加功能1
void SetColor(int colorID)//设置文本颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor1()//设置文本背景色1
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_BLUE);
}
void SetBackColor2()//设置文本背景色2
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_RED |
		BACKGROUND_RED |
		BACKGROUND_RED |
		BACKGROUND_RED);
}

void SetCursorPosition(const int x, const int y)//设置光标位置
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
