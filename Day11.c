#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){ char t=*a; *a=*b; *b=t; }

int used(char str[], int l, int i){
    for(int k=l;k<i;k++) if(str[k]==str[i]) return 1;
    return 0;
}

void permute(char str[], int l, int r){
    if(l==r){ printf("%s\n",str); return; }
    for(int i=l;i<=r;i++){
        if(!used(str,l,i)){
            swap(&str[l],&str[i]);
            permute(str,l+1,r);
            swap(&str[l],&str[i]);
        }
    }
}

int main(){
    char str[20];
    scanf("%s",str);
    permute(str,0,strlen(str)-1);
}
