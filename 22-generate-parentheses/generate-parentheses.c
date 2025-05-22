#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char **result, int *returnSize, char *current, int pos, int open, int close, int max) {
    if (pos == max * 2) {
        current[pos] = '\0';
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    if (open < max) {
        current[pos] = '(';
        backtrack(result, returnSize, current, pos + 1, open + 1, close, max);
    }

    if (close < open) {
        current[pos] = ')';
        backtrack(result, returnSize, current, pos + 1, open, close + 1, max);
    }
}

char **generateParenthesis(int n, int *returnSize) {
    int maxCombinations = 1 << (2 * n);  // estimate capacity (safe over-approximation)
    char **result = (char **)malloc(maxCombinations * sizeof(char *));
    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    *returnSize = 0;

    backtrack(result, returnSize, current, 0, 0, 0, n);

    free(current);
    return result;
}
