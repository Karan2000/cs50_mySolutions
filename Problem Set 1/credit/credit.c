#include <stdio.h>
#include <cs50.h>
#include <math.h>
bool luhns_algo(long, int *);
void validate(long, int);

int main(void)
{
    int count = 0;
    long credit_card_number; //for the credit card number
    do
    {
        credit_card_number = get_long("Number: "); //prompt for the user
    }
    while (credit_card_number < 0);

    if (luhns_algo(credit_card_number, &count) == true) //to check for validity with luhn's algorithm
    {
        validate(credit_card_number, count); // if valid ,check which card
    }
    else
    {
        printf("INVALID\n"); //if none of them works. This one only works if the tests fail the luhn's algorithm
    }
    return 0;
}

bool luhns_algo(long num, int *count) //luhn's algorithm
{
    int i = 0, k, sum = 0;
    *count = 0;
    while (num != 0)
    {
        //if the digit in odd position, add directly. Since the first position is denoted by '0' which is divisible by 2, odd positions will be divisible by 2
        if (i % 2 == 0)
        {
            k = num % 10;
            sum += k;
            num = num / 10;
            *count = *count + 1;
        }
        else // if the digit in even position
        {
            k = num % 10;
            sum += (2 * k) % 10 + ((2 * k) / 10);
            num = num / 10;
            *count = *count + 1;
        }
        i++;
    }
    if (sum % 10 == 0) // checks if the last digit is 0
    {
        return true;
    }
    else
    {
        return false;
    }
}

void validate(long num, int count) //validation
{
    int i, flag = 0;
    if (count != 13 && count != 15 && count != 16) // checks if number of digits is 13 or 15 or 16
    {
        printf("INVALID\n"); //if not, print invalid and set flag to 1
        flag = 1;
    }
    for (i = 0; i <= count && flag != 1 ; num = num / 10, i++)
    {
        if (num == 4) // VISA
        {
            printf("VISA\n");
            flag = 1;
        }
        else if (num == 34 || num == 37) //AMEX
        {
            printf("AMEX\n");
            flag = 1;
        }
        else if (num == 51 || num == 52 || num == 53 || num == 54 || num == 55) //MASTERCARD
        {
            printf("MASTERCARD\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("INVALID\n"); // if the number does not start with any of the above specified digits, then print invalid
    }
}