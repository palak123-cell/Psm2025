#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->val = v; n->left = n->right = NULL;
    return n;
}

int isBST(struct Node* root, long min, long max) {
    if (!root) return 1;
    if (root->val <= min || root->val >= max) return 0;
    return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
}

int main() {
    struct Node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);
    printf(isBST(root, LONG_MIN, LONG_MAX) ? "true\n" : "false\n");
}
