#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

void modifyArray(int theArray[])
{
    theArray[2] = 44;
    for (int number = 0; number < 3; number++)
    {
        printf("The number at %i is %i\n", number, theArray[number]);
    }
}

int main(void)
{

    int anArray[] = {28, 32, 29};
    printf("position 2 is %i\n", anArray[1]);
    modifyArray(anArray);
    printf("position 3 is %i\n", anArray[2]);

}