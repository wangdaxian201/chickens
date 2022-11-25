#include"main.h"
#include "EasyXPng.h"

void init()
{
	TCHAR filename[50];
	for (int i = 0; i < 4; i++)
	{
		_stprintf_s(filename, _T("./images/enemychicken/left/chicken%d.png"), i);
		loadimage(&enemy_chicken[0][i], filename);
	}
	for (int i = 0; i < 4; i++)
	{
		_stprintf_s(filename, _T("./images/enemychicken/right/chicken%d.png"), i);
		loadimage(&enemy_chicken[1][i], filename);
	}
	for (int i = 0; i < 4; i++)
	{
		_stprintf_s(filename, _T("./images/mychicken/left/chicken%d.png"), i);
		loadimage(&player[0][i], filename);
	}
	for (int i = 0; i < 4; i++)
	{
		_stprintf_s(filename, _T("./images/mychicken/right/chicken%d.png"), i);
		loadimage(&player[1][i], filename);
	}
	for (int i = 0; i < 4; i++)
	{
		_stprintf_s(filename, _T("./images/nums/0%d.png"), i);
		loadimage(&nums[i], filename);
	}
	loadimage(&im_bk, _T("./images/bk.jpg"));
	state = true;//��Ϸ��ʼ
	srand((unsigned int)time(NULL));//��������ӳ�ʼ��
	initgraph(WIN_WIDTH, WIN_HEIGHT);//������
}

void draw(object& obj)
{
	
	cleardevice();
	
	putimagePng(obj.x,obj.y,&(obj.image));
}

void update(MyChicken& me)
{
	putimage(0, 0, &im_bk);//����
	draw(me);
	me.image=player[me.isRight][me.level];//�����ҵ�ͼƬ
}

int main()
{
	init();
	MyChicken me(player[1][3],WIN_WIDTH / 2, WIN_HEIGHT / 2,1,3);//��ʼ���ҷ�С��	
	while(state)
	{
		draw(me);
		me.move();
	}

	_getch();
	return 0;
}
