#include <stdio.h>
#include <stdlib.h>
#include "DAO.h"

void input(){
    char inputAns;
    int insertCountryNum = 0;                                           // 読み込んだ国数
    char countryName[100][256];                                         // 国名
    int goldMedalNum[100], silverMedalNum[100], copperMedalNum[100];    // 金、銀、銅メダルの数

    printf("情報の入力\n");

    do {
        printf("[%d 国目]\n", insertCountryNum+1);

        printf("国名を入力してください:");
        scanf("%s", countryName[insertCountryNum]);

        printf("金メダルの数を入力してください:");
        scanf("%d", &goldMedalNum[insertCountryNum]);

        printf("銀メダルの数を入力してください:");
        scanf("%d", &silverMedalNum[insertCountryNum]);

        printf("銅メダルの数を入力してください:");
        scanf("%d", &copperMedalNum[insertCountryNum]);
        insertCountryNum++;

        printf("続けて入力しますか? [Y/N]:");
        scanf("%*c%c", &inputAns);         // 1 文字目(改行)は無視し,2 文字目を代入
    } while (inputAns == 'y' || inputAns == 'Y'); // 'Y'が入力されたら続行,それ以外であれば終了

    for (int i = 0; i < insertCountryNum; i++) {
        // この段階で順位は不明なのでありえない値を引数に格納
        fileWrite(countryName[i], goldMedalNum[i], silverMedalNum[i], copperMedalNum[i]);
    }
    printf("ファイルへ書き込みました。\n");

    // メダル順位のソート
}