/**
 *
 * Modify the poker.c program of Section 10.5 by having it
 * recognize an additional category, “royal flush”
 * (ace, king, queen, jack, ten of the same suit).
 * A royal flush ranks higher than all other hands.
 *
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 5
#define NUM_SUITS 2
#define NUM_CARDS 5

/* external variables   */
char hand[NUM_RANKS][NUM_SUITS];
bool royal, straight, flush;
int four, three;
int pairs;  // can be 0, 1, or 2
int sum_ranks = 0;

/* prototypes  */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void) 
{
   for (;;) {
      read_cards();
      analyze_hand();
      print_result();
   }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void read_cards(void)
// reads the cards into the external variables num_in_rank 
// and num_in_suit; checks for bad cards and duplicate cards
{
   char ch, rank_ch, suit_ch;
   int rank, suit;
   bool bad_card, duplicate_card;
   int cards_read = 0;
   sum_ranks = 0;

   for (rank = 0; rank < NUM_RANKS; rank++) {
      for (suit = 0; suit < NUM_SUITS; suit++)
         hand[rank][suit] = '-';
   }

   while (cards_read < NUM_CARDS) {
      bad_card = false;
      duplicate_card = false;

      printf("Enter a card: ");
      rank_ch = getchar();
      switch (rank_ch) {
         case '0': exit(EXIT_SUCCESS);
         case '2':            rank = 0; break;
         case '3':            rank = 1; break;
         case '4':            rank = 2; break;
         case '5':            rank = 3; break;
         case '6':            rank = 4; break;
         case '7':            rank = 5; break;
         case '8':            rank = 6; break;
         case '9':            rank = 7; break;
         case 't': case 'T':  rank = 8; break;
         case 'j': case 'J':  rank = 9; break;
         case 'q': case 'Q':  rank = 10; break;
         case 'k': case 'K':  rank = 11; break;
         case 'a': case 'A':  rank = 12; break;
         default:             bad_card = true;
      }

      suit_ch = getchar();
      switch (suit_ch) {
         case 'c': case 'C': suit = 0; break;
         case 'd': case 'D': suit = 1; break;
         case 'h': case 'H': suit = 2; break;
         case 's': case 'S': suit = 3; break;
         default:            bad_card = true;
      }

      while ((ch = getchar() != '\n'))
         if (ch != ' ') bad_card = true;

      for (int i = 0; i < cards_read; i++) {
         if (hand[i][0] == rank_ch && hand[i][1] == suit_ch)
            duplicate_card = true;
      }

      if (bad_card) {
        printf("Bad card; ignored.\n");
      } else if (duplicate_card) {
         printf("Duplicate card; ignored.\n");
      } else {
         hand[cards_read][0] = rank_ch;
         hand[cards_read][1] = suit_ch;
         sum_ranks += rank;   // for analyze_hand
         cards_read++;
      }
   }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void analyze_hand(void)
// determines whether the hand contains a straight, a flush, 
// four-of-a-kind, and/or three-of-a-kind; determines the 
// number of pairs; stores the result into the external variables 
// straight, flush, four, three, and pairs.
{
   int rank, same_ranks = 0;
   int card;
   char rank_ch;
   straight = false;
   flush = false;
   four = 0;
   three = 0;
   pairs = 0;

   /* check for flush   */
   for (int card = 0; card < NUM_CARDS - 1; card++) {
      if (hand[card][1] == hand[card+1][1])
         flush = true;
      else {
         flush = false;
         break;
      }
   }

   /* check that how many same rank do we have  */
   card = 0;
   for ( ; card < NUM_CARDS; card++) {
      rank_ch = hand[card][0];

      for (rank = card + 1; rank < NUM_CARDS; rank++) {
         if (rank_ch == hand[rank][0])
            same_ranks++;
      }
   }

   /* check for royal flush   */
   if (sum_ranks == 50) {
      royal = true;
   }


   /**
    *
    * check for straight:
    *
    *    in read_cards function, in switch statement, we set rank values
    *    for each corresponding rank_ch values and we summed them up into
    *    the sum_ranks variable;
    *
    *    sum of the every group of five consecutive rank is divisible by 5;
    *
    *    0('2') + 1('3') + 2('4') + 3('5') + 4('6') = 10
    *    1('3') + 2('4') + 3('5') + 4('6') + 5('7') = 15
    *    .
    *    .
    *    8('t') + 9('j') + 10('q') + 11('k') + 12('a') = 50 // royal flush
    *
    *    so, if the sum is divisible by 5 and the ranks are consecutive,
    *    the hand is a straight.
    *
    */
   if (sum_ranks % 5 == 0 && same_ranks == 0) {
      straight = true;
      return;
   }

   /**
    * check for 4-of-a-kind, 3-of-a-kind, and pairs;
    *
    * four should be 4, three should be 3 and pair should be
    * 1 or 2 to indicate a pair or two pairs.
    *
    */
   if (same_ranks > 4) {
      four = 4;
      three = same_ranks - 4; // shouldn't be equal 3 here (four of a kind)
   } else if (same_ranks > 2) {
      three = 3;
      pairs = same_ranks - 3; // can only be 1 (three or full house)
   } else
      pairs = same_ranks;     // 1 or 2 (pair or two pair)

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void print_result(void)
// prints the classification of the hand, based on the values of the 
// external variables straight, flush, four, three, and pairs
{
   if (royal && flush)                printf("Royal flush");
   else if (straight && flush)        printf("Straight flush");
   else if (four == 4)                printf("Four of a kind");
   else if (three == 3 && pairs == 1) printf("Full house");
   else if (flush)                    printf("Flush");
   else if (straight)                 printf("Straight");
   else if (three == 3)               printf("Three of a kind");
   else if (pairs == 2)               printf("Two pairs");
   else if (pairs == 1)               printf("Pair");
   else                               printf("High card");

   printf("\n\n");
}
