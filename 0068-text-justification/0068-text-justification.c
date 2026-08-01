/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
#include <stdlib.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char **result = (char **)malloc(wordsSize * sizeof(char *));
    int count = 0;
    int i = 0;

    while (i < wordsSize) {
        int j = i;
        int len = 0;

        while (j < wordsSize && len + strlen(words[j]) + (j - i) <= maxWidth) {
            len += strlen(words[j]);
            j++;
        }

        int gaps = j - i - 1;
        char *line = (char *)malloc(maxWidth + 1);
        int pos = 0;

        if (j == wordsSize || gaps == 0) {
            for (int k = i; k < j; k++) {
                int l = strlen(words[k]);
                memcpy(line + pos, words[k], l);
                pos += l;
                if (k != j - 1)
                    line[pos++] = ' ';
            }
            while (pos < maxWidth)
                line[pos++] = ' ';
        } else {
            int spaces = (maxWidth - len) / gaps;
            int extra = (maxWidth - len) % gaps;

            for (int k = i; k < j; k++) {
                int l = strlen(words[k]);
                memcpy(line + pos, words[k], l);
                pos += l;

                if (k != j - 1) {
                    int s = spaces + (extra > 0 ? 1 : 0);
                    while (s--)
                        line[pos++] = ' ';
                    if (extra > 0)
                        extra--;
                }
            }
        }

        line[maxWidth] = '\0';
        result[count++] = line;
        i = j;
    }

    *returnSize = count;
    return result;
}