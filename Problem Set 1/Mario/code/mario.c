#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h, i, j, count = 0 ;
    do
    {
        h = get_int("Height: ");
    }
    while ((h < 1) || (h > 8));
    for (i = 0 ; i < h ; i++) //first iteration denoting rows
    {
        for (j = 0 ; j < h ; j++) //second iteration representing the columns of the rows
        {
            if ((j + i) < h - 1) //the condition for printing either hash or space
            {
                printf(" "); //prints space
            }
            else
            {
                printf("#"); //prints hash
                count++;
            }
        }
        printf("  ");
        while (count != 0)
        {
            printf("#");
            count--;
        }
        printf("\n"); //print newline
    }

}
