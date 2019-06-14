#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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


int doesContain(int value)
{
    // if (rootNode->value == value)
    // {
    //     printf("Match\n");
    //     return 1;
    // }
    NODE *trav = rootNode;
    while(1)
    {
        if(trav->value == value)
        {
            printf("Match\n");
            return 1;
        }
        if (value < trav->value)
        {
            if (trav->low == NULL)
            {
                return 0;
            }
            trav = trav->low;
            continue;
        }
        if (!trav->high)
        {
            return 0;
        }
        trav = trav->high;
        continue;
    }
}

void tests()
{
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
    addNode(14);
    addNode(12);
    // displayList();

    // displayTreeOnEnter(rootNode);s
    displayTreeOnDeparture(rootNode);
    printf("\n");


    assert(doesContain(10) && "tree does contain 10");
    assert(doesContain(8) && "tree does contain 8");
    assert(doesContain(4) && "tree does contain 4");
    assert(!doesContain(1) && "tree does contain 1");
    assert(doesContain(15) && "tree does contain 15");
    assert(!doesContain(100) && "tree does contain 1");
    assert(doesContain(13) && "tree does contain 15");
    assert(doesContain(18) && "tree does contain 15");
    assert(!doesContain(16) && "tree does contain 15");
}
int main(void)
{
    printf("hello\n");

    tests();

}