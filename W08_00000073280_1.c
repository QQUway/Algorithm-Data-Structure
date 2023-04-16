#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(char data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insertNode(Node *node, char data) {
    if(node == NULL) {
        return createNode(data);
    }
    if(data < node->data) {
        node->left = insertNode(node->left, data);
    } else {
        node->right = insertNode(node->right, data);
    }
    return node;
}

void inorder(Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root) {
    if(root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    Node *root = NULL;

    // a. - ∗ + a b c d
    root = insertNode(root, '-');
    root = insertNode(root, '*');
    root = insertNode(root, '+');
    root = insertNode(root, 'a');
    root = insertNode(root, 'b');
    root = insertNode(root, 'c');
    root = insertNode(root, 'd');

    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n\n");

    // b. ∗ + a b + c d
    root = NULL;
    root = insertNode(root, '*');
    root = insertNode(root, '+');
    root = insertNode(root, 'a');
    root = insertNode(root, 'b');
    root = insertNode(root, '+');
    root = insertNode(root, 'c');
    root = insertNode(root, 'd');

    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n\n");

    // c. + / a b / c d
    root = NULL;
    root = insertNode(root, '+');
    root = insertNode(root, '/');
    root = insertNode(root, 'a');
    root = insertNode(root, 'b');
    root = insertNode(root, '/');
    root = insertNode(root, 'c');
    root = insertNode(root, 'd');

    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n\n");

    return 0;
}
