#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int len, i, printed = 0;

    scanf(" %999[^\n]", str);      // read a full line safely
    len = strlen(str);

    for (i = len - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[i] = '\0';
            if (str[i + 1] != '\0') {
                if (printed) printf(" ");
                printf("%s", &str[i + 1]);
                printed = 1;
            }
        }
    }
    if (str[0] != '\0') {
        if (printed) printf(" ");
        printf("%s", str);
    }
    return 0;
}
