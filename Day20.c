#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int *a;
    int top, cap;
} Stack;

void init(Stack *s, int cap){ s->a = malloc(cap*sizeof(int)); s->cap=cap; s->top=-1; }
bool empty(Stack *s){ return s->top==-1; }
bool full (Stack *s){ return s->top==s->cap-1; }
void push (Stack *s, int x){ if(!full(s)) s->a[++s->top]=x; }
int  pop  (Stack *s){ return empty(s)? INT_MIN : s->a[s->top--]; }
int  peek (Stack *s){ return empty(s)? INT_MIN : s->a[s->top]; }

void insertSorted(Stack *s, int x){
    if (empty(s) || x <= peek(s)) { push(s, x); return; }
    int t = pop(s);
    insertSorted(s, x);
    push(s, t);
}

void sortStack(Stack *s){
    if (empty(s)) return;
    int t = pop(s);
    sortStack(s);
    insertSorted(s, t);
}

int main(void){
    int n; 
    if (scanf("%d", &n)!=1 || n<0) return 0;
    Stack st; init(&st, n);

    
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); push(&st, x); }

    sortStack(&st);

    
    while(!empty(&st)){
        printf("%d ", pop(&st));
    }
    printf("\n");
    free(st.a);
    return 0;
}
