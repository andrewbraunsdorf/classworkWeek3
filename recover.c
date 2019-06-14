#include <stdio.h>
#include <stdlib.h>

//reserve space for BYTEs
typedef uint8_t BYTE;
BYTE *buffer = malloc(sizeof(BYTE) * 512)
buffer[0] ==0xff;

int main(int argc, char *argv[])
{
    int x = 0xf9;
    if(x >= 0xe0 && x <= 0xef)
    {
        printf("the number is within the range 0xe0 and 0xef\n");
    }
    else
    {
        printf("the statement is outside the range\n");
    }
}