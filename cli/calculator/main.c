#include <stdio.h>

int main() {
  float firstValue;
  float secondValue;
  char operator;
  

  printf("*Calculator*\n");

  printf("Enter first value: ");
  scanf("%f", &firstValue);

  printf("Enter second value: ");
  scanf("%f", &secondValue);

  printf("\n(+, -, *, /)");
  printf("\nEnter operator: ");
  scanf("%s", &operator);


  switch (operator) {
    case '+':
      printf("\n%.2f", firstValue + secondValue);
      break;
    case '-':
      printf("\n%.2f", firstValue - secondValue);
      break;
    case '/':
      printf("\n%.2f", firstValue / secondValue);
      break;
    case '*':
      printf("\n%.2f", firstValue * secondValue);
      break;
    default:
      printf("Character %c is incorrect operator.", operator);
  }

  return 0;
}
