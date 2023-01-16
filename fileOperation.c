#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 256 // 一行の最大文字数(バイト数)

typedef struct {
    char countryName[BUF_SIZE];
    int medalRank;
    int medalGetNum;
    int goldMedal;
    int silverMedal;
    int cupperMedal;
} object; //オブジェクト型して、定義

int fileWrite(char *countryName, int goldMedal, int silverMedal, int cupperMedal) {
    FILE *fp;

    char *fname = "data.csv";

    fp = fopen("data.csv", "a");

    if(fp == NULL) {
        printf("Error: 書き込むファイルが見つかりませんでした。");
        exit(0);
    }
    char *inputString;

    sprintf(inputString, "%s,%d,%d,%d\n", countryName, goldMedal, silverMedal, cupperMedal);
    fputs(inputString, fp);

    fclose(fp);

    return 1;
}

int fileMedalRead() {
    return 1;
}

int fileCountryRead() {
    return 1;
}

// 順位と総メダル数
int fileRead() {
    // FILE型構造体
    FILE *fp;

    // ファイル操作を行うファイル名
    char *fname = "data.csv";

    // fgets関数や、sscanf関数を用いる際に使用する一行分の文字列を格納する変数
    char lineString[BUF_SIZE];
    // 検索した文字列を格納する変数
    char searchCountryName[BUF_SIZE];

    // 検索した国が存在するかどうかの識別変数
    int isExist = 0;

    // 構造体をインスタンス化
    object data;

    // ファイルを開き、読み込む
    fp = fopen(fname, "r");

    if(fp!=NULL) {
        // 第一引数:一行分の文字列を格納する配列
        // 第二引数:一行の最大文字数
        // 第三引数:FILE型構造体の実体のアドレス
        // fgets関数で読み込みに失敗するとnullを返す。
        while(fgets(lineString, BUF_SIZE, fp) != NULL) {
            // 第一引数にファイル操作の対象の変数
            // 第二引数に読み込まれた書式指定子
            // 第三引数にファイルで読み込んだ文字列を格納する変数
            sscanf(lineString, "%s %d %d", data.countryName, &data.medalRank, &data.medalGetNum);
            // 第一引数の変数と第二引数の変数の文字列を比較して、一致すれば0を返す。
            if(strcmp(searchCountryName, data.countryName)==0) {
                // コマンドプロントの履歴を消去
                system("cls");
                printf("======================================\n");
                printf("\t国名\t\t:%s\n", data.countryName);
                printf("\tメダル順位\t:%d\n", data.medalRank);
                printf("\t獲得メダル数\t:%d\n", data.medalGetNum);
                printf("======================================\n");
                isExist++;
            }
        }
    }else { // ファイルが存在しなかった場合のエラー
        printf("Error: 読み込むファイルが見つかりませんでした。");
        exit(0);
    }

    // 検索した国がファイル内に存在しなかった場合のエラー
    if(!isExist) {
        printf("Error: 検索した条件と一致する国が見つかりませんでした。");
        exit(0);
    }

    // ファイル操作を行った後は必ずファイルを閉じる必要がある。
    fclose(fp);

    return 0;
}