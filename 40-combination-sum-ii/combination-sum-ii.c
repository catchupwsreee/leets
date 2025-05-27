#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* path, int pathSize,
               int** res, int* resSize, int* resColSize,
               int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        res[*resSize] = (int*)malloc(pathSize * sizeof(int));
        for (int i = 0; i < pathSize; i++)
            res[*resSize][i] = path[i];
        resColSize[*resSize] = pathSize;
        (*resSize)++;
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;
        path[pathSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i + 1,
                  path, pathSize + 1, res, resSize, resColSize, returnSize, returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int** res = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    int resSize = 0;
    int* path = (int*)malloc(candidatesSize * sizeof(int));
    backtrack(candidates, candidatesSize, target, 0, path, 0, res, &resSize, *returnColumnSizes, returnSize, returnColumnSizes);
    free(path);
    *returnSize = resSize;
    return res;
}
