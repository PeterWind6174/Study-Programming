#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "interface.h"
#include "snake.h"

int main(void)
{
	struct snake a[(M - 2) * (N - 2)];
	int snake_x = 4;
	int snake_y = 4;
	int X = 1;
	int Y = 0;
	int food_x, food_y;
	int score = 0;

	do {
		food_x = 1 + rand() % (N - 3);
		food_y = 1 + rand() % (M - 3);
	} while (food_x == 4 && food_y == 4);

	for (;;)
	{
		system("cls");
		printf("\n                       ̰����С��Ϸ");
		printf("��W���������˶�����D���������˶�����S���������˶�����A���������˶���\n");
		printf("�÷֣�%d", score);
		printf("\n");

		control(&snake_x, &snake_y, &X, &Y);
		build_snake(a, score, &snake_x, &snake_y);
		death(snake_x, snake_y, score);
		newinterface(a, food_x, food_y, score);
		food(&snake_x, &snake_y, &food_x, &food_y, &score, a);
		draw();
		Sleep(140);
	}
	system("pause");
	return 0;
}