char* simplifyPath(char* path) {
    int n = strlen(path);
    char **stack = (char **)malloc((n + 1) * sizeof(char *));
    int top = 0;
    char *token = strtok(path, "/");

    while (token) {
        if (strcmp(token, ".") == 0) {
        } else if (strcmp(token, "..") == 0) {
            if (top > 0) top--;
        } else {
            stack[top++] = token;
        }
        token = strtok(NULL, "/");
    }

    char *res = (char *)malloc(n + 2);
    int pos = 0;

    if (top == 0) {
        res[pos++] = '/';
    } else {
        for (int i = 0; i < top; i++) {
            res[pos++] = '/';
            int len = strlen(stack[i]);
            memcpy(res + pos, stack[i], len);
            pos += len;
        }
    }

    res[pos] = '\0';
    free(stack);
    return res;
}