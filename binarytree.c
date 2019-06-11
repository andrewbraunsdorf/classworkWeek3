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
    // printf("trying to add node %i\n", newNode->value);
    while(1)
    {
        if (newNode->value < trav->value)
        {
            if(trav->low == NULL)
            {
                // printf("found empty spot\n");
                trav->low = newNode;
                return;
            }
            // printf("found a low node valued: %i maving to it\n", trav->low->value);
            trav = trav->low;
            // continue restarts the loop
            continue;
        }
        else
        {
            if (trav->high == NULL)
            {
                trav->high = newNode;
                return;
            }
            trav = trav->high;
            continue;
        }
    }
}
void displayTreeOnEnter(NODE *curNode)
{
    printf("%i, ", curNode->value);

    // these are identicals
    // if(curNode->low != NULL)
    if(curNode->low)
    {
        displayTreeOnEnter(curNode->low);
    }

    if(curNode->high)
    {
        displayTreeOnEnter(curNode->high);
    }
}
void displayTreeOnDeparture(NODE *curNode)
// 4 7 6 5 9 8 13 18 20 17 15 10
{
    // these are identicals
    // if(curNode->low != NULL)
    if(curNode->low)
    {
        displayTreeOnDeparture(curNode->low);
    }

    if(curNode->high)
    {
        displayTreeOnDeparture(curNode->high);
    }
    printf("%i, ", curNode->value);
}

void doesContain(int value)
{
    //search the tree
    // return 1 if value is not in the tree
    // return 0 if value does exist in the tree
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

    // displayTreeOnEnter(rootNode);
    displayTreeOnDeparture(rootNode);
    printf("\n");
}