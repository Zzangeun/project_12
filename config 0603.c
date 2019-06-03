#include "config.h"
char string[3] = "07";


int main(void)
{
	system("mode con cols=150 lines=40");
	
	Menu_SelectMenu();
	if (worktype == 4) {
		int c;

		while ((c = menu_display()) != 4)
		{
			switch (c)
			{
			case 1:sub_back01();
				break;
			case 2: sub_word01();
				break;
			case 3:
				Menu_SelectMenu();
				break;
			}
			system("mode con cols=150 lines=40");
			FILE *fp = fopen("bubble_it.txt", "w");
			fprintf(fp, "%s", string);
			fclose(fp);
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
		gotoxy(70, 19);
		printf("  배경색 변경\n");
		gotoxy(70, 21);
		printf("  글자색 변경\n");
		gotoxy(70, 23);
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

	while ((c = sub_background()) != 6)
	{
		back_color(c);
	}
}
int sub_background(void)
{
	int select;
	int y1 = 0;
	int key;
	do {
		gotoxy(70, 14);
		printf("   빨강색\n");
		gotoxy(70, 16);
		printf("   파란색\n");
		gotoxy(70, 18);
		printf("   초록색\n");
		gotoxy(70,20);
		printf("   검정색\n");
		gotoxy(71, 22);
		printf("   흰색\n");
		gotoxy(66, 24);
		printf("   메인메뉴로 이동\n\n");
		Menu_draw_arrow(y1);
		key = getch();
		Menu_move_arrow_key(key, &y1, 5);
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
	case 3:
		string[0] = '2';
		break;
	case 4:
		string[0] = '0';
		break;
	case 5:
		string[0] = '7';
		break;

	}
	sprintf(dos_command, "color %s", string);

	system(dos_command);
}

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


void sub_word01(void)
{
	int c;
	while ((c = sub_word()) != 25)
	{
		word_color(c);
	}
}
int sub_word(void)
{
	int select;
	int y1 = 14;
	int key;
	do {
		system("cls");
		gotoxy(70, 14);
		printf("   빨간색\n");
		gotoxy(70, 16);
		printf("   파란색\n");
		gotoxy(70, 18);
		printf("   초록색\n");
		gotoxy(70, 20);
		printf("   검정색\n");
		gotoxy(71, 22);
		printf("   흰색\n");
		gotoxy(66, 24);
		printf("   메인메뉴로 이동\n\n");
		Menu_draw_arrow(y1);
		key = getch();
		Menu_move_arrow_key(key, &y1,24);
		system("cls");
	} while (key != 13);

	select = y1 + 2;

	return select;

}
