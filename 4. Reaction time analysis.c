#include <math.h>
#include <stdio.h>
 
#define DISTANCE_BALL_BOWLER 22.0
#define BAT_SWING_TIME 0.5
#define DISTANCE_TO_BOUNDARY 90.0
#define GRAVITY 9.81
#define MIN_LAUNCH_ANGLE_SIX 25.0
 
float estimateBatSwingAngle(float ball_speed) {}
 
void analyzeDismissal(char ball_location, char batsman_action,
                      float ball_speed) {
  printf("Ball location: ");
  switch (ball_location) {
  case 'w':
    printf("Wide\n");
    break;
  case 'o':
    printf("Off-stump\n");
    break;
  case 'l':
    printf("Leg-stump\n");
    break;
  default:
    printf("Invalid ball location\n");
  }
 
  printf("Batsman's action: ");
  switch (batsman_action) {
  case 's':
    printf("Played a shot\n");
    break;
  case 'm':
    printf("Missed the ball\n");
    break;
  case 'p':
    printf("Played onto body\n");
    break;
  default:
    printf("Invalid batsman action\n");
  }
 
  printf("Dismissal scenarios: ");
  if (ball_location == 'w') {
    printf("Not Out (Wide)\n");
  } else if (ball_location == 'l' && batsman_action != 's') {
    printf("Not Out (Leg Bye)\n");
  } else {
    if (ball_speed > 30 && (batsman_action == 'm' ||
                            (batsman_action == 'p' && ball_location == 'o'))) {
      printf("LBW shout (depending on umpire's call)\n");
    }
    if (batsman_action == 's') {
      printf("Caught (if fielder catches the ball)\n");
    }
  }
  printf("Run Out (possible if batsman leaves the crease)\n");
}
 
int main() {
  float ball_speed;
  char ball_location, batsman_action;
 
  printf("Enter ball speed (m/s): ");
  scanf("%f", &ball_speed);
 
  printf("Enter ball location (w - Wide, o - Off-stump, l - Leg-stump): ");
  scanf(" %c", &ball_location);
 
  printf("Enter batsman's action (s - Played a shot, m - Missed, p - Played "
         "onto body): ");
  scanf(" %c", &batsman_action);
 
  float time_to_batsman = DISTANCE_BALL_BOWLER / ball_speed;
  float ideal_reaction_time = time_to_batsman - BAT_SWING_TIME;
 
  if (ideal_reaction_time < 0) {
    printf("Error: Ball speed too high for human reaction time.\n");
  } else {
    printf("Ideal reaction time for this ball speed: %.2f seconds\n",
           ideal_reaction_time);
 
    float swing_angle = estimateBatSwingAngle(ball_speed);
    printf("Estimated bat swing angle for a six: %.2f degrees\n", swing_angle);
 
    analyzeDismissal(ball_location, batsman_action, ball_speed);
  }
 
  return 0;
}

