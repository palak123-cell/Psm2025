#include <stdio.h>
#include <string.h>

int isValid(char *s) {
    char stack[10000]; 
    int top = -1;
    for(int i=0; s[i]; i++) {
        char c = s[i];
        if(c=='(' || c=='{' || c=='[') stack[++top] = c;
        else {
            if(top==-1) return 0;
            char last = stack[top--];
            if((c==')' && last!='(') || (c=='}' && last!='{') || (c==']' && last!='['))
                return 0;
        }
    }
    return top==-1;
}

int main() {
    char s[10000];
    scanf("%s", s);
    if(isValid(s)) printf("true\n");
    else printf("false\n");
    return 0;
}
