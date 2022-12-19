#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool HasValidArgumentAmount(int argc);
void MakeStringLower(string str);
bool IsValidKey(string key);
string GetPlainText(void);
void DisplayCipherText(string cipher, string str);

int main(int argc, string argv[])
{
    // Validate arguments
    if (!HasValidArgumentAmount(argc))
    {
        return 1;
    }

    // Validate key
    string key = argv[1];
    MakeStringLower(key); //Program expects key to be lowercase.
    if (!IsValidKey(key))
    {
        return 1;
    }

    //Get text and cipher
    string plaintext = GetPlainText();
    DisplayCipherText(key, plaintext);

    return 0;
}

bool HasValidArgumentAmount(int argc)
{
    if (argc != 2)
    {
        printf("Invalid arugment amount.  Arguments are %i\n", argc);

        return false;
    }
    else
    {
        return true;
    }
}

void MakeStringLower(string str)
{
    for (int i = 0, l = strlen(str); i < l; i++)
    {
        str[i] = tolower(str[i]);
    }
}

//Key must be lower case
bool IsValidKey(string key)
{
    int keylength = strlen(key);

    //Must have 26 characters
    if (keylength != 26)
    {
        printf("Invalid key.  Key length %lu.\n", strlen(key));

        return false;
    }

    int spots[26] = { 0 };
    for (int i = 0; i < keylength; i++)
    {
        //Each letter must be lower case
        if (key[i] < 97 || key[i] > 122)
        {
            printf("Invalid key. Invalid character %c in key.\n", key[i]);

            return false;
        }

        //Can't have repeated letters
        if (spots[key[i] - 97] != 0)
        {
            printf("Invalid key. Character %c used more than once.  Positions: %i, %i.\n", key[i], spots[key[i] - 97], i + 1);

            return false;
        }
        else
        {
            //We store the spot for error reporting.
            spots[key[i] - 97] = i + 1;
        }
    }

    return true;
}

string GetPlainText(void)
{
    return get_string("plaintext:");
}

void DisplayCipherText(string cipher, string str)
{
    for (int i = 0, l = strlen(str); i < l; i++)
    {
        //Lower case
        if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] = cipher[str[i] - 97];
        }
        //Uppder case
        else if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] = cipher[str[i] - 65] - 32;
        }
    }

    printf("ciphertext: %s\n", str);
}
