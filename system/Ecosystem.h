#pragma once
class Ecosystem
{
private:
	int time; //ʱ������
	int num_grass;//������Ŀ
	int num_sheep;//����Ŀ
	int num_wolf;//����Ŀ
	vector<Biogeocenose*>info;
	friend class Sheep;
	friend class Wolf;
	friend class Grass;
public:
	Ecosystem();
	~Ecosystem();
	void cin_num();//�����������Ŀ
	void animalplant();//������ֲ����������
	void run();//ִ��ѭ��
	void cout_num();//�����ֲ����Ŀ�¼�
	void grass_reproduce();//�ݷ�ֳʱ��
	void sheep_reproduce();//��ֳʱ��
	void wolf_reproduce();//�Ƿ�ֳʱ��
	void worktime(int i);//����ʱ������
	int E_time();//ʱ��
	int E_orientation(int x, int y);//�����ƶ�����

};

