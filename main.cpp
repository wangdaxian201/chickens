#include "MyChicken.h"
#include "EnemyChicken.h"
#include "util.h"

void init();
void draw();

int main()
{
	srand((unsigned int)time(NULL));//��������ӳ�ʼ��
	init();
	MyChicken me(utils::player[myLevel],WIN_WIDTH/2,WIN_HEIGHT/2);

	return 0;
}

void init()
{
	utils::init();
}
