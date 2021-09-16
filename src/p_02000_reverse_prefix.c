
char *reversePrefix(char *word, char ch) {
    char *l = word, *r = word;
    char tmp;
    for (; *r != ch && *r != '\0'; r++);
    if (*r == '\0') {
        return word;
    }
    while (l < r) {
        tmp = *l;
        *l++ = *r;
        *r-- = tmp;
    }
    return word;
}
