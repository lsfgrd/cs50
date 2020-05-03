#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

bool checkSum(string cardString);
string getCardBrand(string cardString);

bool isEven(long number);
bool isOdd(long number);

int charAsInt(char achar);
string longAsString(long along, int maxlength);

int main(void)
{
    long cardNumber = get_long("Please insert the card number:\n");

    // in this algorithm we are going to work with strings
    string cardString = longAsString(cardNumber, 20);

    if (checkSum(cardString) && strlen(cardString) > 13)
    {
        printf("%s", getCardBrand(cardString));
    }
    else
    {
        printf("INVALID\n");
    }
}

bool checkSum(string cardString)
{
    long numberOfDigits = strlen(cardString);
    long doubledSum = 0, normalSum = 0;

    for (int digitIndex = numberOfDigits - 1; digitIndex >= 0; digitIndex--)
    {
        int currentDigit = charAsInt(cardString[digitIndex]);

        // checks if we should multiply the current digit by 2 based on the total number of digits the card has
        // if the total is even, we should double the evens. if it's odd, we should double the odds.
        bool shouldDouble = isEven(numberOfDigits) ? isEven(digitIndex) : isOdd(digitIndex);

        if (shouldDouble)
        {
            int doubled = currentDigit * 2;
            string product = longAsString(doubled, 2); // transforms the product in a string so we can get it's length and separate digits later

            if (strlen(product) == 2) // if the product has two digits, we must add them separately
            {
                doubledSum += (charAsInt(product[0]) + charAsInt(product[1]));
            }
            else
            {
                doubledSum += doubled;
            }
        }
        else
        {
            normalSum += currentDigit;
        }
    }

    string finalSum = longAsString(doubledSum + normalSum, 5);
    return finalSum[1] == '0'; // true if the last digit is zero
}


string getCardBrand(string cardString)
{
    if (cardString[0] == '3') // checks if could be AMEX
    {
        if (cardString[1] == '4' || cardString[1] == '7')
        {
            return "AMEX\n";
        }
    }

    if (cardString[0] == '5') // checks if could be MASTERCARD
    {
        if (cardString[1] == '1' || cardString[1] == '2' || cardString[1] == '3' || cardString[1] == '4' || cardString[1] == '5')
        {
            return "MASTERCARD\n";
        }
    }

    if (cardString[0] == '4') // checks if could be VISA
    {
        return "VISA\n";
    }

    return "INVALID\n";
}



/**
 *  HELPER FUNCTIONS
 */
int charAsInt(char achar)
{
    return achar - '0';
}

string longAsString(long along, int maxlength)
{
    char *mystr = malloc(maxlength * sizeof(char *));
    sprintf(mystr, "%ld", along);
    return mystr;
}

bool isEven(long number)
{
    return number % 2 == 0;
}

bool isOdd(long number)
{
    return number % 2 != 0;
}
