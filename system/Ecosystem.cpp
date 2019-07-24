#include "stdafx.h"
#include "Ecosystem.h"
#include<iostream>
using namespace std;


Ecosystem::Ecosystem()
{

}


Ecosystem::~Ecosystem()
{
	for (int i = 0; i < info.size(); i++)
	{
		delete info[i];
	}
	info.clear();
}


void Ecosystem::cin_num()
{
	Push(0, 60);
	SetColor(13);
	cout << "生态系统v3.0" << endl;
	Push(3, 60);
	SetColor(10);
	cout << "请输入必须的生态系统参数" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	SetColor(3);
	cout << "植物数目" << endl;
	cin >> num_grass;
	SetColor(15);
	cout << "羊数目" << endl;
	cin >> num_sheep;
	SetColor(12);
	cout << "狼数目" << endl;
	cin >> num_wolf;

}


void Ecosystem::animalplant()
{
	for (int i = 0; i < num_grass; i++)
	{
		Grass *p = new Grass;
		int x, y;
		while (1)
		{
			int t = 0;
			x = rand() % 33 + 1;
			y = (rand() % 58 + 1) * 2;
			for (int i = 0; i < info.size(); i++)
			{
				if (x == info[i]->putx() && info[i]->puty() == y)//判断点是否存在生物
				{
					t++;
					break;
				}
			}
			if (t == 0) break;
		}
		p->getx(x);
		p->gety(y);

		Push(p->putx(), p->puty());
		p->animalshow();
		SetColor(3);
		info.push_back(p);
	}
	for (int i = 0; i < num_sheep; i++)
	{
		Sheep *p = new Sheep;
		int x, y;
		while (1)
		{
			int t = 0;
			x = rand() % 33 + 1;
			y = (rand() % 58 + 1) * 2;
			for (int i = 0; i < info.size(); i++)
			{
				if (x == info[i]->putx() && info[i]->puty() == y)
				{
					t++;
					break;
				}
			}
			if (t == 0) break;
		}
		p->getx(x);
		p->gety(y);
		Push(p->putx(), p->puty());
		p->animalshow();
		SetColor(15);
		info.push_back(p);
	}

	for (int i = 0; i < num_wolf; i++)
	{
		Wolf *p = new Wolf;
		int x, y;
		while (1)
		{
			int t = 0;
			x = rand() % 33 + 1;
			y = (rand() % 58 + 1) * 2;
			for (int i = 0; i < info.size(); i++)
			{
				if (x == info[i]->putx() && info[i]->puty() == y)
				{
					t++;
					break;
				}
			}
			if (t == 0) break;
		}
		p->getx(x);
		p->gety(y);
		Push(p->putx(), p->puty());
		p->animalshow();
		SetColor(12);
		info.push_back(p);
	}
}


int Ecosystem::E_orientation(int a, int b)
{
	int t;
	while (1)
	{
		int l = 0;
		int x = a;
		int y = b;

		t = rand() % 4;
		switch (t)
		{
		case 0:x += 1; break;
		case 1:x -= 1; break;
		case 2:y -= 2; break;
		case 3:y += 2; break;
		}

		if (x <= 0 || y <= 0 || y >= 118 || x >= 34)  continue;
		for (int i = 0; i < info.size(); i++)
		{
			if (info[i]->putx() == x && info[i]->puty() == y)//随机运动点与原点相同
			{
				l++;
				break;
			}
		}
		if (l == 0)
			break;
	}
	return t;
}
void Ecosystem::worktime(int i)
{
	time = i;
	if (time % 4 == 0)//4周期一循环 有1/10的草有繁殖能力
	{
		for (int i = 0; i < num_grass / 10; i++)
			grass_reproduce();
	}

}
int  Ecosystem::E_time()
{
	return time;
}


void Ecosystem::run()
{
	for (int i = 0; i < info.size(); i++)
	{


		if (info[i]->s_reproduce())//具有繁殖能力
		{
			if (info[i]->s_name() == "羊"&&info[i]->s_life() >= 10)
				sheep_reproduce();
			if (info[i]->s_name() == "狼"&&info[i]->s_life() >= 7)
				wolf_reproduce();
		}

		//取生物坐标
		int x = info[i]->putx();
		int y = info[i]->puty();
		int t = 0;//吃草数目
		if (info[i]->s_name() == "羊")
		{
			for (int j = 0; j < info.size(); j++)
			{
				if (info[i]->putx() == info[j]->putx() && info[i]->puty() == info[j]->puty()) continue;
				if (info[j]->s_name() == "草")
					if (info[j]->putx() <= x +info[i]->s_scope() && info[j]->putx() >= x - info[i]->s_scope() && info[j]->puty() <= y + info[i]->s_scope() * 2 && info[j]->puty() >= y - info[i]->s_scope() * 2)
					{
						info[i]->prey(info[j]->putx(), info[j]->puty());
						t++;
						num_grass--;
						vector<Biogeocenose*>::iterator it = info.begin() + j;//清除捕食生物原点信息
						info.erase(it);//删除容器中元素
						break;
					}
			}
			if (t == 0)
			{
				int T = E_orientation(info[i]->putx(), info[i]->puty());
				info[i]->move(T);
				if (info[i]->s_life() == 0)//衰老死亡
				{
					Push(info[i]->putx(), info[i]->puty());
					cout<<" death_sheep ";
					num_sheep--;//羊死
					vector<Biogeocenose*>::iterator it = info.begin() + i;//清除衰老死亡点信息
					info.erase(it);
				}
			}
		}
		else if (info[i]->s_name() == "狼")
		{
			for (int z = 0; z < info.size(); z++)
			{
				if (info[i]->putx() == info[z]->putx() && info[i]->puty() == info[z]->puty()) continue;
				if (info[z]->s_name() == "羊"&&info[z]->putx() <= x + info[i]->s_scope() && info[z]->putx() >= x - info[i]->s_scope() && info[z]->puty() <= y + info[i]->s_scope() * 2 && info[z]->puty() >= y - info[i]->s_scope() * 2)
				{
					info[i]->prey(info[z]->putx(), info[z]->puty());
					t++;
					num_sheep--;//羊死
					vector<Biogeocenose*>::iterator it = info.begin() + z;
					info.erase(it);
					break;
				}
			}
			if (t == 0)//没吃到羊并且生命周期完结
			{
				int T = E_orientation(info[i]->putx(), info[i]->puty());
				info[i]->move(T);
				if (info[i]->s_life() == 0)
				{
					Push(info[i]->putx(), info[i]->puty());
					cout<<" death_wolf ";
					num_wolf--;
					vector<Biogeocenose *>::iterator it = info.begin() + i;
					info.erase(it);
				}
			}
		}

	}
}


void Ecosystem::cout_num()
{
	Push(3, 125);
	SetColor(3);
	printf("草：%0.3d", num_grass);
	Push(4, 125);
	SetColor(15);
	printf("羊：%0.3d", num_sheep);
	Push(5, 125);
	SetColor(12);
	printf("狼：%0.3d", num_wolf);

	//ver3.1新加功能2.vol_1 文件读写
	Push(7, 150);
	SetColor(15);
	//SetBackColor1();
	ofstream file;
	

	file.open("infomation.text", ios::in);
	if (!file.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	else
	{
		
		Push(8, 125);
		SetColor(115);
		cout << "记录的最终数目:";
		Push(9, 125);
		SetColor(3);
		cout << "草数目：" << num_grass << endl;
		Push(10, 125);
		SetColor(15);
		cout << "羊数目：" << num_sheep << endl;
		Push(11, 125);
		SetColor(12);
		cout << "狼数目：" << num_wolf << endl;
	}
	file.close();

	file.open("infomation.text", ios::out);
	if (!file.is_open())
	{
		cout << "还未存储信息" << endl;
	}
	else
	{
		file << "草数目：" << num_grass << endl;
		file << "羊数目：" << num_sheep << endl;
		file << "狼数目：" << num_wolf << endl;
	}
	file.close();
}

	




void Ecosystem::sheep_reproduce()//随机生成繁殖
{
	Sheep *p = new Sheep;
	int x, y;
	while (1)
	{
		int t = 0;
		x = rand() % 33 + 1;
		y = (rand() % 58 + 1) * 2;
		for (int i = 0; i < info.size(); i++)
		{
			if (x == info[i]->putx() && info[i]->puty() == y)
			{
				t++;
				break;
			}
		}
		if (t == 0) break;
	}
	p->getx(x);//取代原生物点信息
	p->gety(y);
	Push(p->putx(), p->puty());
	p->animalshow();
	info.push_back(p);
	num_sheep++;


}
void Ecosystem::wolf_reproduce()
{
	Wolf *p = new Wolf;
	int x, y;
	while (1)
	{
		int t = 0;
		x = rand() % 33 + 1;
		y = (rand() % 58 + 1) * 2;
		for (int i = 0; i < info.size(); i++)
		{
			if (x == info[i]->putx() && info[i]->puty() == y)
			{
				t++;
				break;
			}
		}
		if (t == 0) break;
	}
	p->getx(x);
	p->gety(y);
	Push(p->putx(), p->puty());
	p->animalshow();
	info.push_back(p);
	num_wolf++;
}

void Ecosystem::grass_reproduce()
{
	Grass *p = new Grass;
	int x, y;
	while (1)
	{
		int t = 0;
		x = rand() % 33 + 1;
		y = (rand() % 58 + 1) * 2;
		for (int i = 0; i < info.size(); i++)
		{
			if (x == info[i]->putx() && info[i]->puty() == y)
			{
				t++;
				break;
			}
		}
		if (t == 0) break;
	}
	p->getx(x);//取代原生物点信息
	p->gety(y);
	Push(p->putx(), p->puty());
	p->animalshow();
	info.push_back(p);
	num_grass++;
}

