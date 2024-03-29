// 生态系统.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Ecosystem.h"
#include "startinterface.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SetBackColor1();
	system("mode con cols=160 lines=40");//定义界面大小
	SetConsoleTitle(L"生态系统");//修改控制台的标题
	
	SetColor(7);//设置开始动画颜色
	startInterface *start = new startInterface();//动态分配一个StartInterface类start
	start->Action();//开始动画
	delete start;//释放内存空间

	Ecosystem in;
	in.cin_num();
	int time;
	Push(15, 0);
	SetColor(6);
	cout<<"请输入运行周期"<<endl;
	cin >> time;

	system("cls");//清除原界面信息
	edgemap();
	Push(7, 125);
	in.animalplant();//创建成员
	for (int i = 0; i < time; i++)
	{
		in.worktime(i);
		in.run();
		in.cout_num();
		Push(6, 125);
		SetColor(26);
		printf("运行周期：%d", i + 1);
		Sleep(1000);

	}
	system("pause");
	return 0;
}


