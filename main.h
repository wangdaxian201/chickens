#pragma once
#include <graphics.h>
#include "MyChicken.h"
#include "EnemyChicken.h"
#include<vector>
using namespace std;


static bool state; //��Ϸ����״̬��whileѭ��������־
static bool isover=false;//��Ϸ������־
static bool win=false;//��Ϸ�����falseΪ��
static IMAGE enemy_chicken[2][5]; //�з�С����ͼƬ
static IMAGE player[2][4]; //�ҷ�С����ͼƬ
static IMAGE nums[5];//�ȼ���ͼƬ
static IMAGE im_bk;//����ͼƬ
static vector<EnemyChicken> enemys;//�з�С��

static int flush_count=0;//���ڵз�С��������

void init();//���ݳ�ʼ��
void draw(EnemyChicken& obj);//����С��
void draw(MyChicken& obj);
void draw();//�������Ƶз�С��
void enemy_move();//�з�С���ƶ�
void update(MyChicken& me);//������Ϣ
void crash_check(MyChicken& me);//��ײ�ж�
void create_enemy();//�з�С������
void state_check(MyChicken& me);//״̬���
void gameover();//��������