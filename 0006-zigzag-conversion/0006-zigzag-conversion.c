char* convert(char* s, int numRows) {
    int n = strlen(s);

    if (numRows == 1 || numRows >= n)
        return strdup(s);

    char **rows = (char **)malloc(numRows * sizeof(char *));
    int *idx = (int *)calloc(numRows, sizeof(int));

    // Allocate memory for each row
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char *)malloc((n + 1) * sizeof(char));
    }

    int currRow = 0;
    int down = 1;

    for (int i = 0; i < n; i++) {
        rows[currRow][idx[currRow]++] = s[i];

        if (currRow == 0)
            down = 1;
        else if (currRow == numRows - 1)
            down = 0;

        if (down)
            currRow++;
        else
            currRow--;
    }

    // Build result
    char *ans = (char *)malloc((n + 1) * sizeof(char));
    int k = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < idx[i]; j++) {
            ans[k++] = rows[i][j];
        }
    }

    ans[k] = '\0';

    // Free allocated memory
    for (int i = 0; i < numRows; i++)
        free(rows[i]);
    free(rows);
    free(idx);

    return ans;
}