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

    if (rootNode->value > value)
    {
        rootNode->left = newNode;
    }
    else
    // (rootNode->value > value)
    {
        rootNode->right = newNode;
    }
}

void addSecondNode(int value)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (rootNode->value > value)
    {
        if (rootNode->left->value > value)
        {
            rootNode->left->left = newNode;
        }
        else
        {
            rootNode->left->right = newNode;
        }
    }
    else
    {
        if (rootNode->right->value > value)
        {
            rootNode->right->left = newNode;
        }
        else
        {
            rootNode->right->right = newNode;
        }
    }



    // if (rootNode->left->value < value)
    // {
    //     rootNode->left = newNode;
    // }
    // if (rootNode->right->value > value)
    // {
    //     rootNode->right = newNode;
    // }

    // if(rootNode != NULL)
    // {

    // }
}


int main(void)
{
    printf("hello\n");
    addNode(10);
    addNode(8);
    addNode(15);
    addSecondNode(20);
    addSecondNode(9);
    addSecondNode(7);
    addSecondNode(14);
    // displayList();
}