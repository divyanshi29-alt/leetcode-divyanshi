/**
 * Note: The returned string must be malloced, assume caller calls free().
 */
#include <string.h>
#include <stdlib.h>

char *addBinary(char *a, char *b) {
    int m = strlen(a);
    int n = strlen(b);
    int size = (m > n ? m : n) + 2;

    char *res = (char *)malloc(size);
    res[size - 1] = '\0';

    int i = m - 1, j = n - 1, k = size - 2;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        res[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    return res + k + 1;
}