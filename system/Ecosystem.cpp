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
	cout << "��̬ϵͳv3.0" << endl;
	Push(3, 60);
	SetColor(10);
	cout << "������������̬ϵͳ����" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	SetColor(3);
	cout << "ֲ����Ŀ" << endl;
	cin >> num_grass;
	SetColor(15);
	cout << "����Ŀ" << endl;
	cin >> num_sheep;
	SetColor(12);
	cout << "����Ŀ" << endl;
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
				if (x == info[i]->putx() && info[i]->puty() == y)//�жϵ��Ƿ��������
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
			if (info[i]->putx() == x && info[i]->puty() == y)//����˶�����ԭ����ͬ
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
	if (time % 4 == 0)//4����һѭ�� ��1/10�Ĳ��з�ֳ����
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


		if (info[i]->s_reproduce())//���з�ֳ����
		{
			if (info[i]->s_name() == "��"&&info[i]->s_life() >= 10)
				sheep_reproduce();
			if (info[i]->s_name() == "��"&&info[i]->s_life() >= 7)
				wolf_reproduce();
		}

		//ȡ��������
		int x = info[i]->putx();
		int y = info[i]->puty();
		int t = 0;//�Բ���Ŀ
		if (info[i]->s_name() == "��")
		{
			for (int j = 0; j < info.size(); j++)
			{
				if (info[i]->putx() == info[j]->putx() && info[i]->puty() == info[j]->puty()) continue;
				if (info[j]->s_name() == "��")
					if (info[j]->putx() <= x +info[i]->s_scope() && info[j]->putx() >= x - info[i]->s_scope() && info[j]->puty() <= y + info[i]->s_scope() * 2 && info[j]->puty() >= y - info[i]->s_scope() * 2)
					{
						info[i]->prey(info[j]->putx(), info[j]->puty());
						t++;
						num_grass--;
						vector<Biogeocenose*>::iterator it = info.begin() + j;//�����ʳ����ԭ����Ϣ
						info.erase(it);//ɾ��������Ԫ��
						break;
					}
			}
			if (t == 0)
			{
				int T = E_orientation(info[i]->putx(), info[i]->puty());
				info[i]->move(T);
				if (info[i]->s_life() == 0)//˥������
				{
					Push(info[i]->putx(), info[i]->puty());
					cout<<" death_sheep ";
					num_sheep--;//����
					vector<Biogeocenose*>::iterator it = info.begin() + i;//���˥����������Ϣ
					info.erase(it);
				}
			}
		}
		else if (info[i]->s_name() == "��")
		{
			for (int z = 0; z < info.size(); z++)
			{
				if (info[i]->putx() == info[z]->putx() && info[i]->puty() == info[z]->puty()) continue;
				if (info[z]->s_name() == "��"&&info[z]->putx() <= x + info[i]->s_scope() && info[z]->putx() >= x - info[i]->s_scope() && info[z]->puty() <= y + info[i]->s_scope() * 2 && info[z]->puty() >= y - info[i]->s_scope() * 2)
				{
					info[i]->prey(info[z]->putx(), info[z]->puty());
					t++;
					num_sheep--;//����
					vector<Biogeocenose*>::iterator it = info.begin() + z;
					info.erase(it);
					break;
				}
			}
			if (t == 0)//û�Ե����������������
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
	printf("�ݣ�%0.3d", num_grass);
	Push(4, 125);
	SetColor(15);
	printf("��%0.3d", num_sheep);
	Push(5, 125);
	SetColor(12);
	printf("�ǣ�%0.3d", num_wolf);

	//ver3.1�¼ӹ���2.vol_1 �ļ���д
	Push(7, 150);
	SetColor(15);
	//SetBackColor1();
	ofstream file;
	

	file.open("infomation.text", ios::in);
	if (!file.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	else
	{
		
		Push(8, 125);
		SetColor(115);
		cout << "��¼��������Ŀ:";
		Push(9, 125);
		SetColor(3);
		cout << "����Ŀ��" << num_grass << endl;
		Push(10, 125);
		SetColor(15);
		cout << "����Ŀ��" << num_sheep << endl;
		Push(11, 125);
		SetColor(12);
		cout << "����Ŀ��" << num_wolf << endl;
	}
	file.close();

	file.open("infomation.text", ios::out);
	if (!file.is_open())
	{
		cout << "��δ�洢��Ϣ" << endl;
	}
	else
	{
		file << "����Ŀ��" << num_grass << endl;
		file << "����Ŀ��" << num_sheep << endl;
		file << "����Ŀ��" << num_wolf << endl;
	}
	file.close();
}

	




void Ecosystem::sheep_reproduce()//������ɷ�ֳ
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
	p->getx(x);//ȡ��ԭ�������Ϣ
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
	p->getx(x);//ȡ��ԭ�������Ϣ
	p->gety(y);
	Push(p->putx(), p->puty());
	p->animalshow();
	info.push_back(p);
	num_grass++;
}

