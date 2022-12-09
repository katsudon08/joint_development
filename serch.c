#include <stdio.h>
// fgets()関数を使うための標準ライブラリ
#include <stdlib.h>
// strcmp()関数を使うための標準ライブラリ
#include <string.h>
#define N 256 // 一行の最大文字数(バイト数)

typedef struct {
    char countryName[N];
    int medalRank;
    int medalGetNum;
} object; //オブジェクト型して、定義

int main(void) {
    // FILE型構造体
    FILE *fp;

    // ファイル操作を行うファイル名
    char fname[] = "data.csv";

    // fgets関数や、sscanf関数を用いる際に使用する一行分の文字列を格納する変数
    char line[N];
    // 検索した文字列を格納する変数
    char searchCountryName[N];

    // 構造体をインスタンス化
    object data;

    printf("検索する国名を入力してください。\n");
    scanf("%s", searchCountryName);
    system("cls");

    // ファイルを開き、読み込む
    fp = fopen(fname, "r");
    if(fp!=NULL) {
        // 第一引数:一行分の文字列を格納する配列
        // 第二引数:一行の最大文字数
        // 第三引数:FILE型構造体の実体のアドレス

        // fgets関数で読み込みに失敗するとnullを返す。
        while(fgets(line, N, fp) != NULL) {
            // 第一引数にファイル操作の対象の変数
            // 第二引数に読み込まれた書式指定子
            // 第三引数にファイルで読み込んだ文字列を格納する変数
            sscanf(line, "%s %d %d", data.countryName, &data.medalRank, &data.medalGetNum);

            // 第一引数の変数と第二引数の変数の文字列を比較して、一致すれば0を返す。
            if(strcmp(searchCountryName, data.countryName)==0) {
                // コマンドプロントの履歴を消去
                system("cls");
                printf("======================================\n");
                printf("\t国名\t\t:%s\n", data.countryName);
                printf("\tメダル順位\t:%d\n", data.medalRank);
                printf("\t獲得メダル数\t:%d\n", data.medalGetNum);
                printf("======================================\n");
                break;
            }
        }
    }else {
        printf("null");
        return 0;
    }

    // ファイル操作を行った後は必ずファイルを閉じる必要がある。
    fclose(fp);

    return 0;
}