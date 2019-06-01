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


int add(int x, int y)
{
    return x + y;
}
int modifyAdder(int *x, int y)
{
    *x+= 7;
    return *x + y;
}

// iterate through the linked list until you get to the end
// once at end print out last value
// once at the end add the new node to the list

void addNode(int value, NODE *homeNode)
{
    NODE *trav = homeNode;
    // 1 = true in the cs50 library it adds
    while(1)
    {
        if (trav->next == NULL)
        {
            NODE *newNode = malloc(sizeof(NODE));
            newNode->value = value;
            //want to nullify whatever data is there.
            //are we at the end of our list
            newNode->next = NULL;
            trav->next = newNode;
            break;
        }

        else
        {
            trav = trav-> next;
            printf("Moved Deeper\n");
        }
    }


}

// // this was referencing an empty part of the cycle where it was not grabbing anything
// void addNode(int value, NODE *homeNode)
// {
//     NODE newNode;
//     newNode.value = value;
//     homeNode->next = &newNode;
// }

int main (void)
{
    NODE rootNode;
    rootNode.value = 5;
    rootNode.next = NULL;

    addNode(10, &rootNode);

    printf("%i\n", rootNode.value);
    printf("%i\n", rootNode.next->value);

    addNode(8, &rootNode);
    // printf("added next value\n");
    addNode(17, &rootNode);
    // addNode(20, &rootNode);

    printf("%i\n%i\n", rootNode.next->next->value, rootNode.next->next->next->value);

    // NODE secondNode;
    // secondNode.value = 10;
    // rootNode.next = &secondNode;

    // int a = 5;
    // int b = 13;
    // printf("The total is %i!\n", add(a, b));
    // printf("The modified total is %i!\n", modifyAdder(&a, b));
    // printf("Running normal add again: %i!\n", add(a,b));
    // printf("The modified again is %i!\n", modifyAdder(&a, b));
    // printf("Running normal add a second time: %i!\n", add(a, b));

    // int* intPointer = &b;
    // printf("b is %i\n", b);
    // *intPointer += 4;
    // printf("now b is %i\n", b);



}