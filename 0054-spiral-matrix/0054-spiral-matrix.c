int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int total = rows * cols;

    int* ans = (int*)malloc(total * sizeof(int));
    *returnSize = total;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int k = 0;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            ans[k++] = matrix[top][j];
        top++;

        for (int i = top; i <= bottom; i++)
            ans[k++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                ans[k++] = matrix[bottom][j];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans[k++] = matrix[i][left];
            left++;
        }
    }

    return ans;
}