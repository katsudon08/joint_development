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
    char *countryName;
    int goldMedal;
    int silverMedal;
    int bronzeMedal;
    int totalMedal;
};

void search() {
    int isExist = 0;
    struct COUNTRY_DATA *data;
    char searchCountryName[BUF_SIZE];

    printf("検索する国名を入力してください。\n");
    scanf("%s", searchCountryName);
    system("cls");

    data = fileRead();
    for(int i=0; i<BUF_SIZE; i++) {
        if(strcmp(searchCountryName, data->countryName)==0) {
                // コマンドプロントの履歴を消去
                system("cls");
                printf("======================================\n");
                printf("\t国名\t\t:%s\n", data->countryName);
                printf("\tメダル順位\t:%d\n", data->medalRank);
                printf("\t獲得メダル数\t:%d\n", data->totalMedal);
                printf("======================================\n");
                isExist++;
        }
        data++;
    }
    if(!isExist) {
        printf("Error: 検索した条件と一致する国が見つかりませんでした。");
        fflush(0);
    }
}