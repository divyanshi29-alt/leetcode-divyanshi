/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *word;
    int count;
} WordEntry;

int findWord(WordEntry *arr, int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].word, word) == 0)
            return i;
    }
    return -1;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;

    if (wordsSize == 0)
        return NULL;

    int wordLen = strlen(words[0]);
    int sLen = strlen(s);
    int totalLen = wordLen * wordsSize;

    if (sLen < totalLen)
        return NULL;

    WordEntry *dict = (WordEntry *)malloc(wordsSize * sizeof(WordEntry));
    int dictSize = 0;

    // Build frequency dictionary
    for (int i = 0; i < wordsSize; i++) {
        int idx = findWord(dict, dictSize, words[i]);
        if (idx == -1) {
            dict[dictSize].word = words[i];
            dict[dictSize].count = 1;
            dictSize++;
        } else {
            dict[idx].count++;
        }
    }

    int *result = (int *)malloc((sLen + 1) * sizeof(int));

    char *temp = (char *)malloc(wordLen + 1);

    for (int offset = 0; offset < wordLen; offset++) {

        int *seen = (int *)calloc(dictSize, sizeof(int));

        int left = offset;
        int matched = 0;

        for (int right = offset; right + wordLen <= sLen; right += wordLen) {

            strncpy(temp, s + right, wordLen);
            temp[wordLen] = '\0';

            int idx = findWord(dict, dictSize, temp);

            if (idx == -1) {
                memset(seen, 0, dictSize * sizeof(int));
                matched = 0;
                left = right + wordLen;
                continue;
            }

            seen[idx]++;
            matched++;

            while (seen[idx] > dict[idx].count) {
                strncpy(temp, s + left, wordLen);
                temp[wordLen] = '\0';

                int leftIdx = findWord(dict, dictSize, temp);
                seen[leftIdx]--;
                matched--;
                left += wordLen;
            }

            if (matched == wordsSize) {
                result[(*returnSize)++] = left;

                strncpy(temp, s + left, wordLen);
                temp[wordLen] = '\0';

                int leftIdx = findWord(dict, dictSize, temp);
                seen[leftIdx]--;
                matched--;
                left += wordLen;
            }
        }

        free(seen);
    }

    free(temp);
    free(dict);

    return result;
}