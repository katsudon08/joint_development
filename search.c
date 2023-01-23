#include <stdio.h>
// fgets()関数を使うための標準ライブラリ
#include <stdlib.h>
// strcmp()関数を使うための標準ライブラリ
#include <string.h>
// ファイル操作のライブラリ
#include "DAO.h"
#define BUF_SIZE 256

struct COUNTRY_DATA {
    int medalRank;
    char countryName[BUF_SIZE];
    int goldMedal;
    int silverMedal;
    int bronzeMedal;
    int totalMedal;
};

void search() {
    int isExist=0;
    struct COUNTRY_DATA *data = fileRead();
    char searchCountryName[BUF_SIZE];

    printf("検索する国名:");
    scanf("%s", searchCountryName);
    system("cls");

    for(int i=0; (data+i)->medalRank!=0; i++) {
        if(strcmp(searchCountryName, (data+i)->countryName)==0) {
                // コマンドプロントの履歴を消去
                system("cls");
                printf("======================================\n");
                printf("\t国名\t\t:%s\n", (data+i)->countryName);
                printf("\tメダル順位\t:%d\n", (data+i)->medalRank);
                printf("\t獲得メダル数\t:%d\n", (data+i)->totalMedal);
                printf("======================================\n");
                isExist++;
                break;
        }
    }
    if(!isExist) {
        printf("検索した条件と一致する国が見つかりませんでした。");
    }
}