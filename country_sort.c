#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_MAX 256

struct COUNTRY_DATA {
    int medalRank;
    char *countryName;
    int goldMedal;
    int silverMedal;
    int bronzeMedal;
    int totalMedal;
};

void printArray(char a[][STR_MAX], int num){ //num: 国数
    for (int i = 0; i < num; i++) {
        printf("%s\n", a[i]);
    }
}

void selectionSort(char data[][STR_MAX]) {
    int dataLength = sizeof(data)/sizeof(data)[0];
    char min[STR_MAX];
    int i_min;
    char tmp[STR_MAX];
    if (dataLength == 0) {
        return;
    }
    for (int i = 0; i < dataLength; i++) {
        i_min = i;
        strcpy(min, data[i_min]);
        for (int j=i; j<dataLength; j++) {
            if (strcmp(min, data[j]) > 0) {
                strcpy(min, data[j]);
                i_min = j;
            }
        }

        if (i!=i_min) {
            strcpy(tmp, data[i]);
            strcpy(data[i], data[i_min]);
            strcpy(data[i_min], tmp);
        }
    }
}


// 修正後
void main() {
    struct COUNTRY_DATA data;
    // int dataLength = sizeof(data)/sizeof(data);
    // char min[STR_MAX];
    // int i_min;
    // char tmp[STR_MAX];
    // if (dataLength == 0) {
    //     return;
    // }
    // for (int i = 0; i < dataLength; i++) {
    //     i_min = i;
    //     strcpy(min, data[i_min]);
    //     for (int j=i; j<dataLength; j++) {
    //         if (strcmp(min, data[j]) > 0) {
    //             strcpy(min, data[j]);
    //             i_min = j;
    //         }
    //     }

    //     if (i!=i_min) {
    //         strcpy(tmp, data[i]);
    //         strcpy(data[i], data[i_min]);
    //         strcpy(data[i_min], tmp);
    //     }
    // }
    int size = sizeof(data);
    printf("%d", size);
}


// int main(void) {
//     char array[][STR_MAX] = {
//         "Sakuraba",
//         "Sato",
//         "Suzuki",
//         "Sakakibara",
//         "Shourinnji",
//         "Sanada",
//         "Sasakamaboko",
//         "Sasakamabokoo"
//     };
//     int data_num = sizeof(array)/sizeof(array)[0];
//     printArray(array, data_num);
//     selectionSort(array, data_num - 1);
//     printArray(array, data_num);
//     return 0;
// }