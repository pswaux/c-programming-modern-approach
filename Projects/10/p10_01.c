/**
 *
 * Modify the stack example of Section 10.2 so that it stores characters
 * instead of integers. Next, add a main function that asks the user to
 * enter a series of parentheses and/or braces, then indicates whether or
 * not they're properly nested:
 *
 *    Enter parentheses and/or braces: ( () { } { () } )
 *    Parentheses/braces are nested properly
 *
 * Hint: As the program reads characters, have it push each left parenthesis
 * or left brace. When it reads a right parenthesis or brace, have it pop the
 * stack and check that the item popped is a matching parenthesis or brace.
 * (If not, the parentheses/braces aren't nested properly.) When the program
 * reads the new-line character, have it check whether the stack is empty;
 * if so, the parentheses/braces are matched. If the stack isn't empty
 * (or if stack underflow is ever called),the parentheses/braces aren't matched.
 * If stack overflow is called, have the program print the message Stack overflow
 * and terminate immediately.
 *
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 100

/* external variables   */
char contents[STACK_SIZE];
int top = 0;

/* prototypes  */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char);
char pop(void);
void stack_underflow(void);
void stack_overflow(void);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void) 
{
   char item, popped_ch;
   bool match;

   printf("Enter parentheses and/or braces: ");
   for (;;) {
      item = getchar();
      if (item == '\n')
         break;

      if (item == '{' || item == '(')
         push(item);

      if (item == '}' || item == ')') {
         popped_ch = pop();

         if ((popped_ch == '(' && item == ')') ||
             (popped_ch == '{' && item == '}')) {
            match = true;
         } else {
            match = false;
            break;
         }
      }
   }

   if (is_empty() && match)
      printf("Parentheses/braces are nested properly\n");
   else
      printf("Parentheses/braces aren't nested properly\n");

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

void push(char ch) 
{
   if (is_full())
      stack_overflow();
   else
      contents[top++] = ch;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

char pop(void) 
{
   if (is_empty())
      stack_underflow();
   
   return contents[--top];
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void stack_underflow(void)
{
   printf("ERROR: Stack underflow");
   exit(EXIT_FAILURE);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void stack_overflow(void) 
{
   printf("ERROR: Stack overflow");
   exit(EXIT_FAILURE);
}
