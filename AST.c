#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASTNode {
    char *value;
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;
ASTNode* createLeaf(char *value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->value = strdup(value);
    node->left = node->right = NULL;
    return node;
}

ASTNode* createNode(char *value, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->value = strdup(value);
    node->left = left;
    node->right = right;
    return node;
}
ASTNode* buildAST() {
    // Leaves
    ASTNode *a1 = createLeaf("a");
    ASTNode *a2 = createLeaf("a");
    ASTNode *b1 = createLeaf("b");
    ASTNode *c1 = createLeaf("c");
    ASTNode *b2 = createLeaf("b");
    ASTNode *c2 = createLeaf("c");
    ASTNode *d = createLeaf("d");

    // Subtrees
    ASTNode *sub1 = createNode("-", b1, c1);          // b - c
    ASTNode *mul1 = createNode("*", a2, sub1);        // a * (b - c)
    ASTNode *add1 = createNode("+", a1, mul1);        // a + a * (b - c)

    ASTNode *sub2 = createNode("-", b2, c2);          // b - c
    ASTNode *mul2 = createNode("*", sub2, d);         // (b - c) * d

    // Final AST
    ASTNode *root = createNode("+", add1, mul2);      // a + a * (b - c) + (b - c) * d

    return root;
}
void printAST(ASTNode *node, int level) {
    if (node == NULL) return;



    printAST(node->left, level + 1);
    printAST(node->right, level + 1);
    for (int i = 0; i < level; i++) printf(" ");
    printf("%s ", node->value);
}
/*void printAST(ASTNode *node, int level) {
    if (node == NULL) return;

    printAST(node->right, level + 1);
    for (int i = 0; i < level; i++) printf("    ");
    printf("%s\n", node->value);
    printAST(node->left, level + 1);
}*/
void freeAST(ASTNode *node) {
    if (node == NULL) return;
    freeAST(node->left);
    freeAST(node->right);
    free(node->value);
    free(node);
}
int main() {
    ASTNode *ast = buildAST();
    printf("Abstract Syntax Tree:\n");
    printAST(ast, 0);
    freeAST(ast);
    return 0;
}

