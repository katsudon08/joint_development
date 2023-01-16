#include <stdio.h>
#include <string.h>

int main(void) {
    char *a = "aiueo";
    char *b = "bbb";
    char allow[10] = "➤";
    printf("%s\n", a);

    strcat(allow, b);
    printf("%s\n", allow);

    a = allow;
    printf("%s\n", a);

    return 0;
}