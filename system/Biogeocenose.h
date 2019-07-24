//生态系统基本信息
#pragma once
#include"stdafx.h"
using namespace std;
class Biogeocenose
{
public:
	Biogeocenose();
	~Biogeocenose();

	int range_x;//坐标x
	int range_y;//坐标y
	//物种基本信息
	int age;//年龄
	int life;//生命值
	int scope;//捕食范围
	bool reproduce;//繁殖力
	int orientation;//运动方位 0右 1左 2上 3下

	string name;//物种名称

				//建立物种坐标框
	void getx(int x);//坐标x
	void gety(int y);//坐标y
	int putx();
	int puty();

	void move(int z);//运动轨迹
	virtual void animalshow();//建立输出动物分布
	virtual void prey(int x, int y);//捕食


	int s_scope();
	int s_life();
	bool s_reproduce();

	string s_name();

	
};

