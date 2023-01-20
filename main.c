#include <stdio.h>
// _getch()�֐����g�p���邽�߂̊O�����C�u����
#include <conio.h>
// system()�֐����g�p���邽�߂̕W�����C�u����
#include <windows.h>
// exit()�֐����g�p���邽�߂̊O�����C�u����
#include <stdlib.h>

void keyboard_input(int, int, int *);
void display_transition(int);

// 他ファイルで使用して�?る関数のプロトタイプ宣言
#include "joint.h"

int main(void) {
    // ���݂̑I����ʂ𔻕ʂ��邽�߂̎��ʃR�[�h
    int currentStateNum = 4;

    // �R�}���h�v�����v�g�̃R�}���h���̗��������ׂď�������V�F���R�}���h
    // �?字コードをutf8に変更するシェルコマン�?
    system("chcp 65001");

    // コマンド�?�ロンプトのコマンド等�?�履歴をすべて消去するシェルコマン�?
    system("cls");

    display_transition(currentStateNum);

    while(1) {
        // ���͂����L�[�{�[�h�̕�����F������֐���16�i���ŔF�����Ă���B
        int getOnceNum = _getch();
        /*
        ���L�[�������ꂽ���ɁA���ڂɖ��L�[���̂������ꂽ���Ƃ�F���������Ƃɓ��ڂłǂ̌����̖��L�[�������ꂽ�̂���
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
                        // ()�����Ȃ���*���Z�q�����C���N�������g���D�悳��A�A�h���X���C���N�������g���邱�ƂɂȂ��Ă��܂����߁A()��t����B
                        (*currentStateNum)++;
                    }
                    display_transition(*currentStateNum);
                    break;
                // ���L�[�������ꂽ��
                case 0x50:
                    system("cls");
                    if(1<*currentStateNum && *currentStateNum<5) {
                        (*currentStateNum)--;
                    }
                    display_transition(*currentStateNum);
                    break;
            }
            break;
        // Enter�L�[�������ꂽ��
        case 0xd:
            system("cls");
            switch(*currentStateNum) {
                case 1:
                    // �����\�[�g
                    break;
                case 2:
                    // ���_���\�[�g
                    break;
                case 3:
                    // ����
                    search();
                    break;
                case 4:
                    // ����
                    break;
            }
            break;
        // Esc�L�[�������ꂽ��
        case 0x1b:
            system("cls");
            // �R�}���h�v�����v���������I������
            exit(0);
            break;
    }
}

void display_transition(int currentStateNum) {
    char *selectInput = "? ����\n";
    char *input = "  ����\n";
    char *selectQuery = "? ����\n";
    char *query = "  ����\n";
    char *selectMedalList = "? ���_�����l�����ꗗ\n";
    char *medalList = "  ���_�����l�����ꗗ\n";
    char *selectCountryList = "? �������ꗗ\n";
    char *countryList = "  �������ꗗ\n";

    char *selectInputState[4] = {selectInput, query, medalList, countryList};
    char *selectQueryState[4] = {input, selectQuery, medalList, countryList};
    char *selectMedalState[4] = {input, query, selectMedalList, countryList};
    char *selectCountryState[4] = {input, query, medalList, selectCountryList};

    switch(currentStateNum) {
        case 1:
            for(int i=0; i<4; i++) {
                printf("%s", selectCountryState[i]);
            }
            break;
        case 2:
            for(int i=0; i<4; i++) {
                printf("%s", selectMedalState[i]);
            }
            break;
        case 3:
            for(int i=0; i<4; i++) {
                printf("%s", selectQueryState[i]);
            }
            break;
        case 4:
            for(int i=0; i<4; i++) {
                printf("%s", selectInputState[i]);
            }
            break;
    }
}



