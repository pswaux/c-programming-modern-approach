/**
 *
 * Write a program that evaluates an expression:
 *
 *    Enter an expression: 1+2.5*3
 *    Value of expression: 10.5
 *
 * The operands in the expression are floating-point numbers;
 * the operators are +, -, *, and /. The expression is evaluated
 * from left to right (no operator takes precedence over any other
 * operator).
 *
 */
#include <stdio.h>

int main(void)
{
   float number, result;
   char op;

   printf("Enter an expression: ");
   scanf("%f", &result);
   op = getchar();
   scanf("%f", &number);

   for (; ;) {    
      switch (op) {
         case '+': result += number; break;
         case '-': result -= number; break;
         case '*': result *= number; break;
         case '/': result /= number; break;
      }

      op = getchar();
      if (op == '\n') break;
   
      scanf("%f", &number);
   }

   printf("Value of expression: %.2f\n", result);
}
