#include "config.h"
char string_[3] = "07";
menu_m show_menus = { 0, 17 };
int I_s_main = 1;					
const char arrow_[3] = "��";


int main(void)						
{

	system("mode con cols=150 lines=40");
	FILE *fp = fopen("bubble_it.txt", "w");
	fprintf(fp, "%s", string_);
	fclose(fp);
	//FILE *fp = fopen("bubble_it.txt", "r");
	Menu_SelectMenu();
	if (worktype == 4)
	{
		int c;

		while (1)
		{
			c = menu_display();			
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
		if (show_menus._y > 17 + 3 - 1) {
			show_menus._y = 17 + 3 - 1;
		}
		Menu_gotoxy(65, 17);
		printf("  ���� ����\n");
		Menu_gotoxy(65, 18);
		printf("  ���ڻ� ����\n");
		Menu_gotoxy(65, 19);
		printf("  ���� ����\n\n");
		Menu_draw_arrow(show_menus._y);
		key = getch();
		Menu_move_arrow_key(key, &show_menus._y, 3);
		system("cls");
	} while (key != 13);

	select = show_menus._y - 16;

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
		Menu_gotoxy(65, 17);
		printf("   ������\n");
		Menu_gotoxy(65, 18);
		printf("   �Ķ���\n");
		Menu_gotoxy(65, 19);
		printf("   �ʷϻ�\n");
		Menu_gotoxy(65, 20);
		printf("   ������\n");
		Menu_gotoxy(65, 21);
		printf("   ���\n");
		Menu_gotoxy(65, 22);
		printf("   ���θ޴��� �̵�\n\n");
		Menu_draw_arrow(show_menus._y);			
		key = getch();
		Menu_move_arrow_key(key, &show_menus._y, 6);
		system("cls");
	} while (key != 13);

	select = show_menus._y - 16;		

	return select;
}
void back_color(int type)			
{
	system("cls");
	char dos_command[9];
	char pre_color = string_[0];

	switch (type) {
	case 1:
		string_[0] = '4';
		break;
	case 2:
		string_[0] = '1';
		break;
	case 3:
		string_[0] = '2';
		break;
	case 4:
		string_[0] = '0';
		break;
	case 5:
		string_[0] = '7';
		break;

	}

	if (string_[0] == string_[1]) {		
		Menu_gotoxy(60, 30);
		printf("���� ������ ������ ���� �� ���� �����ϴ�!");
		string_[0] = pre_color;
		return;
	}

	sprintf(dos_command, "color %s", string_);

	system(dos_command);

}

void word_color(int type) {		
	system("cls");
	char dos_command[9];
	char pre_color = string_[1];

	switch (type) {
	case 1:
		string_[1] = '4';
		break;
	case 2:
		string_[1] = '2';
		break;
	case 3:
		string_[1] = '0';
		break;
	case 4:
		string_[1] = '7';
		break;
	}

	if (string_[0] == string_[1]) {
		Menu_gotoxy(60, 30);
		printf("���� ������ ������ ���� �� ���� �����ϴ�!");
		string_[1] = pre_color;
		return;
	}

	sprintf(dos_command, "color %s", string_);

	system(dos_command);
}


void sub_word01(void)		
{
	int c;
	while ((c = sub_word()) != 5)
	{
		word_color(c);
	}
}
int sub_word(void)			
{
	int select;
	int y1 = 0;
	int key;
	do {
		if (show_menus._y > 17 + 5 - 1) {
			show_menus._y = 17 + 5 - 1;
		}
		Menu_gotoxy(65, 17);
		printf("   ������\n");
		Menu_gotoxy(65, 18);
		printf("   �ʷϻ�\n");
		Menu_gotoxy(65, 19);
		printf("   ������\n");
		Menu_gotoxy(65, 20);
		printf("   ���\n");
		Menu_gotoxy(65, 21);
		printf("   ���θ޴��� �̵�\n\n");
		Menu_draw_arrow(show_menus._y);
		key = getch();
		Menu_move_arrow_key(key, &show_menus._y, 5);		
		system("cls");
	} while (key != 13);

	select = show_menus._y - 16;		

	return select;

}
void Menu_go_arrow_key(char key, int *y1, int y_size) {		
	switch (key)
	{
	case 72:
		*y1 = *y1 - 1;
		if (*y1 < 17)
			*y1 = 17;
		break;
	case 80:
		*y1 = *y1 + 1;
		if (*y1 > y_size + 17)
			*y1 = y_size + 17;
		break;
	default:
		return;
	}
}

void Menu_go_arrow(int y) {						//ȭ��ǥ ���
	Menu_gotoxy(65, y);
	printf("%s", arrow_);
}