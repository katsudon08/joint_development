#include <stdio.h>
#include <string.h>
#define STR_MAX 256
void printArray(char a[][STR_MAX], int num){ //num: 国数
    for (int i = 0; i < num; i++) {
        printf("%s ", a[i]);
    }
    printf("\n");
}

void selectionSort(char data[][STR_MAX], int left, int right) {
    int start;
    int i;
    char min[STR_MAX];
    int i_min;
    char tmp[STR_MAX];    
    if (left == right) {
        return;
    }
    start = left;
    for (start = left; start < right; start++) {
        i_min = start;
        strcpy(min, data[i_min]);
        for (i = start; i <= right; i++) {
            if (strcmp(min, data[i]) > 0) {
                strcpy(min, data[i]);
                i_min = i;
            } 
        }

        if (start != i_min) {
            strcpy(tmp, data[start]);
            strcpy(data[start], data[i_min]);
            strcpy(data[i_min], tmp);
        }
    }
}


int main(void) {
    char array[][STR_MAX] = {
        "Sakuraba",
        "Sato",
        "Suzuki",
        "Sakakibara",
        "Shourinnji",
        "Sanada",
        "Sasakamaboko",
        "Sasakamabokoo"
    };
    int data_num = sizeof(array)/sizeof(array)[0];
    printArray(array, data_num);
    selectionSort(array, 0, data_num - 1);
    printArray(array, data_num);
    return 0;
}