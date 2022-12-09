#pragma once
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<vector>

#define WIN_HEIGHT 800 //���ڸ߶�
#define WIN_WIDTH 1600   //���ڿ��
#define BOSS_LIFE 5	//boss����ֵ
#define MY_LIFE 10  //�ҵ�����ֵ
#define BULLET_WIDTH 25
#define BULLET_HEIGHT 25

using namespace std;


class object
{
public:
	object() = default;
	object(IMAGE& image, int x, int y)
	{
		this->image = image;
		this->x = x;
		this->y = y;
		this->width=image.getwidth();
		this->height=image.getheight();
	}


	bool intersect(object& object)
	{
		return x <= object.x + object.width && x + width >= object.x && y <= object.y + object.height && y
			+ height >= object.y;
	}

	void move();

public:
	IMAGE image; //��ͼ
	int x, y; //����
	int width, height; //�߶ȿ��
	int level;//�ȼ�
	bool isAlive =true;//�Ƿ����
};
