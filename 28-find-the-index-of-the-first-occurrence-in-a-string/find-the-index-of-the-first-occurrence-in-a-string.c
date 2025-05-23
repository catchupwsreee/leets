#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
    int lenH = strlen(haystack);
    int lenN = strlen(needle);

    if (lenN == 0) return 0;

    for (int i = 0; i <= lenH - lenN; i++) {
        int j = 0;
        while (j < lenN && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == lenN) return i;
    }

    return -1;
}
