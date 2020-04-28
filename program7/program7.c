/**********************************************************************/
/*                                                                    */
/* Program Name: program7 - Demonstration of Search Algorithms        */
/* Author:       Eric Cherubin                                        */
/* Installation: Pensacola Christian College, Pensacola, FL           */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 21, 2018                                    */
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
/* This program demonstrates the following search algorithms:         */
/*    1. Ordered Sequential Search                                    */
/*    2. Probability Search                                           */
/*    3. Binary Search                                                */
/* The user enters a whole number and the program will search in an   */
/* ordered database of whole numbers using the 3 search algorithms    */
/*                                                                    */
/**********************************************************************/

#include <stdio.h> /* printf, scanf                                   */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER  "CS227"     /* PCC assigned course number      */
#define DATA_SIZE      15          /* Size of Whole Number Database   */
#define LAST_INDEX     DATA_SIZE-1 /* Last index of database          */
#define LAST_NAME      "Cherubin"  /* The programmer's last name      */
#define PROGRAM_NUMBER 7           /* Teacher assigned program number */
#define QUIT           0           /* Program exit value              */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
void get_data(int array[DATA_SIZE], int last_index);
   /* Get data for database of whole numbers                          */
void show_data(int search_array[], int last_index, int search_target);
   /* Show the whole number database                                  */
void search_result(char search_result, int *p_target_index);
   /* Show the result of the search                                   */
int ord_seq_search(int seq_data[], int last_index, 
   int search_target, int *p_target_index);
   /* Search using the ordered sequential search algorithm            */
int prb_search(int prb_data[], int last_index, 
   int search_target, int *p_target_index);
   /* Search using the probability search algorithm                   */
int bin_search(int bin_data[], int last_index, 
   int search_target, int *p_target_index);
   /* Search using the binary search algorithm                        */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int bin_data[DATA_SIZE], /* Binary Search  Database                */
       prb_data[DATA_SIZE], /* Probability Search  Database           */
       search_target,       /* The whole number search target         */
       seq_data[DATA_SIZE], /* Ordered Sequential Search  Database    */ 
       target_index;        /* The target search index                */

   /* Print the program heading and instructions                      */
   printf("\n\n\n\n\n\n");
   print_heading();
   print_instructions();

   /* Get data for the whole number database                          */
   get_data(seq_data, LAST_INDEX);
   get_data(prb_data, LAST_INDEX);
   get_data(bin_data, LAST_INDEX);

   /* Loop processing search whole number database until user quits   */
   while (printf("\n\n\nEnter an integer search target (0 to quit): "), 
          (scanf ("%d", &search_target), search_target != QUIT))
   {
      /* Search for target using ordered sequential search            */
      printf("\n");
      printf("\nOrdered Sequential Search:");
      show_data(seq_data, LAST_INDEX, search_target);
      if (ord_seq_search(seq_data, LAST_INDEX, search_target, 
	       &target_index) == 0)    
         search_result('U', &target_index);
      else
         search_result('S', &target_index);

      /* Search for target using probability search                   */
      printf("\n\nProbability Search:");
      show_data(prb_data, LAST_INDEX, search_target);
      if (prb_search(prb_data, LAST_INDEX, search_target, 
	       &target_index) == 0)           
         search_result('U', &target_index);
      else
         search_result('S', &target_index);

      /* Search for target using binary search                        */
      printf("\n\nBinary Search:");
      show_data(bin_data, LAST_INDEX, search_target);
      if (bin_search(bin_data, LAST_INDEX, search_target, 
	       &target_index) == 0)     
         search_result('U', &target_index);
      else
         search_result('S', &target_index);
   }

   /* Say goodbye and terminate the program                          */
   printf("\nThanks for searching.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                      Print the program heading                     */
/**********************************************************************/
void print_heading()
{
   printf("\n======================================================");
   printf("\n               Program Number: %d",    PROGRAM_NUMBER);
   printf("\n               Programmer: %s",        LAST_NAME);
   printf("\n               PCC Course Number: %s", COURSE_NUMBER);
   printf("\n======================================================");
   return;
}

/**********************************************************************/
/*                    Print the program instructions                  */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program demonstrates various search algorithms.");
   printf("\nYou enter in any whole number, and the program will");
   printf("\nsearch for it in an ORDERED array of whole numbers");
   printf("\nusing each of the following search algorithms:");
   printf("\n     1. Ordered Sequential Search");
   printf("\n     2. Probability Search");
   printf("\n     3. Binary Search");
   printf("\nThe progress of each search is shown so the efficiency");
   printf("\nof the search algorithms can be compared.");
   return;
}

/**********************************************************************/
/*                 Get data for database of whole numbers             */
/**********************************************************************/
void get_data(int search_array[], int last_index)
{
   int array_index; /* Index of database elements                     */

   for (array_index = 0; array_index <= last_index; array_index++)
      search_array[array_index] = array_index * 5 + 10;

   return;
}

/**********************************************************************/
/*                    Show the whole number database                  */
/**********************************************************************/
void show_data(int search_array[], int last_index, int search_target)
{
   int array_index; /* Index of database elements                     */
   
   printf("\n   Array Index: ");
   for (array_index = 0; array_index <= last_index; array_index++)
      printf("[%2d]", array_index);

   printf("\n    Array Data: ");
   for (array_index = 0; array_index <= last_index; array_index++)
      printf("%3d ", search_array[array_index]);

   printf("\n   User Target: %3d", search_target);

   return;
}

/**********************************************************************/
/*                       Show the search result                       */
/**********************************************************************/
void search_result(char search_result, int *p_target_index)
{
   printf("\nSearch Outcome: ");
   if (search_result == 'S')
      printf("Successful - target found at index [%2d]",
         *p_target_index);
   else
      printf("Unsuccessful - target not found"); 
}

/**********************************************************************/
/*           Search using the ordered sequential search algorithm     */
/**********************************************************************/
int ord_seq_search(int seq_data[], int last_index, int search_target, 
   int *p_target_index)
{
   int index = 0; /* Beginning index of search database               */

   printf("\n   Search Path: ");
   if (search_target <= seq_data[last_index])
   {
      while (search_target > seq_data[index])
      {
         printf("[%2d]", index);
         index++; 
      }
	  
      printf("[%2d]", index);
      *p_target_index = index;
   }
   else
   {
      printf("[%2d]", last_index);
      *p_target_index = last_index;
   }

   return (search_target == seq_data[index]);
}

/**********************************************************************/
/*              Search using the probability search algorithm         */
/**********************************************************************/
int prb_search(int prb_data[], int last_index, int search_target, 
   int *p_target_index)
{
   int index = 0; /* Beginning index of search database               */ 

   printf("\n   Search Path: ");
   while (index < last_index && search_target != prb_data[index])
   {
      printf("[%2d]", index);
      index++; 
   }

   printf("[%2d]", index);

   if (search_target == prb_data[index])
   {
      if (index > 0)
      {
         index -= 1;
         prb_data[index] = search_target;
      }
      *p_target_index = index;   
   }

   return (search_target == prb_data[index]);
}

/**********************************************************************/
/*                Search using the binary search algorithm            */
/**********************************************************************/
int bin_search(int bin_data[], int last_index, int search_target, 
   int *p_target_index)
{
   int begin_index = 0,        /* Beginning index of elemenets        */
       end_index = last_index, /* Last index of elements              */
       middle_index;           /* Middle index of elements            */
   
   printf("\n   Search Path: ");
   while (begin_index <= end_index)
   {
      middle_index = (begin_index + end_index) / 2;
      if (search_target > bin_data[middle_index])
         begin_index = (middle_index + 1);
      else
         if (search_target < bin_data[middle_index])
            end_index = (middle_index - 1);
      else
         begin_index = (end_index + 1);
      printf("[%2d]", middle_index);
   }

   *p_target_index = middle_index;

   return (search_target == bin_data[middle_index]);   
}
