#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // asks user name
    string userName = get_string("What's your name?\n");

    // prints asked user input
    printf("Hello, %s!\n", userName);
}