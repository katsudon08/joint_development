#include <stdio.h>
#include <string.h>
int main(void) {
    char a[256] = "aiueo";
    char b[256] = "B";

    printf("%d\n", strcmp(a, b));
    printf("%d\n", strcmp(b, a));

    return 0;
}