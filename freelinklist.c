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

void freeList()


int main(void)
{
    addNode(5);
    addNode(10);
    addNode(8);
    addNode(17);
    // removeNode(8);
    // freelist();
    freeList(rootNode);
    displayList();

    // printf("%i\n%i\n", rootNode.next->next->value, rootNode.next->next->next->value);
}