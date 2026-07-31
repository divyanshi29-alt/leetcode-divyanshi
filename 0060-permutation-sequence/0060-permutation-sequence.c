char* getPermutation(int n, int k) {
    int fact = 1;
    int nums[9];

    for (int i = 1; i < n; i++)
        fact *= i;

    for (int i = 0; i < n; i++)
        nums[i] = i + 1;

    char *ans = (char *)malloc((n + 1) * sizeof(char));
    int idx = 0;
    k--;

    while (n > 0) {
        int pos = k / fact;
        ans[idx++] = nums[pos] + '0';

        for (int i = pos; i < n - 1; i++)
            nums[i] = nums[i + 1];

        n--;

        if (n == 0)
            break;

        k %= fact;
        fact /= n;
    }

    ans[idx] = '\0';
    return ans;
}