// infodafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<vector>
#include<string.h>
#include<math.h>
#include<fstream>
#include <conio.h>
#include "Biogeocenose.h"
#include "Grass.h"
#include"Sheep.h"
#include"Wolf.h"
#include "point.h"
#include "startinterface.h"
using namespace std;
void HideCursor();//隐藏光标 
void Push(int y, int x);//设置光标位置函数
void edgemap();//地图
void SetColor(int colorID);
void SetBackColor1();
void SetBackColor2();
void SetCursorPosition(const int x, const int y);
// TODO: 在此处引用程序需要的其他头文件
