#include <stdio.h>

int main() {
  float value, converted_value;
  char unit_from, unit_to;

  printf("Unit Converter\n");

  // Get user input for value and units
  printf("Enter the value to convert: ");
  scanf("%f", &value);

  printf("Enter the unit you are converting from (C/F/M/ft/G/Kg): ");
  scanf(" %c", &unit_from); // Use space before %c to consume newline

  printf("Enter the unit you are converting to (C/F/M/ft/G/Kg): ");
  scanf(" %c", &unit_to); // Use space before %c to consume newline

  // Perform conversion based on user input
  switch (unit_from) {
    case 'C': // Celsius
      if (unit_to == 'F') {
        converted_value = (value * 9.0 / 5.0) + 32;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", value, converted_value);
      } else {
        printf("Invalid conversion. Cannot convert from Celsius to %c.\n", unit_to);
      }
      break;
    case 'F': // Fahrenheit
      if (unit_to == 'C') {
        converted_value = (value - 32) * 5.0 / 9.0;
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", value, converted_value);
      } else {
        printf("Invalid conversion. Cannot convert from Fahrenheit to %c.\n", unit_to);
      }
      break;
    case 'M': // Meters
      if (unit_to == 'ft') {
        converted_value = value * 3.28;
        printf("%.2f meters is equal to %.2f feet\n", value, converted_value);
      } else {
        printf("Invalid conversion. Cannot convert from Meters to %c.\n", unit_to);
      }
      break;
    case 'f': // Feet
      if (unit_to == 'M') {
        converted_value = value / 3.28;
        printf("%.2f feet is equal to %.2f meters\n", value, converted_value);
      } else {
        printf("Invalid conversion. Cannot convert from Feet to %c.\n", unit_to);
      }
      break;
    case 'G': // Grams
      if (unit_to == 'Kg') {
        converted_value = value / 1000;
        printf("%.2f grams is equal to %.2f kilograms\n", value, converted_value);
      } else {
        printf("Invalid conversion. Cannot convert from Grams to %c.\n", unit_to);
      }
      break;
    case 'K': // Kilograms
      if (unit_to == 'G') {
        converted_value = value * 1000;
        printf("%.2f kilograms is equal to %.2f grams\n", value, converted_value);
      } else {
        printf("Invalid conversion. Cannot convert from Kilograms to %c.\n", unit_to);
      }
      break;
    default:
      printf("Invalid unit entered.\n");
  }

  return 0;
}
