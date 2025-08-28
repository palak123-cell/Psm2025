#include <stdio.h>
#include <string.h>

int atMostK(char *s, int k) {
    int n = strlen(s), freq[26] = {0}, left = 0, distinct = 0, count = 0;
    for (int right = 0; right < n; right++) {
        if (!freq[s[right]-'a']) distinct++;
        freq[s[right]-'a']++;
        while (distinct > k) {
            if (--freq[s[left]-'a'] == 0) distinct--;
            left++;
        }
        count += right - left + 1;
    }
    return count;
}

int exactlyK(char *s, int k) {
    return atMostK(s,k) - atMostK(s,k-1);
}

int main() {
    char s[105]; int k;
    scanf("%s %d", s, &k);
    printf("%d\n", exactlyK(s,k));
    return 0;
}
