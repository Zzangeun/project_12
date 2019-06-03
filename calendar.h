#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "menu.h"

#define CaX 10	//41
#define CaY 15	//1
#define DeX 80
#define DeY 13
void Calendar(); //����Ķ����
void DrawC(); //Ķ�����׸����Լ�
void PrintAllC();//��üĶ��������
void PrintDetailC_M();//����Ķ���� �� ���
void PrintDetailC_C();//����Ķ���� ���� ���
void D_Day();//D-Day, ��������
void AllDB();//��üĶ����DB

void MainMenu();//���θ޴��̵�
void PrintContent();//�������
void PrintD_Day(); //D-Day ���
void DBUp(); //DB ������Ʈ

void DrawM(); //�� ���
int MoveC(int * x, int * y); //Ķ���� �̵� �ڱ�

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}


int rightleft = 0;
int month = 1;
int day[12] = { -1, -4, -4, 0, -2, -5, 0, -3, 1, -1, -4, 1 };
unsigned char a = 0xa6;
unsigned char b[12] = { '��','��','��','��','��','��','��','��','��','��','��',' ' };

typedef struct
{
	int start[12];
	int end[12];
}Month;

Month Month_day = { {3, 6, 6, 2, 4, 7, 2, 5, 1, 3, 6, 1 }, {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

char * detail_sort[12][31] = { 0 };

char * digit[20][5][4] =//0~9���� ����� ����
{
	{
		{ "��","��","��","��" },
		{ "��","  ","  ","��" },
		{ "��","  ","  ","��" },
		{ "��","  ","  ","��" },
		{ "��","��","��","��" }
	},
	{
		{ "  ","  ","��","  "},
		{ "  ","  ","��","  "},
		{ "  ","  ","��","  "},
		{ "  ","  ","��","  "},
		{ "  ","  ","��","  "}
	},
	{
		{ "��","��","��","��" },
		{ "  ","  ","  ","��" },
		{ "��","��","��","��" },
		{ "��","  ","  ","  " },
		{ "��","��","��","��" }
	},
	{
		{ "��","��","��","��" },
		{ "  ","  ","  ","��" },
		{ "��","��","��","��" },
		{ "  ","  ","  ","��" },
		{ "��","��","��","��" }
	},
	{
		{ "��","  ","  ","��" },
		{ "��","  ","  ","��" },
		{ "��","��","��","��" },
		{ "  ","  ","  ","��" },
		{ "  ","  ","  ","��" }
	},
	{
		{ "��","��","��","��" },
		{ "��","  ","  ","  " },
		{ "��","��","��","��" },
		{ "  ","  ","  ","��" },
		{ "��","��","��","��" },
	},
	{
		{ "��","��","��","��" },
		{ "��","  ","  ","  " },
		{ "��","��","��","��" },
		{ "��","  ","  ","��" },
		{ "��","��","��","��" }
	},
	{
		{ "��","��","��","��" },
		{ "��","  ","  ","��" },
		{ "  ","  ","  ","��" },
		{ "  ","  ","  ","��" },
		{ "  ","  ","  ","��" }
	},
	{
		{ "��","��","��","��" },
		{ "��","  ","  ","��" },
		{ "��","��","��","��" },
		{ "��","  ","  ","��" },
		{ "��","��","��","��" }
	},
	{
		{ "��","��","��","��" },
		{ "��","  ","  ","��" },
		{ "��","��","��","��" },
		{ "  ","  ","  ","��" },
		{ "  ","  ","  ","��" }
	},
	{
		{ "��","��","��","  " },
		{ "��","  ","��","  " },
		{ "��","  ","��","  " },
		{ "��","  ","��","  " },
		{ "��","��","��","  " }
	},
	{
		{ "  ","  ","��","  " },
		{ "  ","  ","��","  " },
		{ "  ","  ","��","  " },
		{ "  ","  ","��","  " },
		{ "  ","  ","��","  " },
	},
	{
		{ "��","��","��","  " },
		{ "  ","  ","��","  " },
		{ "��","��","��","  " },
		{ "��","  ","  ","  " },
		{ "��","��","��","  " }
	},
	{
		{ "��","��","��","  " },
		{ "  ","  ","��","  " },
		{ "��","��","��","  " },
		{ "  ","  ","��","  " },
		{ "��","��","��","  " },
	},
	{
		{ "��","  ","��","  " },
		{ "��","  ","��","  " },
		{ "��","��","��","  " },
		{ "  ","  ","��","  " },
		{ "  ","  ","��","  " },
	},
	{
		{ "��","��","��","  " },
		{ "��","  ","  ","  " },
		{ "��","��","��","  " },
		{ "  ","  ","��","  " },
		{ "��","��","��","  " },
	},
	{
		{ "��","��","��","  " },
		{ "��","  ","  ","  " },
		{ "��","��","��","  " },
		{ "��","  ","��","  " },
		{ "��","��","��","  " },
	},
	{
		{ "��","��","��","  " },
		{ "��","  ","��","  " },
		{ "  ","  ","��","  " },
		{ "  ","  ","��","  " },
		{ "  ","  ","��","  " },
	},
	{
		{ "��","��","��","  " },
		{ "��","  ","��","  " },
		{ "��","��","��","  " },
		{ "��","  ","��","  " },
		{ "��","��","��","  " },
	},
	{
		{ "��","��","��","  " },
		{ "��","  ","��","  " },
		{ "��","��","��","  " },
		{ "  ","  ","��","  " },
		{ "  ","  ","��","  " },
	}
};
