#include <stdio.h>
/**
 *
 *
 ***********************
 ***********************
 ***********************
 ***********************
 ***********************
 * Simple Calculator App
 ***********************
 ***********************
 ***********************
 ***********************
 ***********************
 ***********************
 *
 *
 *
 *
 * */

float sum_numbers(float num1, float num2) { return num1 + num2; }
float subtract_numbers(float num1, float num2) { return num1 - num2; }
float divide_numbers(float num1, float num2) { return num1 / num2; }
float multiply_numbers(float num1, float num2) { return num1 * num2; }

int main() {
  printf("== Calculator Program ==");

  char operator;
  float num_one;
  float num_two;
  float result;

  printf("\nEnter an operator: (+, -, /, *)");
  scanf("%c", &operator);

  printf("Enter first number:");
  scanf("%f", &num_one);
  printf("Enter second number:");
  scanf("%f", &num_two);

  switch (operator) {
  case '-':
    result = subtract_numbers(num_one, num_two);
    printf("result: %f\n", result);
    break;
  case '/':
    result = divide_numbers(num_one, num_two);
    printf("result: %.2lf\n", result);
    break;
  case '+':
    result = sum_numbers(num_one, num_two);
    printf("result: %.2f\n", result);
    break;
  case '*':
    result = multiply_numbers(num_one, num_two);
    printf("%f\n", result);
    break;
  default:
    printf("\nPlease enter a supported operator (-, +, /, *)");
  }

  return 0;
}
