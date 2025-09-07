#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->val = v; n->left = n->right = NULL;
    return n;
}

struct Node* LCA(struct Node* root, struct Node* p, struct Node* q) {
    if (!root || root == p || root == q) return root;
    struct Node* l = LCA(root->left, p, q);
    struct Node* r = LCA(root->right, p, q);
    return l && r ? root : (l ? l : r);
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    struct Node* p = root->left;      // 5
    struct Node* q = root->right;     // 1
    printf("LCA: %d\n", LCA(root, p, q)->val);
}
