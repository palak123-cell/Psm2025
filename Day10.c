#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void sortString(char *str) {
    int n = strlen(str);
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char strs[][10] = {"eat","tea","tan","ate","nat","bat"};
    int n = 6;

    int visited[10] = {0};

    for(int i=0;i<n;i++) {
        if(visited[i]) continue;

        char key1[10];
        strcpy(key1, strs[i]);
        sortString(key1);

        printf("[");
        for(int j=i;j<n;j++) {
            char key2[10];
            strcpy(key2, strs[j]);
            sortString(key2);

            if(strcmp(key1, key2)==0) {
                printf("%s ", strs[j]);
                visited[j] = 1;
            }
        }
        printf("]\n");
    }
    return 0;
}
