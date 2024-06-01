#include <stdio.h>
#include <string.h>
 
#define MAX_PLAYERS_PER_TEAM 11
#define MAX_TOTAL_PLAYERS (MAX_PLAYERS_PER_TEAM * 2) // Total players (KKR + RCB)
 
// Player type enumeration
typedef enum { BATTER, BOWLER, ALL_ROUNDER } PlayerType;
 
// Structure to represent a player
struct Player {
    char name[50];
    PlayerType type;
    int runs;
    int wickets;
    int points; // Total fantasy points (calculated)
};
 
// Sample player lists for KKR and RCB (replace with real data if needed)
struct Player allPlayers[MAX_TOTAL_PLAYERS] = {
    // KKR players
    {"Shreyas Iyer", BATTER}, {"Nitish Rana", BATTER}, {"Andre Russell", ALL_ROUNDER}, {"Pat Cummins", BOWLER},
    {"Varun Chakravarthy", BOWLER}, {"Kamlesh Nagarkoti", BOWLER}, {"Dinesh Karthik (wk)", BATTER},
    {"Venkatesh Iyer", ALL_ROUNDER}, {"Sunil Narine", ALL_ROUNDER}, {"Shivam Mavi", BOWLER}, {"Prasidh Krishna", BOWLER},
    // RCB players
    {"Faf du Plessis", BATTER}, {"Virat Kohli (c)", BATTER}, {"Glenn Maxwell", ALL_ROUNDER}, {"Rajat Patidar", BATTER},
    {"Dinesh Karthik (wk)", BATTER}, {"Shahbaz Ahmed", ALL_ROUNDER}, {"Wanindu Hasaranga", BOWLER},
    {"Mohammed Siraj", BOWLER}, {"Harshal Patel", BOWLER}, {"Akash Deep", BOWLER}, {"Navdeep Saini", BOWLER}
};
 
// Function to calculate fantasy points based on scoring system
void calculatePoints(struct Player* player) {
    player->points = player->runs + (player->wickets * 15);
}
 
// Function to sort players by points (descending order)
void sortPlayersByPoints(struct Player players[], int n) {
    // Implement sorting algorithm (e.g., Bubble Sort, Selection Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (players[j].points < players[j + 1].points) {
                struct Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
}
 
int main() {
    // Get user input for fantasy league scoring system (optional)
    // You can prompt the user to define points for runs and wickets
    // (e.g., 1 point per run, 15 points per wicket)
 
    // Player data input loop (shows player names)
    for (int i = 0; i < MAX_TOTAL_PLAYERS; i++) {
        printf("\nPlayer %d: %s (%s)\n", i + 1, allPlayers[i].name,
               allPlayers[i].type == BATTER ? "BATTER" :
               allPlayers[i].type == BOWLER ? "BOWLER" : "ALL-ROUNDER");
 
        printf("Runs: ");
        scanf("%d", &allPlayers[i].runs);
 
        if (allPlayers[i].type != BATTER) {
            printf("Wickets: ");
            scanf("%d", &allPlayers[i].wickets);
        }
    }
 
    // Calculate fantasy points for each player
    for (int i = 0; i < MAX_TOTAL_PLAYERS; i++) {
        calculatePoints(&allPlayers[i]);
    }
 
    // Sort players by points (descending order)
    sortPlayersByPoints(allPlayers, MAX_TOTAL_PLAYERS);
 
    // Display top 11 players (fantasy team) with points
    printf("\nYour Fantasy Team (Top 11 Players by Points):\n");
    for (int i = 0; i < 11; i++) {
        printf("%d. %s (Points: %d)\n", i + 1, allPlayers[i].name, allPlayers[i].points);
    }
 
    return 0;
}
