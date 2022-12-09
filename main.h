#pragma once
#include <graphics.h>
#include "MyChicken.h"
#include "EnemyChicken.h"
#include "Boss.h"
#include "Bullet.h"
#pragma comment(lib,"Winmm.lib")


static int state; //��Ϸ����״̬��whileѭ��������־,0Ϊ������1�ǿ�ʼ���棬2��û��boss��3�ǳ���boss,4�ǽ�������
static bool isover=false;//��Ϸ������־
static bool win=false;//��Ϸ�����falseΪ��
static IMAGE enemy_chicken[2][5]; //�з�С����ͼƬ
static IMAGE player[2][4]; //�ҷ�С����ͼƬ
static IMAGE nums[5];//�ȼ���ͼƬ
static IMAGE im_bk;//����ͼƬ
static IMAGE im_boss;//bossͼƬ
static IMAGE im_myBullet;//�ӵ�ͼƬ
static IMAGE im_bossBullet;//�ӵ�ͼƬ
static IMAGE im_win;//ʤ��ͼƬ
static IMAGE im_lose;//ʧ��ͼƬ
static IMAGE im_start;//��ʼ����
static vector<EnemyChicken> enemys;//�з�С��
static MyChicken me;//�ҷ�С��
static Boss boss;//boss
static vector<Bullet> boss_bullets;//boss�ӵ�
static vector<Bullet> my_bullets;//�ҷ��ӵ�

static int flush_count=0;//���ڵз�С��������

void init();//���ݳ�ʼ��
void draw(EnemyChicken& obj);//����С��
void draw(MyChicken& obj);//�����ҷ�С��
void draw();//�������Ƶз�С��
void enemy_move();//�з�С���ƶ�
void update();//������Ϣ
void crash_check();//��ײ�ж�
void create_enemy();//�з�С������
void state_check();//״̬���
void gameover();//��������
void text_show();
void bullet_show(MyChicken& me_chicken);
void bullet_show(Boss& boss_bu);
void shoot(MyChicken& mc);
void shoot(Boss& b);
