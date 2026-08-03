int **result;
int *colSizes;
int *path;
int returnSize;

void dfs(int *nums, int numsSize, int index, int depth) {
    result[returnSize] = (int *)malloc(depth * sizeof(int));
    memcpy(result[returnSize], path, depth * sizeof(int));
    colSizes[returnSize] = depth;
    returnSize++;

    for (int i = index; i < numsSize; i++) {
        path[depth] = nums[i];
        dfs(nums, numsSize, i + 1, depth + 1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSizePtr, int** returnColumnSizes) {
    int total = 1 << numsSize;

    result = (int **)malloc(total * sizeof(int *));
    colSizes = (int *)malloc(total * sizeof(int));
    path = (int *)malloc(numsSize * sizeof(int));
    returnSize = 0;

    dfs(nums, numsSize, 0, 0);

    free(path);

    *returnSizePtr = returnSize;
    *returnColumnSizes = colSizes;

    return result;
}