#pragma once
#include <graphics.h>

#define WIN_HEIGHT 900 //���ڸ߶�
#define WIN_WIDTH 900   //���ڿ��


static int score; //�÷�
static bool state; //��Ϸ����״̬
static int myLevel;//�ҷ�С���ĵȼ�
class utils
{
public:
	static IMAGE enemy_chicken[5]; //�з�С����ͼƬ
	static IMAGE player[5]; //�ҷ�С����ͼƬ
	static IMAGE im_bk;
	static void init() //��ʼ��
	{
		TCHAR filename[40];
		for (int i = 0; i < 5; i++)
		{
			_stprintf_s(filename, _T("./images/enemychicken/chicken%d.png"), i);
			loadimage(&enemy_chicken[i], filename);
		}
		for (int i = 0; i < 5; i++)
		{
			_stprintf_s(filename, _T("./images/mychicken/chicken%d.png"), i);
			loadimage(&enemy_chicken[i], filename);
		}
		loadimage(&im_bk,_T("./images/jpg"));
		score=0;
		state=true;
		myLevel=0;
	}
};
