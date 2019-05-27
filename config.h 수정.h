#ifndef CONFIG
#define CONFIG
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include "menu.h"




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

void word_color(int type);
void back_color(int type);
void fore_red(void);
void fore_black(void);
void fore_green(void);
void fore_white(void);
void fore_blue(void);
void back_red(int type);
void press_any_key(void);

#endif
