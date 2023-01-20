#include <stdio.h>
// _getch()�֐���g�p���邽�߂̊O�����C�u����
#include <conio.h>
// system()�֐���g�p���邽�߂̕W�����C�u����
#include <windows.h>
// exit()�֐���g�p���邽�߂̊O�����C�u����
#include <stdlib.h>
#include <string.h>

void keyboard_input(int, int, int *);
void display_transition(int);

// 他ファイルで使用している関数のプロトタイプ宣言
#include "PROGRAM_JOINT.h"

int main(void) {
    // 現在の選択画面を判別するための識別コード
    int currentStateNum = 0;

    // �R�}���h�v�����v�g�̃R�}���h���̗����ׂď������V�F���R�}���h
    // �?字コードをutf8に変更するシェルコマン�?
    system("chcp 65001");

    // コマンド�?�ロンプトのコマンド等�?�履歴をすべて消去するシェルコマン�?
    system("cls");

    display_transition(currentStateNum);

    while(1) {
        // ��͂����L�[�{�[�h�̕�����F������֐���16�i���ŔF�����Ă���B
        int getOnceNum = _getch();
        /*
        ���L�[�������ꂽ���ɁA���ڂɖ��L�[���̂������ꂽ���Ƃ�F���������Ƃɓ��ڂłǂ̌�̖��L�[�������ꂽ�̂���
        ���ʂ��邽�ߓ�̕ϐ���p���Ċi�[���Ă���B
        */
        int getTwiceNum = _getch();
        keyboard_input(getOnceNum, getTwiceNum, &currentStateNum);
    }

    return 0;
}

void keyboard_input(int getNumOnce, int getNumTwice, int *currentStateNum) {
    switch(getNumOnce) {
        // ���L�[�������ꂽ�ꍇ
        case 0xe0:
            switch(getNumTwice) {
                // ���L�[�������ꂽ��
                case 0x48:
                    system("cls");
                    if(0<*currentStateNum && *currentStateNum<4) {
                        // ()をつけないと*演算子よりもインクリメントが優先され、アドレスをデクリメントすることになってしまうため、()を付ける。
                        (*currentStateNum)--;
                    }
                    display_transition(*currentStateNum);
                    break;
                // ���L�[�������ꂽ��
                case 0x50:
                    system("cls");
                    if(-1<*currentStateNum && *currentStateNum<3) {
                        (*currentStateNum)++;
                    }
                    display_transition(*currentStateNum);
                    break;
            }
            break;
        // Enter�L�[�������ꂽ��
        case 0xd:
            system("cls");
            switch(*currentStateNum) {
                case 0:
                    // 入力
                    input();
                    break;
                case 1:
                    // 検索
                    search();
                    break;
                case 2:
                    // ���_���\�[�g
                    break;
                case 3:
                    // 国名ソート
                    // selectionSort(char, int, int);
                    break;
            }
            break;
        // Esc�L�[�������ꂽ��
        case 0x1b:
            system("cls");
            // �R�}���h�v�����v������I������
            exit(0);
            break;
    }
}

void display_transition(int currentStateNum) {
    char *normalState[4] = {"  入力\n", "  検索\n", "  メダル総獲得順一覧\n", "  国名順一覧\n"};
    char *selectState[4];
    char allow[50] = "➤";
    strcat(allow, normalState[currentStateNum]);

    for(int i = 0; i < 4; i++) {
        selectState[i] = normalState[i];
        selectState[currentStateNum] = allow;
        printf("%s", selectState[i]);
    }
}