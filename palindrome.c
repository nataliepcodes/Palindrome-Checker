#include <stdio.h>
#include <string.h> // for strlen()
#include <stdlib.h> // for malloc()
#include <ctype.h> // for isalnum()


// Change a character from uppercase to lowercase
char to_lower_case(char character)
{
    // If a character is between ASCII 65-A and ASCII 90-Z
    if (character >= 65  && character <= 90)
    {
        // Convert it to a lower case
        character = character + 32;
    }
    return character;
}

// Remove non-alphanumeric characters from string, and change string to lower case
char* convert(char* string)
{
    char* new_string = (char*)malloc(sizeof(char));
    int j = 0;

    // Remove non-alphanumeric characters and change to lower case
    for (int i = 0; i < strlen(string); i++)
    {
        // isalnum() is a function from the ctype.h library that checks whether a character is alphanumeric
        if (isalnum(string[i]))
        {
            // Convert the string to lowercase / tolower() is another option to achieve this
            // Copy alphanumeric characters in lowercase to a new_string
            new_string[j++] = to_lower_case(string[i]);
        }
    }
    // Add a null terminator to a new_string
    new_string[j] = '\0';
    
    return new_string;
}

void check_palindrome(char* string)
{
    // Declare i and j variables, i as the start of the string, j as the end of the string
    int i = 0;
    int j = strlen(string) - 1;
    int flag = 0;

    // Loop over the string while i is less than j
    while (i < j)
    {
        if (string[i] == string[j])
        {
            i++;
            j--;
        }
        else
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("The string >%s< is not a palindrome!\n", string);
    }
    else
    {
        printf("The string >%s< is a palindrome!\n", string);
    }
}


int main()
{
    // Create a string variable
    char string[100];
    
    // Prompt user to enter a string
    printf("Enter a string: ");
    fgets(string, 100, stdin);

    // Create a formatted string variable
    char formatted_string[100];
    // Copy the converted string to the formatted string variable
    strcpy(formatted_string, convert(string));

    // Call check_palindrome function with the formatted string as an argument
    check_palindrome(formatted_string);

    return 0;
}