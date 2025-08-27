#include <stdio.h>
#include <string.h>

void longestPalindrome(char str[], int n) {
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        
        int low = i, high = i;
        while (low >= 0 && high < n && str[low] == str[high]) {
            if (high - low + 1 > maxLen) {
                start = low;
                maxLen = high - low + 1;
            }
            low--;
            high++;
        }

        low = i; high = i + 1;
        while (low >= 0 && high < n && str[low] == str[high]) {
            if (high - low + 1 > maxLen) {
                start = low;
                maxLen = high - low + 1;
            }
            low--;
            high++;
        }
    }

    for (int i = start; i < start + maxLen; i++)
        printf("%c", str[i]);
    printf("\n");
}

int main() {
    int n;
    char str[1001];

    scanf("%d", &n);
    scanf("%s", str);

    longestPalindrome(str, n);

    return 0;
}
