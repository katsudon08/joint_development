#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void selectionSort() {
    struct COUNTRY_DATA *data = fileRead();
    struct COUNTRY_DATA data_tmp;
    printf("\n");
    for (int i=0; (data+i)->medalRank!=0; i++) {
        for(int j=1; (data+j)->medalRank!=0; j++) {
            if(strcmp((data+(j-1))->countryName, (data+j)->countryName)>0) {
                data_tmp = *(data+(j-1));
                *(data+(j-1)) = *(data+j);
                *(data+j) = data_tmp;
            }
        }
    }
	for(int i=0; (data+i)->medalRank!=0; i++){
	printf("%s ", (data+i)->countryName);
	if(12>strlen((data+i)->countryName)){
		if(6>strlen((data+i)->countryName)){
			printf("\t");
		}
	}
	printf(" \t| Gold   %d",(data+i)->goldMedal);
	printf(" \t| Silver %d \t| Bronze %d \t|\n", (data+i)->silverMedal, (data+i)->bronzeMedal);
	}
}