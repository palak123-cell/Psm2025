#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int v){ Node* n=malloc(sizeof(Node)); n->val=v; n->left=n->right=NULL; return n; }

bool mirror(Node* a, Node* b){
    if(!a && !b) return true;
    if(!a || !b) return false;
    return a->val==b->val && mirror(a->left,b->right) && mirror(a->right,b->left);
}

bool isSym(Node* r){ return !r || mirror(r->left,r->right); }

int main(){
    Node* r=newNode(1);
    r->left=newNode(2); r->right=newNode(2);
    r->left->left=newNode(3); r->left->right=newNode(4);
    r->right->left=newNode(4); r->right->right=newNode(3);
    printf(isSym(r)?"true\n":"false\n");
    return 0;
}
