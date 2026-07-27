/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void backtrack(char **result, int *returnSize, char *current,
               int pos, int open, int close, int n) {

    if (pos == 2 * n) {
        current[pos] = '\0';
        result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        backtrack(result, returnSize, current, pos + 1, open + 1, close, n);
    }

    if (close < open) {
        current[pos] = ')';
        backtrack(result, returnSize, current, pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    // Maximum possible combinations for n <= 8 is 1430
    char **result = (char **)malloc(1430 * sizeof(char *));
    char *current = (char *)malloc((2 * n + 1) * sizeof(char));

    *returnSize = 0;

    backtrack(result, returnSize, current, 0, 0, 0, n);

    free(current);

    return result;
}
