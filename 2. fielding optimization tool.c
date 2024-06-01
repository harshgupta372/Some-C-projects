#include <stdio.h>
#include <math.h>
 
#define DISTANCE_BALL_BOWLER 22.0
#define DISTANCE_TO_BOUNDARY 90.0
 
float estimateBallSpeed(char bowler_type, char delivery_type) {
   float base_speed = 25.0;
   float speed_adjustment = 0.0;
 
   switch (bowler_type) {
     case 'p':
       speed_adjustment = 5.0;
       break;
     case 's':
       speed_adjustment = -2.0;
       break;
     default:
       printf("Invalid bowler type. Using default speed.\n");
   }
 
   switch (delivery_type) {
     case 'y':
       speed_adjustment -= 2.0;
       break;
     case 'b':
       speed_adjustment += 1.0;
       break;
     default:
       printf("Invalid delivery type. Using base speed.\n");
   }
 
   return base_speed + speed_adjustment;
}
 
void suggestFieldingPositions(float ball_speed, char batsman_handedness) {
   float ball_travel_time = DISTANCE_BALL_BOWLER / ball_speed;
   float ideal_reaction_time = 0.5;
   float ball_flight_time = ball_travel_time + ideal_reaction_time;
 
   if (ball_speed > 30) {
     printf("Deep positions recommended for all fielders.\n");
   } else if (batsman_handedness == 'R') {
     printf("Move cover point slightly wider for a right-handed batsman.\n");
     printf("Consider placing a fielder at backward square leg for potential leg-side flicks.\n");
   } else {
     printf("Move cover point slightly closer for a left-handed batsman.\n");
     printf("Consider placing a fielder at third man for potential off-side drives.\n");
   }
 
   float ball_flight_distance = ball_speed * ball_flight_time;
   if (ball_flight_distance > DISTANCE_TO_BOUNDARY * 0.75) {
     printf("Consider placing a fielder at long-on or long-off depending on the shot direction.\n");
   } else {
     printf("Focus on fielding positions closer to the batsman for potential boundaries within the 30-yard circle.\n");
   }
}
 
void suggestPowerplayFielding(char batsman_handedness) {
   printf("Common fielding positions for both batsmen during powerplay:\n");
   printf("  - Bring in an extra fielder in the slips (to a maximum of 3).\n");
   printf("  - Place a fielder at backward point for potential cuts or drives.\n");
   printf("  - Have a fielder at deep square leg for flicks or pulls.\n");
   printf("  - Keep the wicketkeeper alert for potential stumpings.\n");
 
   if (batsman_handedness == 'R') {
     printf("  - Move the cover point slightly wider to cover for potential drives.\n");
     printf("  - Consider a fielder at third man for boundaries on the off-side.\n");
   } else {
     printf("  - Move the cover point slightly closer to trap leg-side flicks.\n");
     printf("  - Consider a fielder at fine leg for boundaries on the leg-side.\n");
   }
}
int main() {
  char bowler_type, batsman_handedness, delivery_type;
  float ball_speed;
  int over_number;
 
  printf("Enter over number (1-6 for powerplay, others for regular fielding): ");
  scanf("%d", &over_number);
 
  printf("Enter bowler type (p - Pace, s - Spin): ");
  scanf(" %c", &bowler_type);
 
  printf("Enter batsman handedness (R - Right, L - Left): ");
  scanf(" %c", &batsman_handedness);
 
  printf("Enter delivery type (f - Normal, y - Yorker, b - Bouncer): ");
  scanf(" %c", &delivery_type);
 
  ball_speed = estimateBallSpeed(bowler_type, delivery_type);
 
  printf("Estimated ball speed: %.2f m/s\n", ball_speed);
 
  if (over_number <= 6) {
    printf("Powerplay Fielding Suggestions: \n");
    suggestPowerplayFielding(batsman_handedness);
  } else {
    suggestFieldingPositions(ball_speed, batsman_handedness);
  }
 
  return 0;
}
 
 
  
