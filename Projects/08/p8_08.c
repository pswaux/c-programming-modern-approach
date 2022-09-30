/**
 * 
 * Modify Programming Project 7 so that it prompts for five quiz grades
 * for each of five students, then computes the total score and average score
 * for each student, and the average score, high score, and low score for each quiz.
 * 
 */
#include <stdio.h>

#define SIZE 5

int main(void)
{
   int students[SIZE][SIZE];
   double student_scores[SIZE] = {0.0};
   double quiz_scores[SIZE] = {0.0};
   double high = 0.0, low = 100.0;
   int row, col, student_total = 0; // total score for each student
   int quiz_total = 0;              // total score for each quiz


   /* initialize the array */
   for (row = 0; row < SIZE; row++) {
      printf("Enter the scores for student %d: ", row + 1);

      for (col = 0; col < SIZE; col++) {
         scanf("%d", &students[row][col]);
         student_total += students[row][col];
      }

      student_scores[row] = student_total;
      student_total = 0;
   }

   for (row = 0; row < SIZE; row++) {
      printf("\nTotal and the average score for student %d: %.2f %.2f", row + 1,
              student_scores[row], student_scores[row] / SIZE);
   }

   printf("\n");
   for (row = 0; row < SIZE; row++) {
      for (col = 0; col < SIZE; col++) {
         quiz_total += students[col][row];

         if (students[col][row] < low)
            low = students[col][row];

         if (students[col][row] > high)
            high = students[col][row];
      }

      quiz_scores[row] = quiz_total;
      quiz_total = 0;

      printf("\nThe average, high, and low scores for quiz %d: %.2f %.2f %.2f",
            row + 1, quiz_scores[row] / 5, high, low);

      high = 0.0;
      low = 100.0;
   }

   printf("\n");

   return 0;
}
