#pragma once
#include <graphics.h>
#include "MyChicken.h"
#include "EnemyChicken.h"

static bool state; //��Ϸ����״̬
static IMAGE enemy_chicken[2][4]; //�з�С����ͼƬ
static IMAGE player[2][4]; //�ҷ�С����ͼƬ
static IMAGE nums[4];
static IMAGE im_bk;

void init();
void draw(object& obj);
void me_update(MyChicken& me);