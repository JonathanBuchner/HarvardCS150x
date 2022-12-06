#include <cs50.h>
#include <stdio.h>

void validateCard(long num);
bool validateCardChecksum(long num);
bool isAmericanExpress(long num);
bool isMasterCard(long num);
bool isVisa(long num);

const string INVALID = "INVALID";
const string AMEX = "AMEX";
const string MASTERCARD = "MASTERCARD";
const string VISA = "VISA";

int main(void)
{
    long ccUserInput = 0;

    do
    {
        ccUserInput = get_long("Provide a valid credit card number: ");
    }
    while (1 > ccUserInput);

    validateCard(ccUserInput);
}

void validateCard(long num)
{
    string cardCheck = INVALID;

    if (validateCardChecksum(num))
    {
        if (isAmericanExpress(num))
        {
            cardCheck = AMEX;
        }
        else if (isMasterCard(num))
        {
            cardCheck = MASTERCARD;
        }
        else if (isVisa(num))
        {
            cardCheck = VISA;
        }
    }

    printf("%s\n", cardCheck);
}

//Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
//Add the sum to the sum of the digits that weren’t multiplied by 2.
//If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
//Checksum invented by Hans Peter Luhn of IBM.
bool validateCardChecksum(long num)
{

    long evenNum = num / 10;
    int total = 0;

    //Add product digits of even digit numbers multiplied by 2
    while (evenNum > 0)
    {
        int ones = (evenNum % 10) * 2;

        while (ones > 0)
        {
            total += ones % 10;
            ones /= 10;
        }

        evenNum /= 100;
    }

    //Add odd digits
    while (num > 0)
    {
        total += num % 10;

        num /= 100;
    }

    return total % 10 == 0;
}

// //American Express uses 15-digit numbers
// //All American Express numbers start with 34 or 37
bool isAmericanExpress(long num)
{
    num = num / 10000000000000;

    if (num == 34 || num == 37)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// //MasterCard uses 16-digit numbers
// //MasterCard numbers start with 51, 52, 53, 54, or 55
bool isMasterCard(long num)
{
    num = num / 100000000000000;

    if (num > 50 && num < 56)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// //Visa uses 13- and 16-digit numbers.
// //Visa numbers start with 4.
bool isVisa(long num)
{
    if (num / 1000000000000000 == 4)
    {
        return true;
    }

    if (num / 1000000000000 == 4)
    {
        return true;
    }

    return false;
}
