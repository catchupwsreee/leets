#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void backtrack(int* nums, int numsSize, int* used, int* temp, int depth, int** res, int* returnSize) {
    if (depth == numsSize) {
        res[*returnSize] = malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++)
            res[*returnSize][i] = temp[i];
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        used[i] = 1;
        temp[depth] = nums[i];
        backtrack(nums, numsSize, used, temp, depth + 1, res, returnSize);
        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxPerms = 1;
    for (int i = 2; i <= numsSize; i++) maxPerms *= i;
    int** res = malloc(sizeof(int*) * maxPerms);
    *returnColumnSizes = malloc(sizeof(int) * maxPerms);
    int* temp = malloc(sizeof(int) * numsSize);
    int* used = calloc(numsSize, sizeof(int));
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    backtrack(nums, numsSize, used, temp, 0, res, returnSize);
    for (int i = 0; i < *returnSize; i++) (*returnColumnSizes)[i] = numsSize;
    free(temp);
    free(used);
    return res;
}
