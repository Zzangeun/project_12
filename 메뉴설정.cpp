#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>

int menu_display(void);
int sub_background(void);
void sub_back01(void);
int sub_bubble(void);
void sub_bub01(void);
int sub_word(void);
void sub_word01(void);
void background(void);
void bubble(void);
void word(void);
int a;

void fore_red(void);
void fore_black(void);
void fore_green(void);
void fore_white(void);
void fore_blue(void);
//void back_red(void);
void press_any_key(void);


int main(void)
{
	int c;
	while ((c = menu_display()) != 4)
	{
		switch (c)
		{
		case 1:sub_back01();
			break;
		case 2: sub_bub01();
			break;
		case 3: sub_word01();
			break;
		default: break;
		}
	}
	return 0;
}
int menu_display(void)
{
	int select;

	system("cls");
	printf("환경설정\n\n");
	printf("1.배경색 변경\n");
	printf("2.방울색 변경\n");
	printf("3.글자색 변경\n");
	printf("4.설정 종료\n\n");
	printf("번호 입력");
	select = getchar() - 48;
	return select;
}
void sub_back01(void)
{
	int c;
	while ((c = sub_background()) != 3)
	{
		switch (c)
		{
		case 1: back_red();
			break;
		default: break;
		}
	}
}
int sub_background(void)
{
	int select;
	system("cls");
	printf("배경색 변경\n\n");
	printf("1. 빨강색\n");
	printf("2.메인메뉴로 이동\n\n");
	printf("메뉴번호 입력>");
	select = getchar() - 48;
	return select;
}
void back_red(void)
{
	system("cls");
	int i = 7;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}



void sub_bub01(void)
{
	int c;
	while ((c = sub_bubble()) != 3)
	{
		switch (c)
		{
		case 1: fore_red();
			break;
		default: break;
		}
	}
}
void fore_red(void)
{
	system("cls");
	int i = 4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void fore_blue(void)
{
	system("cls");
	int i = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void fore_black(void)
{
	system("cls");
	int i = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void fore_green(void)
{
	system("cls");
	int i = 2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void fore_white(void)
{
	system("cls");
	int i = 7;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
int sub_bubble(void)
{
	int select;
	system("cls");
	printf("방울색 변경\n\n");
	printf("1.흰색\n");
	printf("2.메인메뉴로 이동\n\n");
	printf("메뉴번호 입력>");
	select = getchar() - 48;
	return select;
}
void sub_word01(void)
{
	int c;
	while ((c = sub_word()) != 6)
	{
		switch (c)
		{
		case 1: fore_red();
			break;
		case 2: fore_blue();
			break;
		case 3: fore_green();
			break;
		case 4: fore_black();
			break;
		case 5: fore_white();
			break;
		default: break;
		}
	}
}
int sub_word(void)
{
	int select;
	system("cls");
	printf("글자색 변경\n\n");
	printf("1.빨간색\n");
	printf("2.파란색\n");
	printf("3.초록색\n");
	printf("4.검정색\n");
	printf("5.흰색\n");
	printf("6.메인메뉴로 이동\n\n");
	printf("메뉴번호 입력>");
	select = getchar() - 48;
	return select;
}
void press_any_key(void)
{
	printf("\n\n");
	printf("아무키나 누르면 이젠 메뉴로");
	getchar();
}