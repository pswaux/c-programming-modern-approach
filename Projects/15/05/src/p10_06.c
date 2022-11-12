/**
 *
 * Some calculators (notably those from Hewlett-Packard) use a system of writing
 * mathematical expressions known as Reverse Polish Notation (RPN). In this notation,
 * operators are placed after their operands instead of between their operands. For example,
 * 1 + 2 would be written 1 2 + in RPN, and 1 + 2 * 3 would be written 1 2 3 * +.
 * RPN expressions can easily be evaluated using a stack. The algorithm involves reading the
 * operators and operands in an expression from left to right, performing the following actions:
 *
 *    When an operand is encountered, push it onto the stack.
 *    When an operator is encountered, pop its operands from the stack,
 *    perform the operation on those operands, and then push the result onto the stack.
 *
 * Write a program that evaluates RPN expressions. The operands will be single-digit integers.
 * The operators are +, -. *. /. and =. The = operator causes the top stack item to be displayed;
 * afterwards, the stack is cleared and the user is prompted to enter another expression.
 * The process continues until the user enters a character that is not an operator or operand:
 *
 *    Enter an RPN expression: 1 2 3 * + =
 *    Value of expression: 7
 *    Enter an RPN expression: 5 8 * 4 9 - / =
 *    Value of expression: -8
 *    Enter an RPN expression: q
 *
 * If the stack overflows, the program will display the message "Expression is too complex" and terminate.
 * If the stack underflows (because of an expression such as 1 2 + +), the program will display the
 * message "Not enough operands in expression" and terminate.
 *
 * Hints: Incorporate the stack code from Section 10.2 into your program. Use scanf(" %c", &ch)
 * to read the operators and operands.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

int main(void) 
{
   char value1, value2;   // operands
   char ch;

   printf("Enter an RPN expression: ");
   for (; ;) {
      scanf(" %c", &ch);

      switch (ch) {
         case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8':
         case '9':
            push(ch - '0');
            break;
         case '+':
            value2 = pop();
            value1 = pop();
            push(value1 + value2);
            break;
         case '-':
            value2 = pop();
            value1 = pop();
            push(value1 - value2);
            break;
         case '*':
            value2 = pop();
            value1 = pop();
            push(value1 * value2);
            break;
         case '/':
            value2 = pop();
            value1 = pop();
            push(value1 / value2);
            break;
         case '=':
            printf("Value of expression: %d\n", pop());
            printf("Enter an RPN expression: ");
            make_empty();
            break;
         default:
            exit(EXIT_SUCCESS);
      }
   }
}
