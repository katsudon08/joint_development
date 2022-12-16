#include <stdio.h>
int main(void) {
    char a[100];
    int b, c, d;
    printf("国名 金メダル数 銀メダル数 銅メダル数\n");
    scanf("%s %d %d %d", &a, &b, &c, &d);
    printf("%sは、金%d個、銀%d個、銅%d個です。\n", a, b, c, d);
    return 0;
}