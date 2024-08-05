#include <stdio.h>
#include <cs50.h>

void printBlockLine(int blockQuantity, int pyramidHeight);

int main(void)
{
    int height = get_int("How tall the pyramid should be?\n");

    if (height >= 1 && height <= 8)
    {
        for (int blockQuantity = 1; blockQuantity <= height; blockQuantity++)
        {
            printBlockLine(blockQuantity, height);
        }
    }
    else
    {
        main();
    }
}

void printBlockLine(int blockQuantity, int height)
{
    int whitespaces = height - blockQuantity;

    for (int i = 0; i < whitespaces; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < blockQuantity; i++)
    {
        printf("#");
    }

    printf("  ");

    for (int i = 0; i < blockQuantity; i++)
    {
        printf("#");
    }

    printf("\n");
}