//��̬ϵͳ������Ϣ
#pragma once
#include"stdafx.h"
using namespace std;
class Biogeocenose
{
public:
	Biogeocenose();
	~Biogeocenose();

	int range_x;//����x
	int range_y;//����y
	//���ֻ�����Ϣ
	int age;//����
	int life;//����ֵ
	int scope;//��ʳ��Χ
	bool reproduce;//��ֳ��
	int orientation;//�˶���λ 0�� 1�� 2�� 3��

	string name;//��������

				//�������������
	void getx(int x);//����x
	void gety(int y);//����y
	int putx();
	int puty();

	void move(int z);//�˶��켣
	virtual void animalshow();//�����������ֲ�
	virtual void prey(int x, int y);//��ʳ


	int s_scope();
	int s_life();
	bool s_reproduce();

	string s_name();

	
};

