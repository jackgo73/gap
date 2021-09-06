#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef signed char int8;          /* == 8 bits */
typedef signed short int16;        /* == 16 bits */
typedef signed int int32;          /* == 32 bits */
typedef unsigned char uint8;       /* == 8 bits */
typedef unsigned short uint16;     /* == 16 bits */
typedef unsigned int uint32;       /* == 32 bits */

char *longestPalindrome(char *s) {
    uint32 len = strlen(s);
    char *p = s, *l, *r;
    while (*(p++)) {
        for (l = p, r = p; l >= s && r < s && *l == *r; l--, r++) {

        }
        for (l = p, r = p + 1; l >= s && r < s && *l == *r; l--, r++) {

        }
    }


}