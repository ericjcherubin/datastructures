/**********************************************************************/
/*                                                                    */
/* Program Name: program1 - Calculation of Whole Number Ranges        */
/* Author:       Eric Cherubin                                        */
/* Installation: Pensacola Christian College                          */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: September 4, 2018                                    */
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
/* This program calculates a sum of whole number ranges.              */
/*                                                                    */
/**********************************************************************/

#include <stdio.h> /* printf, scanf                                   */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER  "CS227"    /* PCC assigned course number       */
#define LAST_NAME      "Cherubin" /* The programmer's last name       */
#define PROGRAM_NUMBER 1          /* Teacher assigned program number  */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void get_range(int *p_range_start, int *p_range_end);
   /* Get the whole number range                                      */
int sum_range(int range_start, int range_end);
   /* Calculate the range of whole numbers                            */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int range_end,   /* The user's last number                         */
       range_start; /* The user's first number                        */

   /* Print the program heading                                       */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Get start and end of range                                      */
   get_range(&range_start, &range_end);

   /* Print the whole number range                                    */
   printf("\nThe sum of all numbers between %d ", range_start); 
   printf("and %d (inclusively) is %d", range_end, 
            sum_range(range_start, range_end));

   /* Say goodbye and terminate                                       */
   printf("\n\nThanks for your range summing. Have a nice day! ;-)");
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
   printf("\n\nI'll sum whole numbers in a number range (inclusively).");
   printf("\n-------------------------------------------------------");
   return;
}

/**********************************************************************/
/*               Ask for the small number and large number            */
/**********************************************************************/
void get_range(int *p_range_start, int *p_range_end)
{
   printf("\nEnter a range of whole numbers now, lower number first:");
   printf("\n    What is your small number: ");
   scanf("%d", p_range_start);

   printf("    Give me your large number: ");
   scanf("%d", p_range_end);
   
   return;
}

/**********************************************************************/
/*               Ask for the small number and large number            */
/**********************************************************************/
int sum_range(int range_start, int range_end)
{
   int counter, /* The start of the range                            */
       sum = 0; /* The sum of the whole number range                 */

   for (counter = range_start; counter <= range_end; counter++)
   {
      sum += counter;
   }

   return sum;
}
