/**********************************************************************/
/*                                                                    */
/* Program Name: program3 - A Database of Scientific Data             */
/* Author:       Eric Cherubin                                        */
/* Installation: Pensacola Christian College, Pensacola, FL           */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 5, 2018                                      */
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
#include <stdlib.h> /* malloc, free, exit                             */
#include <string.h> /* memcompy                                       */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER  "CS227"    /* PCC assigned course number       */
#define DATA_ALLOC_ERR 1          /* The data allocation error value  */
#define LAST_NAME      "Cherubin" /* The programmer's last name       */
#define MAX_QUANTITY   100        /* The maximum quantity value       */
#define MIN_QUANTITY   2          /* The minimum quantity value       */
#define PROGRAM_NUMBER 3          /* Teacher assigned program number  */
#define SORT_ALLOC     2          /* The sort allocation error value  */
#define QUIT           0          /* The program exit value           */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();  
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
int get_quantity();
   /* Get the quantity                                                */
void get_data(float *p_data_start, int quantity);
   /* Get the scientific experimental data                            */
void sort_data(float *p_data_start, int quantity);
   /* Sort the scientific experimental data                           */
void print_data(float *p_data_start, int quantity);
   /* Print the scientific experimental data                          */
float sum_data(float *p_data_start, int quantity);
   /* Sum the scientific experimental data                            */
void print_total(float sum_data);
   /* Print the sum of the scientific experimental data               */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int   quantity; /* The quantity of scientific data                 */
   float *p_data;  /* The database of scientific data                 */

   /* Print the heading                                               */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Loop processing pairs of scientific data until user quits       */
   while ((print_instructions(), quantity = get_quantity()) != QUIT) 
   {

      /* Allocate memory for database of scientific data              */
      if ((p_data = (float *) malloc(sizeof(*p_data)*quantity)) == NULL)
      {
         printf("\nError #%d occurred in main()", DATA_ALLOC_ERR);
         printf("\nNot enough memory to allocate data.");
         printf("\nThe program is aborting.");
         printf("\n\n\n\n\n\n");
         exit  (DATA_ALLOC_ERR);
      }

      /* Get, Sort, and Print the data and Print the sum              */
      get_data   (p_data, quantity);
      sort_data  (p_data, quantity);
      print_data (p_data, quantity);
      print_total(sum_data(p_data, quantity));

      /* Release the memory for the experimental scientific data      */
      free(p_data);
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
   return;
}

/**********************************************************************/
/*                    Print the program instructions                  */
/**********************************************************************/
void print_instructions()
{
   printf("\n\n\nThis program processes experimental scientific data");
   printf("\n---------------------------------------------------");
   return;
}

/**********************************************************************/
/*                     Get the quantity of the data                   */
/**********************************************************************/
int get_quantity()
{
   int quantity; /* The quantity of scientific data                   */

   do
   {
      printf("\nHow many data values are there (2 to 100, 0=quit): ");
      scanf ("%d", &quantity);
   } while ((quantity < MIN_QUANTITY || quantity > MAX_QUANTITY)
        && (quantity != QUIT));

   return quantity;
}

/**********************************************************************/
/*                 Get the experimental scientific data               */
/**********************************************************************/
void get_data(float *p_data_start, int quantity)
{
   float *p_data; /* The database of scientific data                  */
  
   for (p_data = p_data_start; (p_data-p_data_start) < quantity; 
                                                               p_data++)
   {
      printf("   Enter data value %d: ", (int)(p_data-p_data_start)+1);
      scanf ("%f", p_data);

      if (*p_data < 0)
      {
         *p_data = -*p_data;
         printf("      Negative -%.2f converted to positive ", 
            *p_data);
         printf("%.2f\n", *p_data); 
      }
   }

   return;
}

/**********************************************************************/
/*               Sort the scientific experimental data                */
/**********************************************************************/
void sort_data(float *p_data_start, int quantity)
{
   float *p_big,        /* Points to the biggest value                */
         *p_data,       /* Points to every scientific data            */
         *p_sort,       /* Points to every sorted scientific data     */
         *p_sort_start; /* The database of sorted scientific data     */

   /* Allocate memory for the sorted scientific data                  */
   if ((p_sort_start = (float *) malloc(sizeof(float)*quantity)) 
      == NULL)
   {
      printf("\nError #%d occurred in sort function", SORT_ALLOC);
      printf("\nNot enough memory to allocate sort function");
      printf("\nThe program is aborting.");
      printf("\n\n\n\n\n\n");
      exit  (SORT_ALLOC);
   }

   /* Process the scientific data                                     */
   for (p_sort = p_sort_start; (p_sort-p_sort_start) < quantity; 
                                                               p_sort++)
   {
      *p_sort = 0.0f;
   
      for (p_data = p_data_start; (p_data-p_data_start) < quantity; 
                                                               p_data++)
      {
         if (*p_data > *p_sort)
         {
            *p_sort = *p_data;
            p_big = p_data;  
         }
      }
         *p_big = 0.0f;
  }

   /* Copy the scientific data                                        */
   memcpy(p_data_start, p_sort_start, sizeof(*p_sort)*quantity);
   
   /* Release the memory for the sorted experimental scientific data  */
   free (p_sort_start);

   return;
}

/**********************************************************************/
/*               Print the scientific experimental data               */
/**********************************************************************/
void print_data(float *p_data_start, int quantity)
{
   float *p_data; /* Points to every data                             */

   printf("\n\nThe data in descending order (with duplicates noted):");
   printf("  \n-----------------------------------------------------");
   
   for (p_data = p_data_start; (p_data-p_data_start) < quantity; 
                                                               p_data++)
   {
      printf("\n                 %9.2f", *p_data);
      if (p_data != p_data_start)
      {
         if (*p_data == *(p_data_start-1))
         {
            printf(" (duplicate)");
         }
      }
   }

   return;
}

/**********************************************************************/
/*                 Sum the scientific experimental data               */
/**********************************************************************/
float sum_data(float *p_data_start, int quantity)
{
   float data_sum, /* The sum of the scientific data                  */
         *p_data;  /* Points to every data                            */

   for (p_data = p_data_start; (p_data-p_data_start) < quantity; 
                                                               p_data++)
      data_sum += *p_data;

   return data_sum;   
}

/**********************************************************************/
/*           Print the sum of the scientific experimental data        */
/**********************************************************************/
void print_total(float sum_data)
{
   printf("\n                 ---------");
   printf("\n                 %9.2f total", sum_data);

   return;
}
