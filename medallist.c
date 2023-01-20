#include<stdio.h>
#include<string.h>
#include "DAO.h"
typedef struct {                                        /*新しい型 国名 金銀銅メダル数*/
		char cntry_name[20];                               /*国名*/
		int g_num;                                      /*金メダル数*/
		int s_num;                                      /*銀メダル数*/
		int b_num;                                      /*銅メダル数*/
	}mdl;
mdl medal_sort[100],chng;                      /*構造体の配列とソートに使う構造体を宣言*/

void TotalMedalRank(void){                               /*総メダルソート*/

	int i,j,t;                                          /*ソートと表示に使う変数を宣言*/
	int s;                                              /*総メダル数算出の際使う変数*/
	int full_medal_num[100];                            /*総メダル数*/
	int full_medal_chng;                                /*入れ替え用*/

	for(s=0;strlen(medal_sort[s].cntry_name);s++){

		full_medal_num[s] = medal_sort[s].g_num + medal_sort[s].s_num + medal_sort[s].b_num;

	}
	for(i=0;i <= 98 && strlen(medal_sort[i].cntry_name)/**/;i++){

		for(j=i+1;j <= 99 && strlen(medal_sort[j].cntry_name)/**/;j++){

			if(full_medal_num[i]<full_medal_num[j]){

				chng = medal_sort[i];
				medal_sort[i] = medal_sort[j];
				medal_sort[j] = chng;
				full_medal_chng = full_medal_num[i];
				full_medal_num[i] = full_medal_num[j];
				full_medal_num[j] = full_medal_chng;

			}

		}

	}                                                   /*総メダル数の順にソート*/
	printf("T-Medal Ranking\n\n");
	for(t=0;strlen(medal_sort[t].cntry_name);t++){

		printf("No.%d \t| %s",t+1,medal_sort[t].cntry_name);
		printf(" \t| Total  %d \t| Gold   %d",full_medal_num[t],medal_sort[t].g_num);
		printf(" \t| Silver %d \t| Bronze %d \t|\n",medal_sort[t].s_num,medal_sort[t].b_num);

	}                                                   /*No.〇 | 国名 | Total  〇 | Gold   〇 |Silver 〇 | Bronze 〇 |*/
	printf("...\n");
}

void GSCMedalRank(void){                                /*メダル順位ソート*/

	int i,j,t;                                          /*ソートと表示に使う変数を宣言*/

	for(i=0;strlen(medal_sort[i].cntry_name) && i <= 98/**/;i++){
		for(j = i + 1;strlen(medal_sort[j].cntry_name)/* && j <= 99*/;j++){
			                                            /*金メダル数の順にソート*/
			if(medal_sort[i].g_num<medal_sort[j].g_num){

				chng = medal_sort[i];
				medal_sort[i] = medal_sort[j];
				medal_sort[j] = chng;

			}
			else if(medal_sort[i].g_num==medal_sort[j].g_num){
														/*金メダル数が同じ時銀の比較へ*/
				if(medal_sort[i].s_num<medal_sort[j].s_num){
														/*銀メダル数の順にソート*/
					chng = medal_sort[i];
					medal_sort[i] = medal_sort[j];
					medal_sort[j] = chng;

				}
				else if(medal_sort[i].s_num==medal_sort[j].s_num){
														/*銀メダル数が同じ時銅の比較へ*/
					if(medal_sort[i].b_num<medal_sort[j].b_num){
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
	for(t=0;strlen(medal_sort[t].cntry_name);t++){

		printf("No.%d \t| %s",t+1,medal_sort[t].cntry_name);
		printf(" \t| Gold   %d ",medal_sort[t].g_num);
		printf(" \t| Silver %d \t| Bronze %d \t|\n",medal_sort[t].s_num,medal_sort[t].b_num);

	}
	printf("...\n");
														/*No.〇 | 国名 | Gold   〇 | Silver 〇 | Bronze 〇 |*/
}
/*
int main(void){
	int n;
	int let_num;


	printf("please tell me num of countries\n->");
	scanf("%d",&let_num);

	for(n=0;n<=(let_num - 1);n++){
		printf("country name\n->");
		scanf("%*c%s",medal_sort[n].cntry_name);
		printf("medal number\nGold  :");
		scanf("%*c%d",&medal_sort[n].g_num);
		printf("Silver:");
		scanf("%*c%d",&medal_sort[n].s_num);
		printf("Bronze:");
		scanf("%*c%d",&medal_sort[n].b_num);
		printf("No.%d finished\n",n + 1);
	}

	printf("All finished.\n");



	GSCMedalRank();

	TotalMedalRank();
	/*

	return 0;
}
*/
