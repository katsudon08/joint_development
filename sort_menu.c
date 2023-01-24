#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

void sort_input_key(int, int, int *);
void sort_display(int);
void menu();

#include "MEDAL_SORT.h"

void sort_menu() {
    int currentStateNum = 0;

    system("chcp 65001");

    system("cls");

    sort_display(currentStateNum);

    while(1) {
        int getOnceNum = _getch();
        int getTwiceNum = _getch();
        sort_input_key(getOnceNum, getTwiceNum, &currentStateNum);
    }
}

void sort_input_key(int getNumOnce, int getNumTwice, int *currentStateNum) {
    switch(getNumOnce) {
        case 0xe0:
            switch(getNumTwice) {
                case 0x48:
                    system("cls");
                    if(*currentStateNum==1) {
                        // ()をつけないと*演算子よりもインクリメントが優先され、アドレスをデクリメントすることになってしまうため、()を付ける。
                        (*currentStateNum)--;
                    }
                    sort_display(*currentStateNum);
                    break;
                case 0x50:
                    system("cls");
                    if(*currentStateNum==0) {
                        (*currentStateNum)++;
                    }
                    sort_display(*currentStateNum);
                    break;
            }
            break;
        case 0xd:
            system("cls");
            switch(*currentStateNum) {
                case 0:
                    TotalMedalRank();
                    break;
                case 1:
                    GSBMedalRank();
                    break;
            }
            break;
        case 0x1b:
            system("cls");
            menu();
            break;
    }
}

void sort_display(int currentStateNum) {
    char *normalState[2] = {"  総メダル数ソート\n", "  メダル順位ソート\n"};
    char *selectState[2];
    char allow[50] = "→";
    strcat(allow, normalState[currentStateNum]);

    for(int i = 0; i < 2; i++) {
        selectState[i] = normalState[i];
        selectState[currentStateNum] = allow;
        printf("%s", selectState[i]);
    }
}