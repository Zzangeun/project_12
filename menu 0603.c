#include "menu.h"

const char arrow[3] = "��";
int worktype = 0;
menu_m menu_menus = { 0, 0};

void Menu_MainMenuPrint() {
	if (worktype == 0) {
		printf("  [1.���͵� �÷���]\n");
		printf("  [2.���͵� Ÿ�̸�]\n");
		printf("  [3.���͵� Ķ����]\n");
		printf("  [4.ȯ��     ����]\n");
		printf("  [5.���α׷� ����]\n");
	}
	else {
		printf("  [1.����     �޴�]\n");
		printf("  [2.ȯ��     ����]\n");
		printf("  [3.���α׷� ����]\n");
	}
}

void Menu_SelectMenu() {
	char key;
	while (1) {
		do {
			Menu_MainMenuPrint();
			Menu_draw_arrow(menu_menus._y);
			key = getch();
			Menu_move_arrow_key(key, &menu_menus._y, 4);
			system("cls");
		} while (key != 13);



		menu_menus.menu_select = menu_menus._y + 1;
		if (worktype == 0) {
			if (menu_menus.menu_select >= 1 && menu_menus.menu_select <= 5) {
				worktype = menu_menus.menu_select;
				break;
			}
			else {
				printf("ERROR!\n");
				continue;
			}
		}
		else {
			if (menu_menus.menu_select >= 1 && menu_menus.menu_select <= 3) {
				if (menu_menus.menu_select == 1)
					worktype = 0;
				else
					worktype = menu_menus.menu_select + 2;
				break;
			}
			else {
				printf("ERROR!\n");
				continue;
			}
		}
	}

	switch (worktype) {		//����
	case 0:
		printf("���� �޴��� �̵�\n");
		return;
	case 1:
		printf("���͵� �÷��ʷ� �̵�\n");
		return;
	case 2:
		printf("���͵� Ÿ�̸ӷ� �̵�\n");
		return;
	case 3:
		printf("���͵� Ķ������ �̵�\n");
		return;
	case 4:
		printf("ȯ�� �������� �̵�\n");
		return;
	case 5:
		printf("���α׷� ����\n");
		return;
	}
}

void Menu_gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Menu_move_arrow_key(char key, int *y1, int y_size) {
	switch (key)
	{
	case 72:
		*y1 = *y1 - 1;
		if (*y1 < 0)
			*y1 = 0;
		break;
	case 80:
		*y1 = *y1 + 1;
		if (*y1 > y_size)
			*y1 = y_size;
		break;
	default:
		return;
	}
}

void Menu_draw_arrow(int y) {
	Menu_gotoxy(69, y);
	printf("%s", arrow);
}