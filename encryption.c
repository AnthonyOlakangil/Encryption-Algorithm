#include "cs50.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        // Checking for invalid chars

        bool all_letters;

        for (int i = 0, length = strlen(argv[1]); i < length; i++)
        {
            if ((argv[1][i] >= 'A' && argv[1][i] <= 'Z') || (argv[1][i] >= 'a' && argv[1][i] <= 'z'))
            {
                all_letters = true;
            }
            else
            {
                all_letters = false;
                break;
            }
        }

        // Checking for duplicate chars in key

        for (int i = 0, length = strlen(argv[1]); i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Key must consist of unique characters\n");
                    return 1;
                }
            }
        }

        if (all_letters)
        {
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");

            for (int i = 0, length = strlen(plaintext); i < length; i++)
            {
                if (isupper(plaintext[i]))
                {
                    printf("%c", toupper(argv[1][plaintext[i] - 'A'])); // Printing ith char of key based on index position in
                                                                        // ordered alphabet from plaintext
                }
                else if (islower(plaintext[i]))
                {
                    printf("%c", tolower(argv[1][plaintext[i] - 'a']));
                }
                else
                {
                    printf("%c", plaintext[i]); // Keeping special chars and punctuation the same
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Key must consist of only letters\n");
            return 1;
        }
    }
}

// YTNSHKVEFXRBAUQZCLWDMIPGJO
// VCHPRZGJNTLSKFBDQWAXEUYMOI
