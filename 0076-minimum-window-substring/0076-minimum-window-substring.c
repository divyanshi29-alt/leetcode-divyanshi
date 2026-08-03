char * minWindow(char * s, char * t) {
    int need[128] = {0};
    int required = 0;

    for (int i = 0; t[i]; i++) {
        if (need[(unsigned char)t[i]] == 0)
            required++;
        need[(unsigned char)t[i]]++;
    }

    int window[128] = {0};
    int formed = 0;
    int left = 0, right = 0;
    int start = 0, minLen = INT_MAX;

    while (s[right]) {
        char c = s[right];
        window[(unsigned char)c]++;

        if (need[(unsigned char)c] &&
            window[(unsigned char)c] == need[(unsigned char)c])
            formed++;

        while (left <= right && formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            char d = s[left];
            window[(unsigned char)d]--;

            if (need[(unsigned char)d] &&
                window[(unsigned char)d] < need[(unsigned char)d])
                formed--;

            left++;
        }

        right++;
    }

    if (minLen == INT_MAX)
        return "";

    s[start + minLen] = '\0';
    return s + start;
}