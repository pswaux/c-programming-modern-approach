/**
 *
 * Modify Programming Project 6 from Chapter 3 so that the user may
 * add, subtract. multiply, or divide two fractions (by entering either
 * +, -, *, or / between the fractions).
 *
 */
#include <stdio.h>

int main(void) 
{
   int num1, denom1, num2, denom2, 
      result_num = 0, op, result_denom = 0;

	printf("Enter two fractions separated by operator: ");
	scanf("%d/%d%lc%d/%d", &num1, &denom1, &op, &num2, &denom2);

   switch (op) {
      case '+':
         result_num = num1 * denom2 + num2 * denom1;
	      result_denom = denom1 * denom2;
         break;
      case '-':
         result_num = num1 * denom2 - num2 * denom1;
	      result_denom = denom1 * denom2;
         break;
      case '*':
         result_num = num1 * num2;
	      result_denom = denom1 * denom2;
         break;
      case '/':
         result_num = num1 * denom2;
	      result_denom = denom1 * num2;
         break;
   }
	
	
	printf("%d/%d %c %d/%d = %d/%d\n", num1, denom1, op, 
      num2, denom2, result_num, result_denom);
   
   return 0;
}
