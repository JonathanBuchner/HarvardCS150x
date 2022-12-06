#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Ask for name
    string name = get_string("What's your name? ");

    //Print hello message
    printf("hello, %s\n", name);
}
