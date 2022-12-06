#include <cs50.h>
#include <stdio.h>

void createTower(int num);

int main(void)
{
    int num = 0;
    int tooHigh = 9; //Max height if tower

    //Ask user for height
    do
    {
        num = get_int("Please provide a positive number less than a 9: ");
    }
    while (num < 1 || num >= tooHigh);

    createTower(num);
}

void createTower(int num)
{
    //Loop through row
    for (int i = 1; i <= num; ++i)
    {
        //Loop through first part of column.  Up angle.
        int j = num;
        while (j > 0)
        {
            if (j - i > 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

            --j;
        }
        //Add space
        printf("  ");

        //Loop through second half of column. Down angle.
        j = 1;
        while (j <= i)
        {
            printf("#");

            ++j;
        }

        printf("\n");
    }
}