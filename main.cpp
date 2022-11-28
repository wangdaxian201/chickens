#include"main.h"
#include "EasyXPng.h"


void init()
{
	TCHAR filename[50];
	for (int i = 0; i < 5; i++)
	{
		_stprintf_s(filename, _T("./images/enemychicken/left/chicken%d.png"), i);
		loadimage(&enemy_chicken[0][i], filename);
	}
	for (int i = 0; i < 5; i++)
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
	for (int i = 0; i < 5; i++)
	{
		_stprintf_s(filename, _T("./images/nums/0%d.png"), i);
		loadimage(&nums[i], filename);
	}
	loadimage(&im_bk, _T("./images/bk.jpg"));
	mciSendString(_T("open ./music/xianjian.mp3 alias xj"), NULL, 0, NULL);
	//����
	mciSendString(_T("play xj repeat"), NULL, 0, NULL);


	state = true; //��Ϸ��ʼ
	srand((unsigned int)time(NULL)); //��������ӳ�ʼ��
	initgraph(WIN_WIDTH, WIN_HEIGHT); //������
}

void draw(EnemyChicken& obj)
{
	putimagePng(obj.x, obj.y, &(obj.image));
	putimagePng(obj.x + obj.width / 2 - nums[obj.level].getwidth() / 2, obj.y - nums[obj.level].getheight(),
	            &nums[obj.level]);
}

void draw(MyChicken& obj)
{
	putimagePng(obj.x, obj.y, &(obj.image));
	putimagePng(obj.x + obj.width / 2 - nums[obj.level].getwidth() / 2, obj.y - nums[obj.level].getheight(),
	            &nums[obj.level + 1]);
}

void draw()
{
	for (auto it = enemys.begin(); it != enemys.end();)
	{
		if (it->isAlive)
		{
			draw(*it);
			it++;
		}
		else
		{
			it = enemys.erase(it);
		}
	}
}

void enemy_move()
{
	for (auto it = enemys.begin(); it != enemys.end(); it++)
	{
		it->move();
	}
}

void crash_check(MyChicken& me)
{
	for (auto it = enemys.begin(); it != enemys.end(); it++)
	{
		if (me.intersect(*it))
		{
			if (me.level < it->level)
			{
				me.life--;
				it->isAlive = false;
				mciSendString(_T("close a"), NULL, 0, NULL);
				mciSendString(_T("open ./music/a.mp3 alias a"), NULL, 0, NULL);
				mciSendString(_T("play a"), NULL, 0, NULL);
			}
			else
			{
				it->isAlive = false;
				me.score += it->level + 1;
				mciSendString(_T("close j"), NULL, 0, NULL);
				mciSendString(_T("open ./music/j.mp3 alias j"), NULL, 0, NULL);
				mciSendString(_T("play j"), NULL, 0, NULL);
			}
		}
	}
}

void create_enemy()
{
	if (flush_count >= 10)
	{
		flush_count = 0; //��������һ���з�С��
		int isright = rand() % 2;
		int lev = rand() % 5;
		int y = (100 * (rand() % 9)) + 50;
		int x = isright ? 0 - enemy_chicken[isright][lev].getwidth() : WIN_WIDTH;
		enemys.push_back(EnemyChicken(enemy_chicken[isright][lev], x, y, isright, lev));
	}
}

void state_check(MyChicken& me)
{
	if (me.score >= 2 && me.score < 10)
		me.level = 1;
	else if (me.score >= 10 && me.score <= 20)
		me.level = 2;
	else if (me.score > 20)
		me.level = 3;

	if (me.score >= 100) //100��ΪӮ
	{
		isover = true;
		win = true;
	}
	if (me.life <= 0)
	{
		isover = true;
		win = false;
	}
}

void gameover()
{
	if (isover)
	{
		state = false; //ѭ��������־
		// if(win)
		// else
	}
}

void update(MyChicken& me)
{
	cleardevice();
	create_enemy(); //��ʼ���ɵз�С��

	BeginBatchDraw(); //��ʼ��ͼ
	putimage(0, 0, &im_bk); //���Ʊ���
	draw(me); //�����ҷ�С��
	draw(); //���Ƶз�С��
	EndBatchDraw(); //������ͼ

	me.move(); //�ҷ�С���ƶ�
	enemy_move(); //�з�С���ƶ�
	me.image = player[me.isRight][me.level]; //�����ҵ�ͼƬ
	crash_check(me);
	state_check(me);
	Sleep(50);
	flush_count++;
}

int main()
{
	init();
	MyChicken me(player[1][0],WIN_WIDTH / 2, WIN_HEIGHT / 2, 1, 0); //��ʼ���ҷ�С��
	while (state)
	{
		update(me);
	}

	_getch();
	return 0;
}
