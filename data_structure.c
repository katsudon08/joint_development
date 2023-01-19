#include <stdio.h>
#define BUF_SIZE 256
struct COUNTRY_DATA {
    int medalRank;
    char *countryName;
    int goldMedal;
    int silverMedal;
    int bronzeMedal;
    int totalMedal;
};

struct COUNTRY_DATA init_data(int medalRank, char countryName[BUF_SIZE], int goldName, int silverMedal, int bronzeMedal) {
    struct COUNTRY_DATA dataObject;
    dataObject.medalRank = medalRank;
    dataObject.countryName = countryName;
    dataObject.goldMedal = goldName;
    dataObject.silverMedal = silverMedal;
    dataObject.bronzeMedal = bronzeMedal;
    dataObject.totalMedal = dataObject.goldMedal+dataObject.silverMedal+dataObject.goldMedal;
    return dataObject;
}