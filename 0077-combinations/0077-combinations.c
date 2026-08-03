int **result;
int *colSizes;
int *path;
int returnSize;

int combinationCount(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return combinationCount(n - 1, k - 1) + combinationCount(n - 1, k);
}

void dfs(int start, int n, int k, int depth) {
    if (depth == k) {
        result[returnSize] = (int *)malloc(k * sizeof(int));
        memcpy(result[returnSize], path, k * sizeof(int));
        colSizes[returnSize] = k;
        returnSize++;
        return;
    }

    for (int i = start; i <= n - (k - depth) + 1; i++) {
        path[depth] = i;
        dfs(i + 1, n, k, depth + 1);
    }
}

int** combine(int n, int k, int* returnSizePtr, int** returnColumnSizes) {
    int total = combinationCount(n, k);

    result = (int **)malloc(total * sizeof(int *));
    colSizes = (int *)malloc(total * sizeof(int));
    path = (int *)malloc(k * sizeof(int));
    returnSize = 0;

    dfs(1, n, k, 0);

    *returnSizePtr = returnSize;
    *returnColumnSizes = colSizes;

    free(path);

    return result;
}