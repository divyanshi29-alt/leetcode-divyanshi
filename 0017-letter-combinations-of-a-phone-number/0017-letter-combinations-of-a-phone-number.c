char *map[] = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char *digits, int index, char *current,
               char **result, int *returnSize)
{
    if (digits[index] == '\0')
    {
        result[*returnSize] = (char *)malloc(strlen(current) + 1);
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    char *letters = map[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++)
    {
        current[index] = letters[i];
        current[index + 1] = '\0';

        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize)
{
    *returnSize = 0;

    if (digits[0] == '\0')
        return NULL;

  
    char **result = (char **)malloc(256 * sizeof(char *));
    char current[5];

    backtrack(digits, 0, current, result, returnSize);

    return result;
}