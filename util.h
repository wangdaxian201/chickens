#pragma once
#include <graphics.h>

#define WIN_HEIGHT 100 //���ڸ߶�
#define WIN_WIDTH 100   //���ڿ��


static int score = 0; //�÷�
static bool state = true; //��Ϸ����״̬
class util
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
		loadimage(&im_bk,_T("./images/bk.png"));
	}
};
