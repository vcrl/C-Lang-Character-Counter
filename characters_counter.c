#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Initialization
    int get_word_count(char user_input[]);
    int check_input(char user_input[]);

    char user_input[100];

    // Prompt user :
    printf("Please type a word: ");
    scanf("%s", user_input);
    
    // If there is an input :
    if (user_input)
    {
        // If not int, and letters in alphabet :
        if (check_input(user_input) == 0)
        {
            printf("You typed: %s \n", user_input);
            printf("Spelled: ");
            printf("\nThis word has %d characters. \n", get_word_count(user_input));
        }  
    } 
}

int get_word_count(char user_input[])
{
    int count = 0;
    for (count = 0; count < strlen(user_input); count++)
    {
        printf("%c", user_input[count]);
        if (count != strlen(user_input) - 1)
        {
            printf("-");
        }
        
    }
    return count;
}

int check_input(char user_input[])
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; //éàèếầôûöüëäếâ
    int foundLetters = 0;

    // When this loop is increased, the nested loop is reset (1):
    for (int count = 0; count < strlen(user_input); count++)
    {
        // (1) Is reset when parent loop is increased, meaning if first loop = 0, this loop will run through all its condition (52) :
        for (int c = 0; c < strlen(alphabet); c++)
        {
            // Loop through alphabet[]. If a match is found for character in input, add 1 to foundLetters. Else do nothing.
            if (user_input[count] == alphabet[c])
            {
                foundLetters+=1;
            }
        }
    }
    
    // Is foundLetters is the same size as characters in input (meaning all characters are in the alphabet) : continue/
    // BUT HERE, we're checking if it's inferior :
    if (foundLetters < strlen(user_input))
    {
        printf("Error 1: Incorrect characters detected.\n");
        return 1;
    }

    // If every condition is ok, return 0 :
    return 0;
}