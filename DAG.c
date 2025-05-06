#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char data[10];
    struct Node *left;
    struct Node *right;
};


struct Node* newNode(char *data, struct Node *left, struct Node *right) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    strcpy(temp->data, data);
    temp->left = left;
    temp->right = right;
    return temp;
}

// Postfix
void print(struct Node *root) {
    if (root == NULL) return;
    print(root->left);
    print(root->right);
    printf("%s ", root->data);
}

int main() {

    struct Node *a = newNode("a", NULL, NULL);
    struct Node *b = newNode("b", NULL, NULL);
    struct Node *c = newNode("c", NULL, NULL);
    struct Node *d = newNode("d", NULL, NULL);


    struct Node *sub1 = newNode("-", b, c);


    struct Node *sub2 = newNode("*", a, sub1);


    struct Node *sub3 = newNode("*", sub1, d);


    struct Node *sub4 = newNode("+", a, sub2);


    struct Node *final = newNode("+", sub4, sub3);

    printf("Postfix of expression DAG:\n");
    print(final);
    printf("\n");

    return 0;
}

