#include<stdio.h>
#include<string.h>
#include"DAO.h"
#define BUF_SIZE 256 // 一行の最大文字数(バイト数)

struct COUNTRY_DATA {
    int medalRank;
    char countryName[BUF_SIZE];
    int goldMedal;
    int silverMedal;
    int bronzeMedal;
    int totalMedal;
};

struct COUNTRY_DATA chng;
struct COUNTRY_DATA *medal_sort;

void TotalMedalRank(void){                              /*総メダルソート*/

	medal_sort = fileRead();

	int i,j,t;                                          /*ソートと表示に使う変数を宣言*/

	for(i=0;i < (BUF_SIZE - 1) && strlen(medal_sort[i].countryName);i++){

		for(j=i+1;j < BUF_SIZE && strlen(medal_sort[j].countryName);j++){
			if(medal_sort[i].totalMedal<medal_sort[j].totalMedal){

				chng = medal_sort[i];
				medal_sort[i] = medal_sort[j];
				medal_sort[j] = chng;

			}
		}

	}                                                   /*総メダル数の順にソート*/
	printf("T-Medal Ranking\n\n");
	for(t=0;t < BUF_SIZE && strlen((medal_sort+t)->countryName);t++){
		printf("No.%d \t| %s ",t+1,(medal_sort+t)->countryName);
		if(12>strlen((medal_sort+t)->countryName)){
			if(4>strlen((medal_sort+t)->countryName)){
				printf("\t");
			}
			printf("\t");
		}
		printf(" \t| Total  %d \t| Gold   %d",(medal_sort+t)->totalMedal,(medal_sort+t)->goldMedal);
		printf(" \t| Silver %d \t| Bronze %d \t|\n",(medal_sort+t)->silverMedal,(medal_sort+t)->bronzeMedal);
	}                                                   /*No.〇 | 国名 | Total  〇 | Gold   〇 |Silver 〇 | Bronze 〇 |*/
	printf("...\n");

}

void GSBMedalRank(void){                                /*メダル順位ソート*/

	medal_sort = fileRead();

	int i,j,t;                                          /*ソートと表示に使う変数を宣言*/

	for(i=0;i <= (BUF_SIZE - 1) && strlen(medal_sort[i].countryName)/**/;i++){

		for(j=i+1;j <= BUF_SIZE && strlen(medal_sort[j].countryName)/**/;j++){
			                                            /*金メダル数の順にソート*/
			if(medal_sort[i].goldMedal<medal_sort[j].goldMedal){

				chng = medal_sort[i];
				medal_sort[i] = medal_sort[j];
				medal_sort[j] = chng;

			}
			else if(medal_sort[i].goldMedal==medal_sort[j].goldMedal){
														/*金メダル数が同じ時銀の比較へ*/
				if(medal_sort[i].silverMedal<medal_sort[j].silverMedal){
														/*銀メダル数の順にソート*/
					chng = medal_sort[i];
					medal_sort[i] = medal_sort[j];
					medal_sort[j] = chng;

				}
				else if(medal_sort[i].silverMedal==medal_sort[j].silverMedal){
														/*銀メダル数が同じ時銅の比較へ*/
					if(medal_sort[i].bronzeMedal<medal_sort[j].bronzeMedal){
														/*銅メダル数の順にソート*/
						chng = medal_sort[i];
						medal_sort[i] = medal_sort[j];
						medal_sort[j] = chng;

					}
				}
			}
		}
	}
	printf("Medal Ranking\n\n");

	for(t=0;t < BUF_SIZE && strlen((medal_sort+t)->countryName);t++){
		printf("No.%d \t| %s ",t+1,(medal_sort+t)->countryName);
		if(12>strlen((medal_sort+t)->countryName)){
			if(4>strlen((medal_sort+t)->countryName)){
				printf("\t");
			}
			printf("\t");
		}

		printf(" \t| Gold   %d",(medal_sort+t)->goldMedal);
		printf(" \t| Silver %d \t| Bronze %d \t|\n",(medal_sort+t)->silverMedal,(medal_sort+t)->bronzeMedal);

	}                                                   /*No.〇 | 国名 | Total  〇 | Gold   〇 |Silver 〇 | Bronze 〇 |*/
	printf("...\n");
														/*No.〇 | 国名 | Gold   〇 | Silver 〇 | Bronze 〇 |*/
}

void ReGSBMedalRank(void){              /*メダル順位ソート*/

	medal_sort = fileRead();

	int i,j,t;                                          /*ソートと表示に使う変数を宣言*/

	for(i=0;i <= (BUF_SIZE - 1) && strlen(medal_sort[i].countryName);i++){

		for(j=i+1;j <= BUF_SIZE && strlen(medal_sort[j].countryName);j++){
			                                            /*金メダル数の順にソート*/
			if(medal_sort[i].goldMedal<medal_sort[j].goldMedal){

				chng = medal_sort[i];
				medal_sort[i] = medal_sort[j];
				medal_sort[j] = chng;

			}
			else if(medal_sort[i].goldMedal==medal_sort[j].goldMedal){
														/*金メダル数が同じ時銀の比較へ*/
				if(medal_sort[i].silverMedal<medal_sort[j].silverMedal){
														/*銀メダル数の順にソート*/
					chng = medal_sort[i];
					medal_sort[i] = medal_sort[j];
					medal_sort[j] = chng;

				}
				else if(medal_sort[i].silverMedal==medal_sort[j].silverMedal){
														/*銀メダル数が同じ時銅の比較へ*/
					if(medal_sort[i].bronzeMedal<medal_sort[j].bronzeMedal){
														/*銅メダル数の順にソート*/
						chng = medal_sort[i];
						medal_sort[i] = medal_sort[j];
						medal_sort[j] = chng;

					}
				}
			}
		}
	}

	fileRewrite(medal_sort->countryName, medal_sort->goldMedal, medal_sort->silverMedal, medal_sort->bronzeMedal);
	for(int i=1; (medal_sort+i)->medalRank!=0; i++) {
		fileWrite((medal_sort+i)->countryName, (medal_sort+i)->goldMedal, (medal_sort+i)->silverMedal, (medal_sort+i)->bronzeMedal);
	}
}