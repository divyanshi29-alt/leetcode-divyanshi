#include <stdbool.h>

bool isNumber(char* s) {
    int i = 0;
    bool num = false;
    bool dot = false;
    bool exp = false;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = true;
        } else if (s[i] == '.') {
            if (dot || exp)
                return false;
            dot = true;
        } else if (s[i] == 'e' || s[i] == 'E') {
            if (exp || !num)
                return false;
            exp = true;
            num = false;
            if (s[i + 1] == '+' || s[i + 1] == '-')
                i++;
        } else {
            return false;
        }
    }

    return num;
}