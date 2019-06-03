#include "menu.h"

const char arrow[3] = "→";
int worktype = 0;
menu_m menu_menus = { 0, 0};

void Menu_MainMenuPrint() {
	if (worktype == 0) {
		printf("  [1.스터디 플래너]\n");
		printf("  [2.스터디 타이머]\n");
		printf("  [3.스터디 캘린더]\n");
		printf("  [4.환경     설정]\n");
		printf("  [5.프로그램 종료]\n");
	}
	else {
		printf("  [1.메인     메뉴]\n");
		printf("  [2.환경     설정]\n");
		printf("  [3.프로그램 종료]\n");
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

	switch (worktype) {		//공동
	case 0:
		printf("메인 메뉴로 이동\n");
		return;
	case 1:
		printf("스터디 플래너로 이동\n");
		return;
	case 2:
		printf("스터디 타이머로 이동\n");
		return;
	case 3:
		printf("스터디 캘린더로 이동\n");
		return;
	case 4:
		printf("환경 설정으로 이동\n");
		return;
	case 5:
		printf("프로그램 종료\n");
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