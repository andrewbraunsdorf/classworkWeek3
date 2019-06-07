#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

// struct called node containing an int identified as 'value', reference to another node identified as 'next'

// reference through a value

typedef struct NODE
{
    // identifer
    int value;
    struct NODE *next;
} NODE;

NODE *rootNode;

// int add(int x, int y)
// {
//     return x + y;
// }
// int modifyAdder(int *x, int y)
// {
//     *x += 7;
//     return *x + y;
// }

// iterate through the linked list until you get to the end
// once at end print out last value
// once at the end add the new node to the list

void addNode(int value)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->next = NULL;
    if (rootNode == NULL)
    {
        rootNode = newNode;
        return;
    }

    // NODE *trav = homeNode;
    NODE *trav = rootNode;
    while (trav->next != NULL)
    {
        trav = trav-> next;
    }

    trav->next = newNode;



}

// // this was referencing an empty part of the cycle where it was not grabbing anything
// void addNode(int value, NODE *homeNode)
// {
//     NODE newNode;
//     newNode.value = value;
//     homeNode->next = &newNode;
// }
void removeNode(int value)
{
    NODE *trav = rootNode;
    if(rootNode->value == value)
    {
        rootNode = rootNode->next;
        free(trav);
        return;
    }

    // navigate list until it finds the list we want to observe
    while(trav->next->value != value)
    {
        trav = trav->next;
    }
    NODE *temp = trav->next;
    trav->next = temp->next;
    free(temp);
}

void displayList()
{
    NODE* trav = rootNode;
    // should display
    // 5, 10, 8, 17
     while(trav->next != NULL)
     {
         printf("%i, ", trav->value);
         trav = trav-> next;
     }
     printf("%i\n", trav->value);
}

// void freeList2()
// {
//     // create another variable?
//     // get to the last item if trav->next != NULL?
//     // delete last item
//     // maybe while ( lastNode = NULL)
//     // delete last node
//     if(rootNode->next == NULL)
//     {
//         free(rootNode);
//         return;
//     }

//     NODE *trav = rootNode;

//     // while(trav->next->value )
//     // {
//     //     trav = trav->next;
//     // }
//     // while(rootNode != NULL)
//     // {
//         while(trav->next != NULL)
//         {
//             trav = trav->next;
//             // delete last item in list... aka 17
//             // NODE *temp = trav;
//             // temp->next = trav->next;
//             free(trav->next);
//         }
//     // }

//     // free(temp);
//     // loop through find last item send value to remove code
//     // loop through find 2nd to last remove item and set to null until head remains
//     // recursively iterate through the list to remove all items
// }

void freeList()
{
// loop through find last item send value to remove code
// loop through find 2nd to last remove item and set to null until head remains
// recursively iterate through the list to remove all items

    while(rootNode->next !=NULL)
    {
        NODE *trav = rootNode;
        while(trav->next->next != NULL)
        {
            trav = trav->next;
        }
        printf("%i\n", trav-> value);
        // deletes last item in list
        free(trav->next);
        // now you are making the last ("second to last item") equal to NULL
        trav->next = NULL;
        // return;
    }
    free(rootNode);

}

void freelistFunction()
{
        while (rootNode->next != NULL)
    {
        NODE *trav = rootNode;
        while (trav->next != NULL)
        {
            trav = trav-> next;
        }
        // remove node is setting next to last digit to NULL
        removeNode(trav->value);
    }

    free(rootNode);
// only works for the rootNode
// if (rootNode->next == NULL)
// {
//     free(rootNode);
// }
}


int main(void)
{
    addNode(5);
    addNode(10);
    addNode(8);
    addNode(17);
    // removeNode(8);
    freeList();
    displayList();

    // printf("%i\n%i\n", rootNode.next->next->value, rootNode.next->next->next->value);
}
