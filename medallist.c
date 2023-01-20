#include<stdio.h>
int mdl_f_num[5][4];
void FullMedalRank(void){
	int cntry_num = 5;
	int i,j,chng[4];
	int s;
	for(i=0;i<(cntry_num - 1);i++){
		for(j=i+1;j<=cntry_num;j++){
			if(mdl_f_num[i][4]<mdl_f_num[j][4]){
				for(s=0;s=3;s++){
					chng[s] = mdl_f_num[i][s];
					mdl_f_num[i][s] = mdl_f_num[j][s];
					mdl_f_num[j][s] = chng[s];
				}
				
			}
		}
	}
}
