o#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    // variable declaration
    int count = 0;
    int sum = 0;
    long divisor = 10;
    char result[11];

    long card;
    do
    {
        // user card input
        card = get_long("Pls Enter you Credit Card Number: ");
    }
    while (card < 0);
    long check = card;

    //declaring card to another variable
    long workingcard = card;

    // last digit selection loop
    while (workingcard > 0)
    {
        // the declared working card modulo 10 gives the value of the last digit
        int lastDigit = workingcard % 10;
        // the sum of the last digit
        sum = sum + lastDigit;
        // deletes the last 2 digit to move to the next hundreds place
        workingcard = workingcard / 100;
    }

    // second to the last diget multiplied by 2
    workingcard = card / 10;
    while (workingcard > 0)
    {
        // get the last digit
        int lastDigit = workingcard % 10;
        //multiplying last digit by 2
        int twox = lastDigit * 2;
        //getting the sum of the two modulo ten and two divided by 10 in cases of two digit modulo
        sum = sum + (twox % 10) + (twox / 10);
        workingcard = workingcard / 100;
    }


    // if working card is not zero, working card is incremently divided by 10
    workingcard = card;
    while (workingcard != 0)
    {
        workingcard = workingcard / 10;
        count++;
    }

    //divisor loop for checking values
    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    //variable for first digit and first two digit number of the cards
    int first = card / divisor;
    int first_two = card / (divisor / 10);

    // checking of values


    if (sum % 10 == 0)
    {
        // to check for a valid visa credit card, the first digit MUST be 4 AND the number count can be 13 OR 16
        if (first == 4 && (count == 13 || count == 16))
        {
            strcpy(result, "VISA");
        }
        // if conditions above is false, the 2nd condition that would be valid for American Express credit card would be;
        // the first two digit would be 34 OR 37 AND the length of number is 15
        else if ((first_two == 34 || first_two == 37) && count == 15)
        {
            strcpy(result, "AMEX");
        }
        // for a valid Mastercard, the first two digits MUST be greater than 50 but less than 56 AND length is 16
        else if ((50 < first_two && first_two < 56) && count == 16)
        {
            strcpy(result, "MASTERCARD");
        }
        //if condition above fails, a string "INVALID" will be copied to serve as the value for result
        else
        {
            strcpy(result, "INVALID");
        }
    }
    //if the modulo of sum and 10 is not equal to 0, then it is invalid
    else
    {
        strcpy(result, "INVALID");
    }

    // after checking, print the result on screen.
    printf("%s\n", result);
}
