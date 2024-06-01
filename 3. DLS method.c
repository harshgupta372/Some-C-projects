#include <stdio.h>
 
int main() {
// Input variables
int overs_completed_team1;
int runs_scored_team1;
int overs_remaining;
 
// Simplified par score calculation (replace with your formula)
int average_run_rate = 5; // Example value, adjust as needed
int par_score = overs_completed_team1 * average_run_rate;
 
// Get user input
printf("Enter overs completed by team 1: ");
scanf("%d", &overs_completed_team1);
printf("Enter runs scored by team 1: ");
scanf("%d", &runs_scored_team1);
printf("Enter overs remaining in the match: ");
scanf("%d", &overs_remaining);
 
// Resource comparison (replace with your logic)
int resource_difference = runs_scored_team1 - par_score;
 
// Target adjustment (replace with your logic)
int adjustment_factor = 2; // Example value, adjust as needed
int revised_target = par_score + (resource_difference * adjustment_factor) / overs_remaining;
 
// Output
printf("Revised target score for team 2: %d\n", revised_target);
 
return 0;
}
