#include <stdio.h>
#include <math.h> // for sqrt and pow functions
#include <stdlib.h> // for rand function (random number generation)
#include <string.h> // for strcmp function
 
// Function to calculate ball trajectory and determine if it hits the wicket (with margin of error)
int simulateBallTracking(int ballX, int ballY, int speedX, int speedY, int wicketX, int wicketY, char* pitchCondition) {
  // Time of flight (assuming constant gravity)
  double time = -2.0 * ballY / speedY;
 
  // Final X and Y positions based on initial position, speed, and time
  int finalX = ballX + (speedX * time);
  int finalY = ballY + (speedY * time) - (0.5 * 9.81 * pow(time, 2)); // Account for gravity
 
  // Margin of error for simulating umpire's call (adjust value as needed)
  int margin = 5;
 
  // Combine pitch impact simulation with ball tracking (modify logic as needed)
  if (strcmp(pitchCondition, "bumpy") == 0) {
    finalY += rand() % 10 - 5; // Random deviation between -5 and 5 for bumpy pitch
  } else if (strcmp(pitchCondition, "swing") == 0) {
    finalX += rand() % 3; // Slight lateral deviation for swing (adjust range and direction)
  } else if (strcmp(pitchCondition, "turning") == 0) {
    finalY += rand() % 5; // Additional downward deviation for turning pitch (adjust range)
  }
 
  // Check if ball hits the wicket with margin of error
  return (finalX >= wicketX - margin && finalY <= wicketY + margin);
}
 
// Function to simulate umpire's call (biased or not biased)
int umpiresCall(int isBiased) {
  // Simulate random chance for umpire's call (adjust bias weight as needed)
  return rand() % 100 < (isBiased ? 60 : 50); // 60% chance for out if biased, 50% otherwise
}
 
// Function to display DRS conditions based on decision
void displayDRSConditions(int hit, int call) {
  if (hit) {
    printf("The batsman is OUT! Ball tracking shows the ball would have hit the wicket.\n");
  } else {
    printf("The batsman is NOT OUT! Ball tracking shows the ball would have missed the wicket.\n");
  }
}
 
 
int main() {
  int ballX, ballY, speedX, speedY, wicketX, wicketY, isBiased;
  char pitchCondition[20]; // Allow space for user input
 
  // Get user input for ball position and speed
  printf("Enter ball's initial X position: ");
  scanf("%d", &ballX);
  printf("Enter ball's initial Y position: ");
  scanf("%d", &ballY);
  printf("Enter ball's speed in X direction: ");
  scanf("%d", &speedX);
  printf("Enter ball's speed in Y direction (upward positive): ");
  scanf("%d", &speedY);
 
  // Get user input for wicket position
  printf("Enter wicket's X position: ");
  scanf("%d", &wicketX);
  printf("Enter wicket's Y position (top of wicket): ");
  scanf("%d", &wicketY);
 
  // Get user input for umpire bias
  printf("Is the umpire biased (0 - Not Biased, 1 - Biased): ");
  scanf("%d", &isBiased);
 
  // Get user input for pitch condition
  printf("Enter pitch condition (flat, bumpy, swing, turning): ");
  scanf("%s", pitchCondition);
   // Simulate ball tracking and umpire's call
  int hit = simulateBallTracking(ballX, ballY, speedX, speedY, wicketX, wicketY, pitchCondition);
  int call = umpiresCall(isBiased);
 
  // Display results based on simulated tracking and umpire's call
  displayDRSConditions(hit, call);
 
  return 0;
}
 

