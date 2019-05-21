#include <cs50.h>
#include <stdio.h>

int add(int x, int y)
{
    return x + y;
}
int modifyAdder(int *x, int y)
{
    *x+= 7;
    return *x + y;
}

int main (void)
{
    int a = 5;
    int b = 13;
    printf("The total is %i!\n", add(a, b));
    printf("The modified total is %i!\n", modifyAdder(&a, b));
    printf("Running normal add again: %i!\n", add(a,b));
    printf("The modified again is %i!\n", modifyAdder(&a, b));
    printf("Running normal add a second time: %i!\n", add(a, b));

    // int* intPointer = &b;
    // printf("b is %i\n", b);
    // *intPointer += 4;
    // printf("now b is %i\n", b);
}