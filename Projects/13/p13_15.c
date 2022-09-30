/**
 *
 * Modify Programming Project 6 from Chapter 10 so that it includes 
 * the following function:
 *
 *       int evaluate_RPN_expression(const char *expression);
 *
 * The function returns the value of the RPN expression pointed to by expression.
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

/* external variables   */
int contents[STACK_SIZE];
int top = 0;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/* prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);
int evaluate_RPN_expression(const char *expression);
int read_line(char str[], int n);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void) 
{
   char expression[STACK_SIZE];

   while (true) {
      printf("Enter an RPN expression: ");
      read_line(expression, STACK_SIZE);

      if (strcmp(expression, "q") == 0)
         break;
 
      printf("Value of expression: %d\n", 
            evaluate_RPN_expression(expression));
   }

   return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void make_empty(void)
{
   top = 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool is_empty(void) 
{
   return top == 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool is_full(void)
{
   return top == STACK_SIZE;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void push(int i)
{
   if (is_full())
      stack_overflow();
   else
      contents[top++] = i;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int pop(void) 
{
   if (is_empty())
      stack_underflow();

   return contents[--top];
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void stack_overflow(void) 
{
   printf("Expression is too complex\n");
   exit(EXIT_FAILURE);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void stack_underflow(void) 
{
   printf("Not enough operands in expression\n");
   exit(EXIT_FAILURE);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int evaluate_RPN_expression(const char *expression)
{
   int value1 = 0, value2 = 0;
   int result = 0;

   for (int i = 0; i < strlen(expression); i++) {
      switch (*(expression + i)) {
         case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8':
         case '9':
            push(*(expression + i) - '0');
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
            result = pop();
            make_empty();
            break;
      }
   }

   return result;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int read_line(char str[], int n)
{
   int ch, i = 0;

   while ((ch = getchar()) != '\n')
      if (i < n)
         str[i++] = ch;
   str[i] = '\0';

   return i;
}
