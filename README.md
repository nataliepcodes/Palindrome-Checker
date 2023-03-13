# PALINDROME CHECKER

This program checks whether a given string is a palindrome.

## What is a Palindrome

A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward.\
Examples:

```
words --> racecar, rotor, madam, kayak, kinnikinnik, wow
numbers --> 91019, 2112, 0550, 8125218
sentence --> Was it a car or a cat I saw?
```

## How the program works

1. The program prompts the user to enter a string.
   fgets() function is used to take the user's input from stidin.

```
printf("Enter a string: ");
fgets(string, 100, stdin);
```

2. The the program removes all non-alphanumeric characters from the string and converts the string to lowercase - isalnum(), to_lower_case()\
   The implementation is shown in the below code example, where isalnum() function is used to check whether a character is alphanumeric.\
   The isalnum() function is typically implemented as a macro in C. This implementation defines the isalnum() macro to evaluate to true if the input character is alphabetic or numeric, as determined by the isalpha() and isdigit() functions from the ctype.h library.\
   The isalnum() macro is generally more efficient than calling both isalpha() and isdigit() separately, since the macro evaluates both conditions in a single comparison. Also, the isalnum() macro is guaranteed to be implemented as efficiently as possible by the compiler, since it is defined as a macro rather than a function call.

```
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
```

If the character is alphanumeric then the characters are changed to lower case with the help of the own-build function, called to_lower_case().\
tolower() function from a standard C library could have also been used here. It is declared in the ctype.h header file.\
However, for the purposes of practicing how this function is build, to_lower_case() function was implemented. Which follows the same concept as tolower() - converting uppercase characters to lowercase characters.

```
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
```

3. Check for palindrome\
   The check for palindrom is performed by initialize two variables i and j to the beginning and end of the string, respectively.\
   Then the while loop is used to loop over a string while i < j.\
   If the i and j characters are the same then i is incremented and j is decremented.\
   If the characters at indices i and j are not the same, the string is not a palindrome. The flag variable is implemented to flag this up by setting the flag to 1.\
   Once the loop completes, if statement checks if the flag was equal to 1, thus printing a statement that the string is not a palindrome.\
   If the loop completes without finding a mismatch, the statement is printed that the string is a palindrome.

```
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
```

# Programming concepts used in this project

Loops: single for loops, while loops\
Strings: string copy, string length\
Read from standard input\
flags\
man ascii\
fgets(), isalnum()\
tolower() implementation\
Readme file
