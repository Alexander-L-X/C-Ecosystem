#pragma once
class Ecosystem
{
private:
	int time; //时间周期
	int num_grass;//▓草数目
	int num_sheep;//羊数目
	int num_wolf;//狼数目
	vector<Biogeocenose*>info;
	friend class Sheep;
	friend class Wolf;
	friend class Grass;
public:
	Ecosystem();
	~Ecosystem();
	void cin_num();//输入生物的数目
	void animalplant();//建立动植物生产函数
	void run();//执行循环
	void cout_num();//输出动植物数目事件
	void grass_reproduce();//草繁殖时间
	void sheep_reproduce();//羊繁殖时间
	void wolf_reproduce();//狼繁殖时间
	void worktime(int i);//运行时间周期
	int E_time();//时间
	int E_orientation(int x, int y);//物种移动方向

};

