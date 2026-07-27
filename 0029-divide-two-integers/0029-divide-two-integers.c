#include <limits.h>

int divide(int dividend, int divisor) {
    // Overflow case
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long dvd = dividend;
    long long dvs = divisor;

    // Determine the sign
    int sign = ((dvd < 0) ^ (dvs < 0)) ? -1 : 1;

    // Take absolute values
    if (dvd < 0) dvd = -dvd;
    if (dvs < 0) dvs = -dvs;

    long long result = 0;

    while (dvd >= dvs) {
        long long temp = dvs;
        long long multiple = 1;

        while ((temp << 1) <= dvd) {
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        result += multiple;
    }

    result = (sign == 1) ? result : -result;

    return (int)result;
}