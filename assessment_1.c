#include <stdio.h>
#include <string.h>
#include <ctype.h>
void reverse_string(char str[])
{
  int start = 0, end = strlen(str) - 1;
  char temp;

  printf("Reversed string: %s\n", str);
}
void concatenate_strings(char str1[], char str2[])
{
  strcat(str1, str2);
  printf("Concatenated string: %s\n", str1);
}
int is_palindrome(char str[])
{
  int start = 0, end = strlen(str) - 1;
  while (start < end)
  {
    if (str[start] != str[end])
    {
      return 0;
    }
    start++;
    end--;
  }
  return 1;
}
void copy_string(char source[], char destination[])
{
  strcpy(destination, source);
  printf("Copied string: %s\n", destination);
}
void string_length(char str[])
{
  printf("Length of the string: %lu\n", strlen(str));
}
void char_frequency(char str[], char ch)
{
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == ch)
    {
      count++;
    }
  }
  printf("Frequency of '%c': %d\n", ch, count);
}
void count_vowels_consonants(char str[])
{
  int vowels = 0, consonants = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (isalpha(str[i]))
    {
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
          str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
      {
        vowels++;
      }
      else
      {
        consonants++;
      }
    }
  }
  printf("Number of vowels: %d\n", vowels);
  printf("Number of consonants: %d\n", consonants);
}
void count_spaces_digits(char str[])
{
  int spaces = 0, digits = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == ' ')
    {
      spaces++;
    }
    else if (isdigit(str[i]))
    {
      digits++;
    }
  }
  printf("Number of blank spaces: %d\n", spaces);
  printf("Number of digits: %d\n", digits);
}
void display_menu()
{
  printf("\nChoose an operation from the following:\n");
  printf("1. Reverse the string\n");
  printf("2. Concatenate two strings\n");
  printf("3. Check if the string is a palindrome\n");
  printf("4. Copy the string\n");
  printf("5. Find the length of the string\n");
  printf("6. Find the frequency of a character in the string\n");
  printf("7. Find the number of vowels and consonants\n");
  printf("8. Find the number of blank spaces and digits\n");
  printf("9. Exit\n");
}
int main()
{
  char str1[100], str2[100], copied_str[100];
  int choice, continue_program;
  char ch;
  printf("Enter the first string: ");
  fgets(str1, sizeof(str1), stdin);
  str1[strcspn(str1, "\n")] = '\0';
  do
  {
    display_menu();
    printf("Enter your choice (1-9): ");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
      reverse_string(str1);
      break;
    case 2:
      printf("Enter the second string: ");
      fgets(str2, sizeof(str2), stdin);
      str2[strcspn(str2, "\n")] = '\0';
      concatenate_strings(str1, str2);
      break;
    case 3:
      if (is_palindrome(str1))
      {
        printf("The string is a palindrome.\n");
      }
      else
      {
        printf("The string is not a palindrome.\n");
      }
      break;
    case 4:
      copy_string(str1, copied_str);
      break;
    case 5:
      string_length(str1);
      break;
    case 6:
      printf("Enter the character to find its frequency: ");
      scanf("%c", &ch);
      char_frequency(str1, ch);
      break;
    case 7:
      count_vowels_consonants(str1);
      break;
    case 8:
      count_spaces_digits(str1);
      break;
    case 9:
      printf("Exiting the program...\n");
      return 0;
    default:
      printf("Invalid choice, please select a valid option from the menu.\n");
      break;
    }
    printf("\nDo you want to continue? (1 for Yes, 0 for No): ");
    scanf("%d", &continue_program);
  } while (continue_program == 1);
  printf("Goodbye!\n");
  return 0;
}
