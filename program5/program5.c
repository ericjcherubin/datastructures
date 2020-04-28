/**********************************************************************/
/*                                                                    */
/* Program Name: program5 - Recursive Sum of a Range                  */
/* Author:       Eric Cherubin                                        */
/* Installation: Pensacola Christian College, Pensacola, FL           */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 2, 2018                                     */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge  all of the lines  in this C program  are my own original */
/* work and that none of the lines in this C program have been copied */
/* from anyone else, unless I was specifically authorized to do so by */
/*                        my CS227 instructor.                        */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                           (signature)              */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program recursively calculates the sum of all even whole      */
/* numbers between two numbers inclusively. The user is asked to      */
/* enter two whole numbers, and the sum of all even numbers in the    */
/* range is calculated and printed.                                   */
/*                                                                    */
/**********************************************************************/

#include <stdio.h> /* printf, scanf                                   */
#include <ctype.h> /* tolower                                         */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER  "CS227"    /* PCC assigned course number       */
#define LAST_NAME      "Cherubin" /* The programmer's last name       */
#define MAXIMUM_VALUE  5000       /* Maximum range value              */
#define MINIMUM_VALUE  -5000      /* Minimum range value              */
#define PROGRAM_NUMBER 5          /* Teacher assigned program number  */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
char get_response();
   /* Get the user response                                           */ 
void get_range(int *p_range_start, int *p_range_end);
   /* Get the whole number range                                      */
void swap(int *p_range_start, int *p_range_end);
   /* Swap the two whole numbers                                      */
long recursive_sum_even(int range_start, int range_end);
   /* Calculate the range recursively                                 */
int  is_even(int range_start);
   /* Check if number is even                                         */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int range_end,   /* User's last number                             */
       range_start; /* User's first number                            */
   long even_sums;  /* Sum of the even whole range                    */

   /* Print the program heading and instructions                      */
   printf("\n\n\n\n\n\n");
   print_heading();
   print_instructions();

   /* Loop processing recursive whole range until user quits          */
   while (get_response() == 'y') 
   {

      /* Get the whole number range                                   */
      get_range(&range_start, &range_end);

      /* Calculate the even whole number range and print the sum      */
      even_sums = recursive_sum_even(range_start, range_end);
      printf("\nThe sum of all even numbers in the range ");
      printf("%d to %d is: %ld", range_start, range_end, even_sums);
   }
   
   /* Say goodbye and terminate                                       */
   printf("\n\nThanks for \"even summing\". Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                      Print the program heading                     */
/**********************************************************************/
void print_heading()
{
   printf("\n========================================================");
   printf("\n                Program Number: %d",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        LAST_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   return;
}

/**********************************************************************/
/*                    Print the program instructions                  */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program recursively calculates the sum of all");
   printf("\neven whole numbers between two numbers inclusively.");
   printf("\nYou are repeatedly asked to enter in the start and");
   printf("\nend of a range, and the sum of all even numbers in");
   printf("\nthat range is calculated and printed.  Information");
   printf("\nabout the recursive action of the function is also");
   printf("\nprinted so the recursive nature of the calculation");
   printf("\n              may be observed.");
   return;
}

/**********************************************************************/
/*                       Get the user response                        */
/**********************************************************************/
char get_response()
{
   char response[2]; /* The user's response                           */

   do
   {
      printf("\n\nDo you want to process another range (y or n): ");
      scanf ("%1s", response);
      response[0] = tolower(response[0]);
   } 
   while (response[0] != 'y' && response[0] != 'n');

   return response[0];
}

/**********************************************************************/
/*                     Get the whole number range                     */
/**********************************************************************/
void get_range(int *p_range_start, int *p_range_end)
{
   do
   {
      printf("\nEnter in the first number (from %d to %d): ", 
         MINIMUM_VALUE, MAXIMUM_VALUE);
      scanf ("%d", p_range_start);
   } 
   while (*p_range_start < MINIMUM_VALUE || 
          *p_range_start > MAXIMUM_VALUE);

   do
   {
      printf("\nEnter in the last number (from %d to %d): ", 
         MINIMUM_VALUE, MAXIMUM_VALUE);
      scanf ("%d", p_range_end);
   } 
   while (*p_range_end < MINIMUM_VALUE || 
          *p_range_end > MAXIMUM_VALUE);

   if (*p_range_start > *p_range_end)
      swap(p_range_start, p_range_end);

   return;
}

/**********************************************************************/
/*                     Swap the two whole numbers                     */
/**********************************************************************/
void swap(int *p_range_start, int *p_range_end)
{
   *p_range_start += *p_range_end;
   *p_range_end    = *p_range_start - *p_range_end;
   *p_range_start -= *p_range_end;

   return; 
}

/**********************************************************************/
/*          Calculate the even whole number range recursively         */
/**********************************************************************/
long recursive_sum_even(int range_start, int range_end)
{
   long even_sums; /* Sum of the even whole range                     */

   printf("\nProcessing the range %d to %d:", range_start, range_end);

   printf("\n   Entering sum function for range %d to %d", 
      range_start, range_end);

   if (range_start <= range_end)
   {
      if (is_even(range_start) == 0)
      {
         printf("\n       Adding: %d", range_start);
         even_sums = range_start + 
            recursive_sum_even(range_start + 1, range_end);
      }
      else
      {
         printf("\n       Skipping: %d", range_start);
         even_sums = recursive_sum_even(range_start + 1, range_end);
      }
   }

   printf("\n   Exiting sum function for range %d ", range_start); 
   printf("to %d with result: %ld", range_end, even_sums);

   return even_sums;
}

/**********************************************************************/
/*                    Check if first number is even                   */
/**********************************************************************/
int is_even(int range_start)
{
   range_start = range_start % 2;

   if (range_start == 0)
      return 0;
   else
      return 1;
}
