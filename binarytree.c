#include <stdio.h>
#include <stdlib.h>

// minichallenge create the NODE for a binary tree.

typedef struct NODE
{
    // identifer
    int value;
    struct NODE *left;
    struct NODE *right;
} NODE;

NODE *rootNode;

void addNode(int value)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if(rootNode == NULL)
    {
        rootNode = newNode;
        return;
    }
    if (rootNode->value < value)
    {
        rootNode->left = newNode;
    }
    else
    {
        rootNode->right = newNode;
    }
}
int main(void)
{
    printf("hello\n");
    addNode(10);
    addNode(8);
    addNode(15);
}