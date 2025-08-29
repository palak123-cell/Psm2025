#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int lastIndex[256]; // ASCII characters
    for (int i = 0; i < 256; i++)
        lastIndex[i] = -1;

    int maxLen = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        
        if (lastIndex[(unsigned char)s[end]] >= start) {
            start = lastIndex[(unsigned char)s[end]] + 1;
        }
        
        lastIndex[(unsigned char)s[end]] = end;

        
        int currLen = end - start + 1;
        if (currLen > maxLen)
            maxLen = currLen;
    }

    return maxLen;
}

int main() {
    char s[100005];
    printf("Enter string: ");
    scanf("%s", s);

    int result = lengthOfLongestSubstring(s);
    printf("Length of longest substring without repeating characters: %d\n", result);

    return 0;
}
