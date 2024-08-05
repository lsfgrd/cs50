#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validate_key(string key);

int main(int argc, char **argv)
{
    if (!argv[1] || argv[2])
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    string key = argv[1];

    if (strlen(key) < 26 || strlen(key) > 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (!validate_key(key))
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    int plaintext_length = strlen(plaintext);

    for (int i = 0; i < plaintext_length; i++)
    {
        char curr_char = plaintext[i];

        if (isalpha(curr_char))
        {
            if (isupper(curr_char))
            {
                int alphabet_pos = curr_char - 'A';
                plaintext[i] = toupper(key[alphabet_pos]);
            }
            else
            {
                int alphabet_pos = curr_char - 'a';
                plaintext[i] = tolower(key[alphabet_pos]);
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}

bool validate_key(string key)
{
    int key_length = strlen(key);

    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("The key must contain only letters.\n");
            return false;
        }

        string new_str = malloc(26);
        strcpy(new_str, key);
        new_str[i] = ' ';

        string res = strstr(new_str, (char[2]){key[i], '\0'});

        if (res)
        {
            printf("The key must not contain duplicated letters (%c was duplicated).\n", key[i]);
            return false;
        }
    }

    return true;
}
