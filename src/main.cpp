#include <stdio.h>


int main() {
    int ucNum = 5;

    char aNumChars[] = {'0', '1', '2', /*3~9*/'A', 'B', 'C', /*D~Y*/'Z'};
    char ucNumChar1 = aNumChars[ucNum % sizeof(aNumChars)];

    char ucNumChar2 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[ucNum];

    printf("%c", ucNumChar1);
    printf("%c", ucNumChar2);


    return 0;
}