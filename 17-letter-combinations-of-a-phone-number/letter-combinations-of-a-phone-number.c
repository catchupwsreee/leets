#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *map[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void dfs(char *digits, int pos, char *path, char **res, int *returnSize) {
    if (digits[pos] == '\0') {
        res[*returnSize] = strdup(path);
        (*returnSize)++;
        return;
    }
    const char *letters = map[digits[pos] - '2'];
    for (int i = 0; letters[i] != '\0'; i++) {
        path[pos] = letters[i];
        dfs(digits, pos + 1, path, res, returnSize);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    *returnSize = 0;
    if (digits[0] == '\0') return NULL;
    int len = strlen(digits);
    char **res = (char **)malloc(sizeof(char *) * 1000);
    char *path = (char *)malloc(sizeof(char) * (len + 1));
    path[len] = '\0';
    dfs(digits, 0, path, res, returnSize);
    free(path);
    return res;
}
