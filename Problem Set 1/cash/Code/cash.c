#include <stdio.h>
#include <math.h>
#include <cs50.h>

int calc(int *, int); //function to calculate and return the counter

int main(void)
{
    float dollars;
    int count = 0, rem_coin; // count to track how many coins used. rem_coin to track remainig change owed
    do
    {
        dollars = get_float("Change owed: "); //prompts users to input a positive value
    }
    while (dollars < 0);
    int cents = round(dollars * 100); // converts dollers to cents and rounds it off as well for easier computaton
    rem_coin = cents; //To not lose the original value
    if (rem_coin >= 25) //Quarters
    {
        count += calc(&rem_coin, 25);
    }
    if (rem_coin >= 10 && rem_coin < 25) //Dimes
    {
        count += calc(&rem_coin, 10);
    }
    if (rem_coin >= 5 && rem_coin < 10) //Nickels
    {
        count += calc(&rem_coin, 5);
    }
    if (rem_coin >= 1 && rem_coin < 5) //Pennies
    {
        count += calc(&rem_coin, 1);
    }

    printf("%d\n", count); // Print the number of coins required
    return 0;
}

int calc(int *coins, int change)
{
    int count = 0;
    do
    {
        *coins = *coins - change;
        count++;
    }
    while (*coins >= change); // decrementation condition

    return count; //returns the counter
}