int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize,
             int* returnSize, int** returnColumnSizes) {
    
    int **res = (int **)malloc((intervalsSize + 1) * sizeof(int *));
    *returnColumnSizes = (int *)malloc((intervalsSize + 1) * sizeof(int));
    *returnSize = 0;

    int i = 0;

    while (i < intervalsSize && intervals[i][0] < newInterval[0]) {
        res[*returnSize] = (int *)malloc(2 * sizeof(int));
        res[*returnSize][0] = intervals[i][0];
        res[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        i++;
    }

    res[*returnSize] = (int *)malloc(2 * sizeof(int));
    res[*returnSize][0] = newInterval[0];
    res[*returnSize][1] = newInterval[1];
    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;

    while (i < intervalsSize) {
        res[*returnSize] = (int *)malloc(2 * sizeof(int));
        res[*returnSize][0] = intervals[i][0];
        res[*returnSize][1] = intervals[i][1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        i++;
    }

    int k = 0;
    for (i = 1; i < *returnSize; i++) {
        if (res[k][1] >= res[i][0]) {
            if (res[i][1] > res[k][1])
                res[k][1] = res[i][1];
        } else {
            k++;
            res[k] = res[i];
            (*returnColumnSizes)[k] = 2;
        }
    }

    *returnSize = k + 1;
    return res;
}