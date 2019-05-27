#include "config.h"
char string[3] = "07";
//const char arrow[3] = "��";
//int worktype = 0;

/*void setColor(unsigned short text, unsigned short back)
{
	setConsoleTextAtrribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}*/

int main(void)
{
	/*
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
	*/

	Menu_SelectMenu();
	if (worktype == 4) {
		int c;

		while ((c = menu_display()) != 4)
		{
			switch (c)
			{
			case 1:sub_back01();
				break;
				//case 2: sub_bub01();
					//break;
			case 2: sub_word01();
				break;
			case 3:
				Menu_SelectMenu();
				break;
			}
		}
		return 0;
	}
}
int menu_display(void)
{
	int select;
	int y1 = 0;
	int key;

	do {
		printf("  배경색 변경\n");
		//printf("  2.방울색 변경\n");
		printf("  글자색 변경\n");
		printf("  설정 종료\n\n");
		Menu_draw_arrow(y1);
		key = getch();
		Menu_move_arrow_key(key, &y1, 2);
		system("cls");
	} while (key != 13);

	select = y1 + 1;

	return select;
}

void sub_back01(void)
{
	int c;
	
	while ((c = sub_background()) != 3)
	{
		back_color(c);
		/*switch (c)
		{
		case 1: back_red(c);
			break;
		default: return menu_display();
		}*/
	}
}
int sub_background(void)
{
	int select;
	int y1 = 0;
	int key;
	do {
		printf("1. 빨강색\n");
		printf("2.메인메뉴로 이동\n\n");
		//printf("�޴���ȣ �Է�>");
		Menu_draw_arrow(y1);
		key = getch();
		Menu_move_arrow_key(key, &y1, 1);
		system("cls");
	} while (key != 13);

	select = y1 + 1;

	return select;
}
void back_color(int type)
{
	system("cls");
	char dos_command[9];

	switch (type) {
	case 1:
		string[0] = '4';
		break;
	case 2:
		string[0] = '1';
		break;
	
	}
	sprintf(dos_command, "color %s", string);

	system(dos_command);
}

/*void back_red(int type)
{
	system("cls");
	char dos_command[9];

	//scanf_s("%c", &string[0]);
	string[0] = '4';

	sprintf(dos_command, "color %s", string);

	system(dos_command);
	//unsigned short text = 7;
	//unsigned short back = 4;

	//setColor(text, back);
	//return 0;

}*/



/*void sub_bub01(void)
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
}*/

void word_color(int type) {
	system("cls");
	char dos_command[9];

	switch (type) {
	case 1:
		string[1] = '4';
		break;
	case 2:
		string[1] = '1';
		break;
	case 3:
		string[1] = '2';
		break;
	case 4:
		string[1] = '0';
		break;
	case 5:
		string[1] = '7';
		break;
	}
	sprintf(dos_command, "color %s", string);

	system(dos_command);
}

/*void fore_red(void)
{
	system("cls");
	char dos_command[9];

	string[1] = '4';

	sprintf(dos_command, "color %s", string);

	system(dos_command);
}
void fore_blue(void)
{
	system("cls");

	char dos_command[9];

	string[1] = '1';

	sprintf(dos_command, "color %s", string);

	system(dos_command);
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
}*/
int sub_bubble(void)
{
	int select;
	system("cls");
	printf("���� ����\n\n");
	printf("1.���\n");
	printf("2.���θ޴��� �̵�\n\n");
	printf("�޴���ȣ �Է�>");
	select = getchar() - 48;
	return select;
}
void sub_word01(void)
{
	int c;
	while ((c = sub_word()) != 6)
	{
		word_color(c);
		/*
		switch (c)
		{
		case 1: fore_red(c);
			break;
		case 2: fore_blue(c);
			break;
		case 3: fore_green(c);
			break;
		case 4: fore_black(c);
			break;
		case 5: fore_white(c);
			break;
		default: break;
		}
		*/
		//}
	}
}
int sub_word(void)
{
	int select;
	int y1 = 0;
	int key;
	do {
		system("cls");
		//printf("���ڻ� ����\n\n");
		printf("1.빨간색\n");
		printf("2.파란색\n");
		printf("3.초록색\n");
		printf("4.검정색\n");
		printf("5.흰색\n");
		printf("6.메인메뉴로 이동\n\n");
		//printf("�޴���ȣ �Է�>");
		Menu_draw_arrow(y1);
		key = getch();
		Menu_move_arrow_key(key, &y1, 5);
		system("cls");
	} while (key != 13);

	select = y1 + 1;

	return select;
	//select = getchar() - 48;
	//return select;
}
void press_any_key(void)
{
	printf("\n\n");
	printf("�ƹ�Ű�� ������ ���� �޴���");
	getchar();
}