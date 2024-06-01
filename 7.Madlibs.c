#include <stdio.h>
#include <string.h>

int main() {
  char noun1[50], noun2[50], verb1[50], adjective1[50], adjective2[50];

  // Prompt user for words
  printf("Welcome to Mad Libs!\n");
  printf("Enter a noun: ");
  fgets(noun1, sizeof(noun1), stdin);
  noun1[strcspn(noun1, "\n")] = '\0';

  printf("Enter another noun: ");
  fgets(noun2, sizeof(noun2), stdin);
  noun2[strcspn(noun2, "\n")] = '\0';

  printf("Enter a verb: ");
  fgets(verb1, sizeof(verb1), stdin);
  verb1[strcspn(verb1, "\n")] = '\0';

  printf("Enter an adjective: ");
  fgets(adjective1, sizeof(adjective1), stdin);
  adjective1[strcspn(adjective1, "\n")] = '\0';

  printf("Enter another adjective: ");
  fgets(adjective2, sizeof(adjective2), stdin);
  adjective2[strcspn(adjective2, "\n")] = '\0';

  // Print the Mad Lib story
  printf("\nHere's your Mad Lib story:\n");
  printf("Once upon a time, there was a(n) %s named %s. They loved to %s %s in their %s pajamas.\n",
         adjective1, noun1, verb1, adjective2, noun2);

  return 0;
}
