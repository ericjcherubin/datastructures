/**********************************************************************/
/*                                                                    */
/* Program Name: program2 - Miscellaneous Operations on Whole Numbers */
/* Author:       Eric Cherubin                                        */
/* Installation: Pensacola Christian College, Pensacola, FL           */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: September 12, 2018                                   */
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
/* This program asks for a menu choice and asks for two whole         */
/* numbers. The two whole numbers may be added together, the first    */ 
/* number raised to the power of the second number, sum the numbers   */
/* between the two whole numbers inclusively, and sorts the two whole */
/* numbers in ascending order.                                        */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <stdlib.h> /* exit()                                         */
#include <math.h>   /* pow()                                          */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"    /* PCC assigned course number      */
#define LAST_NAME       "Cherubin" /* The programmer's last name      */
#define MAX_MENU_CHOICE 5          /* The maximum menu choice value   */
#define MENU_CHOICE_ERR 1          /* The menu choice error value     */
#define MIN_MENU_CHOICE 1          /* The minimum menu choice value   */
#define PROGRAM_NUMBER  2          /* Teacher assigned program number */
#define QUIT            5          /* The program exit value          */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();  
   /* Print the program heading                                       */
void print_menu();     
   /* Print the menu                                                  */
int get_menu_choice(); 
   /* Get menu choice                                                 */
void get_two_whole_numbers(int *p_first_number, int *p_second_number);
   /* Get two whole numbers                                           */
int add_two_whole_numbers(int *p_first_number, int *p_second_number);
   /* Add two whole numbers                                           */
float raise_power(int *p_first_number, int *p_second_number);
   /* Raise first number to the power of the second number            */
int sum_whole_numbers(int first_number, int second_number);
   /* Sum all the numbers between the two whole numbers inclusively   */
void swap_whole_numbers(int *p_first_number, int *p_second_number);
   /* Swap the two numbers and put the numbers in ascending order     */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int first_number,  /* The first number entered                     */
       menu_choice,   /* The menu choice value                        */
       second_number; /* The second number entered                    */

   /* Print the heading                                               */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Loop processing pairs of whole numbers until the user quits     */
   while (print_menu(), (menu_choice = get_menu_choice()) != QUIT) 
   {
      /* Get the two whole numbers                                    */
      get_two_whole_numbers(&first_number, &second_number);
      
      /* The miscellaneous operations choices                         */
      switch (menu_choice)
      {

         /* Calculate the sum of the two whole numbers                */
         case 1:
            printf("\nThe sum of %d and %d is %d", first_number, 
               second_number, 
               add_two_whole_numbers(&first_number, &second_number));
            break;

         /* Calculate the sum of the two whole numbers                */
         case 2:
            printf("%d raised to the power of %d = %1.6e", 
               first_number, second_number, 
               raise_power(&first_number, &second_number));
            break; 

         /* Calculate the sum of numbers between the two numbers      */
			case 3:
			   printf("The sum of the numbers between %d ", 
               first_number);
            printf("and %d (inclusive) is %d", second_number,
			      sum_whole_numbers(first_number, second_number));
			   break;
         /* Calculate the sum of numbers between the two numbers      */
			case 4:
			   if (first_number > second_number)
            {
               printf("\n%d and %d properly ordered are: ", 
                  first_number, second_number);
               swap_whole_numbers(&first_number, &second_number);
               printf("%d and %d", first_number, second_number);
            }
            else
               printf("%d and %d are already in order", first_number,
                  second_number);
				break;

         /* Print error message if impossible choice was chosen       */
         default:
            printf("\nError #%d occurred in main()", 
               MENU_CHOICE_ERR);
            printf("\nAn impossible menu choice was chosen.");
            printf("\nThe program is aborting.");
            printf("\n\n\n\n\n\n");
            exit  (MENU_CHOICE_ERR);
      }
   }

   /* Say goodbye and terminate                                       */
   printf("\n\nThanks for processing numbers. Have a nice day! ;-)");
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
   printf("\n   Miscellaneous operations on your two whole numbers");
   return;
}

/**********************************************************************/
/*                       Print the menu choice                        */
/**********************************************************************/
void print_menu()
{
   printf("\n\nMake a selection from the following menu:");
   printf("\n-----------------------------------------");
   printf("\n     1 - Add two whole numbers");
   printf("\n     2 - Raise the 1st number to the power of the 2nd");
   printf("\n     3 - Sum all numbers between two whole numbers"); 
   printf("\n     4 - Put two whole numbers into ascending order");
   printf("\n     5 - Quit");
   return;
}

/**********************************************************************/
/*                       Get the menu choice                          */
/**********************************************************************/
int get_menu_choice()
{
   int menu_choice; /* The menu choice                                */
   
   do
   {
      printf("\nEnter your menu selection (%d-%d): ", 
         MIN_MENU_CHOICE, MAX_MENU_CHOICE);
      scanf ("%d", &menu_choice);
   } while  (menu_choice < MIN_MENU_CHOICE || menu_choice >  
        MAX_MENU_CHOICE);

   return menu_choice;
}

/**********************************************************************/
/*                   Get the two whole numbers                        */
/**********************************************************************/
void get_two_whole_numbers(int *p_first_number, int *p_second_number)
{
   printf("\nType in any two whole numbers now:");
   printf("\n    What is your first number: ");
   scanf ("%d", p_first_number);

   printf("    Give me your second number: ");
   scanf ("%d", p_second_number);
   return;
}

/**********************************************************************/
/*                  Add the two whole numbers                         */
/**********************************************************************/
int add_two_whole_numbers(int *p_first_number, int *p_second_number)
{
   return (*p_first_number + *p_second_number);
}

/**********************************************************************/
/*         Raise first number to the power of the second number       */
/**********************************************************************/
float raise_power(int *p_first_number, int *p_second_number)
{
   return (float)(pow((double)*p_first_number, 
      (double)*p_second_number));
}

/**********************************************************************/
/*      Sum the numbers between the two whole numbers inclusively     */ 
/**********************************************************************/
int sum_whole_numbers(int first_number, int second_number)
{
   int range_counter, /* The counter for the range of numbers         */
       range_sum = 0; /* The sum of the range of numbers              */

   for (range_counter = first_number; range_counter <= second_number; 
      range_counter++)
   {
      range_sum += range_counter;
   }

   return range_sum;
}

/**********************************************************************/
/*                     Swap the two whole numbers                     */
/**********************************************************************/
void swap_whole_numbers(int *p_first_number, int *p_second_number)
{
	int temp; /* The temporary number for the swap                     */

   temp = *p_first_number;
   *p_first_number = *p_second_number;
   *p_second_number = temp;

	return;
}
