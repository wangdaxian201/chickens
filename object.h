#pragma once
#include<graphics.h>
#include<conio.h>
#include<time.h>
#define WIN_HEIGHT 800 //���ڸ߶�
#define WIN_WIDTH 1600   //���ڿ��
class object
{
public:
	object(IMAGE& image, int x, int y)
	{
		this->image = image;
		this->x = x;
		this->y = y;
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
