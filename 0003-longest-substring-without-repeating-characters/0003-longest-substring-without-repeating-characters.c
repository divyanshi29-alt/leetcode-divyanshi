int lengthOfLongestSubstring(char *s) {
    int last[256];
    
    // Initialize all last occurrences to -1
    for (int i = 0; i < 256; i++) {
        last[i] = -1;
    }

    int left = 0;
    int maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char ch = s[right];

        // If character is already in the current window,
        // move the left pointer
        if (last[ch] >= left) {
            left = last[ch] + 1;
        }

        // Update last occurrence
        last[ch] = right;

        // Update maximum length
        int currLen = right - left + 1;
        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }

    return maxLen;
}
