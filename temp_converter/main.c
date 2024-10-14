#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*
 *
 * == Memory safe Temperature converter ==
 *
 * Converts user-entered temperature values from Celsius to Fharenheit and
 viceversa.
 *
 *****************************************************************************
 *
 * LLM optimizations:
 * Input handling: fgets instead of scanf - is more safe and prevents buffer
 overflow
 * Input conversion: strtof to convert to string input to a float, more robust
 than scanf
 * Error handling: Added error checks for input operations and used
 fprintf(stderr, ...) for error messages.
 * Consistent naming: Fixed typos in "Celsius" and "Fahrenheit" throughout the
 code. Memory safety: Defined a BUFFER_SIZE constant to ensure consistent buffer
 sizes for input. Improved accuracy: Used 9.0f and 5.0f in calculations to
 ensure floating-point division.
 *
 *****************************************************************************
 *
 * */

#define BUFFER_SIZE 100

float celsius_to_fahrenheit(float celsius) {
  return (celsius * 9.0f / 5.0f) + 32.0f;
}

float fahrenheit_to_celsius(float fahrenheit) {
  return (fahrenheit - 32.0f) * 5.0f / 9.0f;
}

int main() {
  printf("== Temperature Converter ==\n");
  float temp;
  char unit;
  char input_buffer[BUFFER_SIZE];

  printf("Is the temp in Celsius (C) or Fahrenheit (F)? ");
  if (fgets(input_buffer, BUFFER_SIZE, stdin) == NULL) {
    fprintf(stderr, "Error reading input.\n");
    return 1;
  }
  unit = toupper(input_buffer[0]);

  printf("Enter temperature: ");
  if (fgets(input_buffer, BUFFER_SIZE, stdin) == NULL) {
    fprintf(stderr, "Error reading input.\n");
    return 1;
  }
  temp = strtof(input_buffer, NULL);

  switch (unit) {
  case 'C':
    printf("Temperature in Fahrenheit is: %.2f\n", celsius_to_fahrenheit(temp));
    break;
  case 'F':
    printf("Temperature in Celsius is: %.2f\n", fahrenheit_to_celsius(temp));
    break;
  default:
    fprintf(stderr, "Invalid unit. Please enter C or F.\n");
    return 1;
  }

  return 0;
}
