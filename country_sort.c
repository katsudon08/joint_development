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
    char min[BUF_SIZE];
    int i_min;
    char tmp[BUF_SIZE];

    for(int i=0; (data+i)->medalRank!=0; i++) {
        i_min=i;
        printf("%d\n", i_min);
        strcpy(min, (data+i_min)->countryName);
        for(int j=i; (data+j)->medalRank!=-1; j++) {
            if(strcmp(min, (data+j)->countryName)>0) {
                strcpy(min, (data+j)->countryName);
                i_min=j;
                printf("%d\n", i_min);
            }
        }
        if(i!=i_min) {
            strcpy(tmp, (data+i)->countryName);
            strcpy((data+i)->countryName, (data+i_min)->countryName);
            strcpy((data+i_min)->countryName, tmp);
            printf("%d\n", i_min);
        }
        printf("%d\n", i_min);
    }
    printf("==========================================");
    for(int i=0; (data+i)->medalRank!=0; i++) {
        printf("国名:%s\t総メダル順位:%d\t総メダル数:%d\n", (data+i)->countryName, (data+i)->medalRank, (data+i)->totalMedal);
    }
    printf("==========================================");
}