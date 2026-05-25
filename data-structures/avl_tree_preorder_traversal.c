#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* right;
    struct node* left;
} node;

node* createNode(int val) {
    node* tree = malloc(sizeof(node));
    if (tree != NULL) {
        tree->right = NULL;
        tree->left = NULL;
        tree->val = val;
    }
    return tree;
}

void printBSTPreorder(node* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        printBSTPreorder(root->left);
        printBSTPreorder(root->right);
    }
}

node* leftRotate(node* x) {
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

node* rightRotate(node* y) {
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

int height(node* root) {
    if (root == NULL)
        return 0;
    return 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
}

int getBalanceFactor(node* root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

node* balanceAVL(node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = balanceAVL(root->left, val);
    } else if (val > root->val) {
        root->right = balanceAVL(root->right, val);
    }

    int balance = getBalanceFactor(root);

    if (balance > 1 && val < root->left->val) {
        return rightRotate(root);
    }

    if (balance < -1 && val > root->right->val) {
        return leftRotate(root);
    }

    if (balance > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printAVLPreorder(node* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        printAVLPreorder(root->left);
        printAVLPreorder(root->right);
    }
}

int main() {
    node* n1 = createNode(1);
    node* n2 = createNode(2);
    node* n3 = createNode(3);
    node* n4 = createNode(4);
    node* n5 = createNode(5);

    n1->left = n2;
    n2->right = n3;
    n3->left = n4;
    n4->right = n5;

    node* rootBST = n1;
    node* rootAVL = NULL;
    printf("Omar Mian, mqg069\n ");

    printf("BST Pre-order: ");
    printBSTPreorder(rootBST);
    printf("\n");

    rootAVL = balanceAVL(NULL, 1);
    rootAVL = balanceAVL(rootAVL, 2);
    rootAVL = balanceAVL(rootAVL, 3);
    rootAVL = balanceAVL(rootAVL, 4);
    rootAVL = balanceAVL(rootAVL, 5);

    printf("Balanced (AVL) Pre-order: ");
    printAVLPreorder(rootAVL);
    printf("\n");

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}