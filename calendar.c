#include "calendar.h"
/*
int main(void)
{
	MainC();	
}
*/
void Calendar()
{
	int i = 0, j = 0;
	int x = CaX, y = CaY;
	int key;

	Month month_2019;

	srand(time(NULL));
	system("mode con cols=150 lines=40");

	DrawC();
	MoveC(&x, &y);
	gotoxy(10, 80);

	while(1)
	{ 
		key = getch();
		if (key == 224)
		{
			key = getch();
			switch (key)
			{
			case 72: //위
				if(y >= CaY)
				{
					day[month - 1] -= 7;
					y -= 3;
				}
				break;
			case 80: //아래
				if (y < CaY)
				{
					rightleft = 0;
				}
				if (y != CaY + 3 * 4)
				{
					y += 3;
					day[month-1] += 7;
				}
				break;
			case 75: //왼쪽
				/*
				if (x == CaX)
				{
					if (y != CaY)
					{
						x = CaX + 7 * 6;
						y -= 3;
					}
				}
				else
				{
					x -= 7;
				}
				*/
				if (y >= CaY)
				{
					x -= 7;
					day[month - 1] -= 1;
				}
				else
					rightleft = -1;

				break;
			case 77: //오른쪽
				/*
				if (x == CaX + 7 * 6)
				{
					if (y != CaY + 3 * 4)
					{
						x = CaX;
						y += 3;
					}
					else
						day[month-1] -= 1;
				}
				else
				{
					x += 7;
				}
				*/

				if (y >= CaY)
				{
					x += 7;
					day[month - 1] += 1;
				}
				else
					rightleft = 1;

				break;
			}
		}
		else if (key == 13)
		{
			if (y < CaY)
			{
				if (rightleft == 1)
				{
					month += 1;
				}
				else if (rightleft == -1)
				{
					month -= 1;
				}
			}
			else
			{
				PrintDetailC_C();
			}
		}
		system("cls");
		DrawC();
		MoveC(&x, &y);
	}
}

void DrawC()
{
	int row = 5, column = 7;
	int i, j, k;

	
	//─│┌┐┘└├┬┤┴┼ㅂ

	/*
	printf("    ");
	printf("-");
	printf("    ");
	*/
	gotoxy(CaX, CaY);
	printf("%c%c ", a, b[2]);
	for (i = 1; i <= 6; i++)
	{
		gotoxy(CaX + i*7, CaY);
		printf("%c%c ", a, b[7]);
	} 
	gotoxy(CaX + i * 7, CaY);
	printf("%c%c ", a, b[3]);

	// 첫번째 두번째
	for (k = 1; k <= 4; k++)
	{
		gotoxy(CaX, CaY + k * 3);
		printf("%c%c ", a, b[6]);
		for (i = 1; i <= 6; i++)
		{
			gotoxy(CaX + i * 7, CaY + k * 3);
			printf("%c%c ", a, b[10]);
		} 
		gotoxy(CaX + i * 7, CaY + k * 3);
		printf("%c%c ", a, b[8]);
	}
	//세번째 네번째

	gotoxy(CaX, CaY+15);
	printf("%c%c ", a, b[5]);
	for (i = 1; i <= 6; i++)
	{
		gotoxy(CaX + i * 7, CaY + 15);
		printf("%c%c ", a, b[9]);
	}
	gotoxy(CaX + i * 7, CaY + 15);

	printf("%c%c ", a, b[4]);
	printf("\n\n");

	DrawM();
	PrintContent();
	PrintDetailC_M();
}

void DrawM()
{
	int i, j, k;
	int a = 21, b = 7;
	gotoxy(CaX + a + 2, CaY - b - 2);
	printf("2019년");
	gotoxy(CaX + a - 4, CaY - b + 4);
	printf("◁");
	gotoxy(CaX + a + 15, CaY - b + 4);
	printf("▷");

	gotoxy(CaX + a + 10, CaY - b + 4);
	printf("월");

	if (month == 1)
		a = 20;

	for (i = 0; i < 5; i++)
	{
		gotoxy(CaX + a + 1, CaY - b + i);
		for (j = 0; j < 4; j++)
			printf("%s", digit[month][i][j]);
	}
}

void PrintContent()
{
	int i = 0, j = 0;
	int col = CaX + 2, line = CaY + 1, count = 1, day_count = 1;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 7; j++)
		{
			gotoxy(col, line);

			if (count == Month_day.start[month-1])
			{
				printf("%d", day_count);
				day_count++;
			}
			else
				count++;
			if (day_count > Month_day.end[month-1])
				break;
			/*
			if (rand() % 6 == 1)
			{
			gotoxy(col + 4, line);
			printf("☆");
			gotoxy(col + 0, line + 1);
			printf("기념일");
			}
			else if (rand() % 8 == 2)
			{
			gotoxy(col + 4, line);
			printf("§");
			gotoxy(col + 1, line + 1);
			printf("행사");
			}
			*/
			col += 7;
		}
		if (day_count > Month_day.end[month])
			break;
		col = CaX + 2;
		line += 3;
	}

}

void PrintDetailC_M()
{
	int i, j;

	gotoxy(DeX, DeY);
	printf("┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ┯ ");

	if (day[month-1] < 1 || day[month-1] > 31)
		return;
	else
	{
		for (i = 0; i < 5; i++)
		{
			gotoxy(DeX, DeY + 1 + i);
			if (day[month-1] >= 10)
			{
				if (day[month-1] / 10 == 1)
					gotoxy(DeX - 3, DeY + 1 + i);

				for (j = 0; j < 4; j++)
					printf("%s", digit[day[month-1]/10+10][i][j]);

				if (day[month-1] / 10 == 1)
					gotoxy(DeX +4, DeY + 1 + i);
				else
					gotoxy(DeX+7, DeY + 1 + i);

				for (j = 0; j < 4; j++)
					printf("%s", digit[day[month-1]%10+10][i][j]);
			}
			else
			{
				for (j = 0; j < 4; j++)
					printf("%s", digit[day[month-1]][i][j]);
			}
		}
	}

	if (detail_sort[month][day[month-1]] != 0)
	{
		gotoxy(DeX, DeY + 6);
		printf("%s", detail_sort[month][day[month-1]]);
	}
}
void PrintDetailC_C()
{
	char mun[50];
	int i = 0 ;
	

	while(1)
	{
		gotoxy(DeX+i, DeY + 6);

		mun[i] = getch();
		if (mun[i] == 13)
			break;

		if (mun[i] == 8)
		{
			mun[i] = 0;
			if (i != 0)
			{
				i--;
				printf("\b \b");
			}
		}
		else
		{
			printf("%c", mun[i]);
			i++;
		}
	}

	strcpy(detail_sort[month][day[month-1]], mun);
}



int MoveC(int * x, int * y)
{

	int i = 0;
	int a = 21, b = 7;

	if (*y < CaY)
	{

		if (rightleft == 0)
		{
			gotoxy(CaX + a - 4, CaY - b + 4);
			printf("◀");
		}
		else 
		{
			if (rightleft == 1)
			{
				gotoxy(CaX + a - 4, CaY - b + 4);
				printf("◁");
				gotoxy(CaX + a + 15, CaY - b + 4);
				printf("▶");
			}
			else if (rightleft == -1)
			{
				gotoxy(CaX + a + 15, CaY - b + 4);
				printf("▷");
				gotoxy(CaX + a - 4, CaY - b + 4);
				printf("◀");
			}

		}
		return;
	}
	
	gotoxy(*x, *y);

	printf("╋");
	printf("━ ━ ━ ");
	printf("╋");//┱
	gotoxy(*x, *y + 3);
	printf("╋"); //┡
	printf("━ ━ ━ ");
	printf("╋");//╃
	for (i = 1; i < 3; i++)
	{
		gotoxy(*x, *y + i);
		printf("┃ ");
	}
	for (i = 1; i < 3; i++)
	{
		gotoxy(*x + 7, *y + i);
		printf("┃ ");
	}
	return 0;
}

