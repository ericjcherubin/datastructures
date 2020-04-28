/**********************************************************************/
/*                                                                    */
/* Program Name: program4 - Database of Customer Receivable Accounts  */
/* Author:       Eric Cherubin                                        */
/* Installation: Pensacola Christian College, Pensacola, FL           */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 16, 2018                                     */
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
/* This program creates a database of customer receivable accounts.   */
/* The database of customer receivable accounts contains the          */
/* the customer's last name, the amount the customer owed, and        */
/* the priority of the customer.                                      */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf, getchar                         */
#include <stdlib.h> /* malloc, exit                                   */
#include <string.h> /* strcmp                                         */
#include <ctype.h>  /* isalpha, tolower, toupper                      */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define DB_ALLOC_ERR    1          /* Data allocation error value     */
#define COURSE_NUMBER   "CS227"    /* PCC assigned course number      */
#define END_OF_STRING   '\0'       /* End of string character         */
#define MAX_CUSTOMERS   100        /* Maximum quantity of customers   */
#define MAX_NAME_LENGTH 20         /* Maximum name length             */
#define MIN_CUSTOMERS   2          /* Minimum quantity of customers   */
#define NEW_LINE        '\n'       /* New line character              */
#define LAST_NAME       "Cherubin" /* The programmer's last name      */
#define PROGRAM_NUMBER  4          /* Teacher assigned program number */
#define QUIT            0          /* Program exit value              */

/**********************************************************************/
/*                         Program Structures                         */
/**********************************************************************/
/* The customer account receivable                                    */
struct customer
{
   char  last_name[MAX_NAME_LENGTH+1]; /* Last name of customer       */
   float amount_owed;                  /* Customer amount owed        */
   int   priority;                     /* Customer priority           */
};

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
int get_number_of_customers();
   /* Get the number of customers                                     */
void get_customers(struct customer *p_customer_start, 
   int number_of_customers);
   /* Get the customer account receivable data                        */
void clean_up_names(struct customer *p_customer_start, 
   int number_of_customers);
   /* Clean up the customers' last names                              */
void sort_customers(struct customer *p_customer_start, 
   int number_of_customers);
   /* Sort the customer accounts receivable                           */
void print_customers(struct customer *p_customer_start, 
   int number_of_customers);
   /* Print the customer account receivable records                   */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int number_of_customers;     /* Number of customers                */
   struct customer *p_customer; /* Points to a customer               */

   /* Print the heading                                               */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Loop processing customer accounts receivable until user quits   */
   while ((print_instructions(), 
      number_of_customers = get_number_of_customers()) != QUIT) 
   {

      /* Allocate memory for customer accounts receivable database    */
      if ((p_customer = (struct customer *) 
         malloc(sizeof(*p_customer)*number_of_customers)) == NULL)
      {
         printf("\nError #%d occurred in main()", DB_ALLOC_ERR);
         printf("\nUnable to allocate memory for database");
         printf("\nThe program is aborting.");
         printf("\n\n\n\n\n\n");
         exit  (DB_ALLOC_ERR);
      }

      /* Get the customer accounts receivable data, clean up the     */
      /* customers' last name, sort the customer accounts            */
      /* receivable, and print the customer accounts receivable      */
      get_customers  (p_customer, number_of_customers);
      clean_up_names (p_customer, number_of_customers);
      sort_customers (p_customer, number_of_customers);
      print_customers(p_customer, number_of_customers);

      /* Indicate the end of processing customer accounts receivable */
      printf("\n\n******* End Of Customer Database Processing *******");
   }

   /* Release the memory for the customer accounts receivable        */
   free(p_customer);

   /* Say goodbye and terminate the program                          */
   printf("\n\nThanks for processing customers. Have a nice day! ;-)");
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
/*                   Print the program instructions                   */
/**********************************************************************/
void print_instructions()
{
   printf("\n\nThis program allows you to input customers which owe");
   printf("\nyou money (your accounts receivable), and manage these");
   printf("\naccounts in a database.  You will enter the following:");
   printf("\n   Customer last name (1-%d characters)", MAX_NAME_LENGTH);
   printf("\n   Amount the customer owes (to the exact cent)");
   printf("\n   Customer priority (1=VIP, 2=Important, 3=Regular)");
   printf("\nFrom %d to %d customers may be processed.", MIN_CUSTOMERS,
      MAX_CUSTOMERS);
   printf("\n\nGet the customers for the database");
   printf("\n--------------------------------------------------");
   return;
}

/**********************************************************************/
/*                     Get the number of customers                    */
/**********************************************************************/
int get_number_of_customers()
{
   int number_of_customers; /* The quantity of customer accounts      */

   do
   {
      printf("\nHow many customers do you have (%d to %d, 0=quit): ", 
         MIN_CUSTOMERS, MAX_CUSTOMERS);
      scanf ("%d", &number_of_customers);
   } while ((number_of_customers < MIN_CUSTOMERS || 
        number_of_customers > MAX_CUSTOMERS) && 
        (number_of_customers != QUIT));

   return number_of_customers;
}

/**********************************************************************/
/*                      Get the customer data                         */
/**********************************************************************/
void get_customers(struct customer *p_customer_start, 
   int number_of_customers)
{
   struct customer *p_customer; /* Points to every customer           */
   char *p_name;                /* Points to every character          */

   for (p_customer = p_customer_start; 
       (p_customer-p_customer_start) < number_of_customers; 
       p_customer++)
   {
      printf("\nCustomer number %d:", 
         (int)(p_customer-p_customer_start)+1);
      printf("\n   Enter the customer's last name: ");

      p_name = p_customer->last_name;

      *p_name = getchar();

      do 
      {
         p_name++;
         *p_name = getchar();
      }
      while (*p_name != NEW_LINE);

      *p_name = END_OF_STRING;
      
      printf("   Enter the amount owed: ");
      scanf ("%f", &p_customer->amount_owed);

      do
      {
         printf("   Enter the customer's priority (1-3): ");
         scanf ("%d", &p_customer->priority);
      } 
      while (p_customer->priority < 1 || p_customer->priority > 3);
   }
 
   return;
}

/**********************************************************************/
/*         Remove all non-letters and convert to title-case           */
/**********************************************************************/
void clean_up_names(struct customer *p_customer_start, 
   int number_of_customers)
{
   struct customer *p_customer; /* Points to every customer           */
   char   *p_fast,              /* Points to every character          */
          *p_outer,             /* Points to the first character      */
          *p_slow;              /* Receives all valid characters      */

   for (p_customer = p_customer_start; 
       (p_customer-p_customer_start) < number_of_customers; 
       p_customer++)
   {
      p_fast = p_customer->last_name;
      p_slow = p_customer->last_name;

      while (*p_fast != END_OF_STRING)
      {
         if (isalpha(*p_fast))
            *p_slow++ = tolower(*p_fast);
         p_fast++;
      }
      
      p_outer = p_customer->last_name;
      *p_outer = toupper(*p_outer);

      *p_slow = END_OF_STRING;
   }

   return;
}

/**********************************************************************/
/*                 Sort the customer accounts receivable              */
/**********************************************************************/
void sort_customers(struct customer *p_customer_start, 
   int number_of_customers)
{
   struct customer *p_inner,      /* Points to every customer         */
                   *p_outer,      /* Points to every customer         */
                   temp_customer; /* Temporary customer for the swap  */

   for (p_outer = p_customer_start; (p_outer-p_customer_start) < 
      number_of_customers; p_outer++)
   {
      for (p_inner = p_outer+1; 
          (p_inner-p_customer_start) < number_of_customers;
          p_inner++)
      {
         if (strcmp(p_outer->last_name, p_inner->last_name) > 0)
         {
            temp_customer = *p_outer;
            *p_outer = *p_inner;
            *p_inner = temp_customer;
         }
      }
   }

   return;
}

/**********************************************************************/
/*             Print the customer account receivable records          */
/**********************************************************************/
void print_customers(struct customer *p_customer_start, 
   int number_of_customers)
{
   struct customer *p_customer; /* Points to every customers          */
   
   printf("\n  Here is the accounts receivable customer database");
   printf("\n=====================================================");
   printf("\n   Customer Name         Amount        Priority");
   printf("\n--------------------    ---------    -------------");

   for (p_customer = p_customer_start; 
       (p_customer-p_customer_start) < number_of_customers; 
       p_customer++)
   {
      printf("\n%20s    $%8.2f %4d", p_customer->last_name, 
         p_customer->amount_owed, p_customer->priority);

      switch (p_customer->priority)
      {
         case 1:
            printf("(VIP)");
            break;
         case 2:
            printf("(Important)");
            break;
         case 3:
            printf("(Regular)");
            break;
      }
   }

   return;
}
