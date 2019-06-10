#include <stdio.h>
#include <stdlib.h>

// minichallenge create the NODE for a binary tree.

#define true 1
#define false 0
typedef struct NODE
{
    // identifer
    int value;
    struct NODE *low;
    struct NODE *high;
} NODE;

NODE *rootNode;

void addNode(int value)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->low = NULL;
    newNode->high = NULL;

    if(rootNode == NULL)
    {
        rootNode = newNode;
        return;
    }

    NODE *trav = rootNode;
    while(1)
    {
        if (newNode->value < trav->value)
        {
            if(trav->low == NULL)
            {
                trav->low = newNode;
                return;
            }
            trav = trav->low;
            // continue restarts the loop
            continue;
        }
        else
        {
            rootNode->high = newNode;
            return;
        }
    }
}


int main(void)
{
    printf("hello\n");
    addNode(10);
    addNode(8);
    addNode(15);
    addNode(17);
    addNode(20);
    addNode(18);
    addNode(5);
    addNode(6);
    addNode(9);
    addNode(4);
    addNode(13);
    addNode(7);
    // displayList();
}