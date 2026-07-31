int cmp(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;
    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    int **res = (int **)malloc(intervalsSize * sizeof(int *));
    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < intervalsSize; i++) {
        if (*returnSize == 0 ||
            res[*returnSize - 1][1] < intervals[i][0]) {
            res[*returnSize] = (int *)malloc(2 * sizeof(int));
            res[*returnSize][0] = intervals[i][0];
            res[*returnSize][1] = intervals[i][1];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        } else {
            if (intervals[i][1] > res[*returnSize - 1][1])
                res[*returnSize - 1][1] = intervals[i][1];
        }
    }

    return res;
}