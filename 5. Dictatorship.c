  #include <stdio.h>
#include <string.h>

#define MAX_STATEMENTS 10
#define MAX_INPUT_LENGTH 100

int getUserChoice();
void enforceRules(char statements[][MAX_INPUT_LENGTH], int num_statements);
void createStatements(char statements[][MAX_INPUT_LENGTH]);
void resetGame(); // Function to reset game state

// Global variables
int num_statements;
char statements[MAX_STATEMENTS][MAX_INPUT_LENGTH];
int warnings = 0; // Track number of warnings

int main() {
  // Create the statements using the function
  createStatements(statements);
  num_statements = 5; // Get statement count automatically

  // Ask user to support or not
  int initialChoice = getUserChoice("Do you support our party? (1 - Yes, 2 - No): ");

  if (initialChoice == 1) {
    enforceRules(statements, num_statements);
  } else {
    printf("Giving you another chance ! Be in your limits. \n");
    enforceRules(statements, num_statements);
  }

  if (warnings == 0) {
    printf("Congratulations! from now you are a true patriot \n");
  }

  return 0;
}

void createStatements(char statements[][MAX_INPUT_LENGTH]) {
  strcpy(statements[0], "1. You have to follow all the acts that we are implementing on this country.\n");
  strcpy(statements[1], "2. You can't raise voice against us.\n");
  strcpy(statements[2], "3. You can't stand against us in elections freely.\n");
  strcpy(statements[3], "4. We'll make you blind as you have to worship us.\n");
  strcpy(statements[4], "5. If anyone raises their voice against us, you have to call them anti-national.\n");
  strcpy(statements[5], "6. We will also create nepotism in this country and you have to blindly accept it.\n");
  // Add more statements as needed (up to MAX_STATEMENTS)
}

int getUserChoice(const char* message) {
  int choice;
  printf("%s", message);
  scanf("%d", &choice);

  if (choice != 1 && choice != 2) {
    printf("Invalid choice. Please enter 1 for Yes or 2 for No.\n");
    choice = getUserChoice(message); // Recursively call to get valid input
  }

  return choice;
}

void enforceRules(char statements[][MAX_INPUT_LENGTH], int num_statements) {
  for (int i = 0; i < num_statements; i++) {
    int choice = getUserChoice(statements[i]);

    if (choice == 1) {
      printf("Thank you for your agreement.\n");
    } else if (choice == 2) {
      warnings++;
      if (warnings == 1) {
        printf("Warning: Disagreement is not tolerated. You will be jailed.\n");
      } else if (warnings == 2) {
        printf("You have disobeyed the rules multiple times and are now in jail!\n");
        printf("Do you want to join our party to be free? (yes/no): ");
        int joinChoice = getUserChoice(""); // Empty string for generic prompt
        if (joinChoice == 1) {
          printf("Welcome to the our party! The game has been reset.\n");
          resetGame();
        } else {
          printf("You stay in jail! You lose the game.\n");
          break; // Exit the loop after user refuses to join
        }
      } else {
        printf("Invalid choice. Please enter 1 for Yes or 2 for No.\n");
      }
    }
  }
}

void resetGame() {
  warnings = 0; // Reset warnings
  printf("The game has been reset. You are back at the beginning.\n\n");
}
