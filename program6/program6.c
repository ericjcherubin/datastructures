/**********************************************************************/
/*                                                                    */
/* Program Name: program6 - A Student ID Linked List                  */
/* Author:       Eric Cherubin                                        */
/* Installation: Pensacola Christian College, Pensacola, FL           */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: December 7, 2018                                     */
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
/*  This program creates, inserts into, sorts, and prints a linked    */
/*  list.                                                             */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <stdlib.h> /* malloc, free, exit                             */
#include <ctype.h>  /* tolower                                        */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER     "CS227"    /* PCC assignd course number     */
#define HEADER_ALLOC_ERR  1          /* Header allocation error value */
#define ID_ALLOC_ERR      3          /* ID allocation error value     */
#define TRAILER_ALLOC_ERR 2          /* Trailer allocation error value*/
#define LAST_NAME         "Cherubin" /* The programer's last name     */  
#define LIST_HEADER       0          /* Lowest possible ID number     */
#define LIST_TRAILER      1000000    /* Highest possible ID number    */
#define MAXIMUM_ID        LIST_TRAILER-1
                                     /* Highest possible ID number    */
#define MINIMUM_ID        LIST_HEADER+1
                                     /* Lowest possible ID number     */
#define PROGRAM_NUMBER    6          /*Teacher assigned program number*/
#define QUIT              0          /* Program exit value            */

/**********************************************************************/
/*                         Program Structures                         */
/**********************************************************************/
/* Student ID list                                                    */
struct student
{
   int student_id;                 /* A student ID number             */
   struct student *p_next_student; /* Points to the next student      */
};
typedef struct student STUDENT;           

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
char get_response();
   /* Get response to continue or quit                                */
STUDENT *create_list();  
   /* Create an empty list with header and trailer nodes              */
void insert_student(STUDENT *p_new_student_list, int new_student_id);
   /* Insert a new student into the list                              */
void print_student_list(STUDENT *p_student_list);
   /* Print all students from the list                                */
int get_count_of_student(STUDENT *p_student_list);
   /* Get the count of the students                                   */
void sort_student_list(STUDENT *p_student_list, int student_quality);
   /* Sort the list in ascending order                                */
void remove_duplicates(STUDENT *p_student_list);
   /* Remove the duplicate ID's                                       */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   STUDENT *p_student_list,  /* Points to the student ID list         */
           *p_current_student = p_student_list->p_next_student,
                             /* Points to the next student            */
           *p_previous_student = p_student_list;
                             /* Points to the student list            */
   int     new_student_id,   /* New student ID entered                */
           student_quantity; /* Number of students                    */
                                

   /* Print the program heading                                       */
   printf("\n\n\n\n\n\n");
   print_heading();

   /* Loop processing student ID list until user quits                */
   while (print_instructions(), get_response() == 'y')
   {
      /* Create a new student ID list with header and trailer         */
      p_student_list = create_list();

      /* Loop processing user insert ID numbers until user quits      */
      while (printf("Enter the next student id (0 to quit): "), 
             scanf ("%d", &new_student_id), 
             new_student_id > LIST_HEADER)
      {
         if (new_student_id >= LIST_TRAILER)
            printf("\n   The student id list is empty.");
         else
            insert_student(p_student_list, new_student_id);
      } 
      
	   /* Print the unsorted student ID list                          */
      printf("\nThe unsorted student id list, as entered, is:");
      print_student_list(p_student_list);
      printf("\nThe length of the unsorted student id list is: %d", 
         get_count_of_student(p_student_list));

      /* Sort the list and print the sorted student ID list          */
      student_quantity = get_count_of_student(p_student_list);
      printf("\n\nThe student id list, sorted ascending by id, is:");
      print_student_list(p_student_list);
      printf("\nThe length of the sorted student id list is: %d", 
         get_count_of_student(p_student_list));



      /* Remove duplicates from list and print the list with         */
	   /* duplicates removed                                          */
      remove_duplicates(p_student_list);
      printf("\n\nThe student id list, with duplicates removed, is:");
      print_student_list(p_student_list);
      printf("\nThe length of the cleaned and sorted student ");
      printf("id list is: %d", get_count_of_student(p_student_list));



      /* Release the memory for the list                             */
      while (p_current_student->student_id <= LIST_TRAILER)
      {
         free (p_previous_student);
         p_previous_student = p_current_student;
         p_current_student = p_current_student->p_next_student;
      }   
   }

   /* Say goodbye and terminate the program                          */
   printf("\nThanks for using this program.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                      Print the program heading                     */
/**********************************************************************/
void print_heading()
{
   printf("\n========================================================");
   printf("\n               Program Number: %d",    PROGRAM_NUMBER);
   printf("\n               Programmer: %s",        LAST_NAME);
   printf("\n               PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   return;
}

/**********************************************************************/
/*                    Print the program instructions                  */
/**********************************************************************/
void print_instructions()
{
   printf("\n\n");
   printf("\n    This program maintains a list of students by their");
   printf("\n    id number.  After entry of all id's, it sorts them");
   printf("\n    into ascending order, then removes all duplicates.");

   return;
}

/**********************************************************************/
/*            Get the response from user to continue or quit          */
/**********************************************************************/
char get_response()
{
   char response[2]; /* The user response                             */
   
   do
   {
      printf("\n\nDo you want to enter another student id list");
      printf(" (y or n): ");
      scanf ("%1s", &response[0]);
      response[0] = tolower(response[0]);
   }
   while (response[0] != 'y' && response[0] != 'n');

   return response[0];
}

/**********************************************************************/
/*             Create an empty list with header and trailer           */
/**********************************************************************/
STUDENT *create_list()
{
   STUDENT *p_new_student_list; /* Points to the new created list     */
   
   if ((p_new_student_list = (STUDENT *) malloc(sizeof(STUDENT))) 
                                                                == NULL)
   {
      printf("\nError #%d in create_list.", HEADER_ALLOC_ERR);
      printf("\nCannot allocate memory for the list header.");
      printf("\nThe program is aborting.");
      exit  (HEADER_ALLOC_ERR);
   }
   
   p_new_student_list->student_id = LIST_HEADER;

   if ((p_new_student_list->p_next_student 
                         = (STUDENT *) malloc(sizeof(STUDENT))) == NULL)
   {
      printf("\nError #%d in create_list.", TRAILER_ALLOC_ERR);
      printf("\nCannot allocate memory for the list trailer.");
      printf("\nThe program is aborting.");
      exit  (TRAILER_ALLOC_ERR);
   }

   p_new_student_list->p_next_student->student_id     = LIST_TRAILER;
   p_new_student_list->p_next_student->p_next_student = NULL;

   return p_new_student_list;   
}

/**********************************************************************/
/*                Insert a new student into the list                  */
/**********************************************************************/
void insert_student(STUDENT *p_new_student_list, int new_student_id)
{
   STUDENT *p_current_student = p_new_student_list->p_next_student,
		                     /* Points to each student ID               */
           *p_new_student, /* Points to a new created student ID      */
           *p_previous_student = p_new_student_list;
		                     /* Points to the previous student ID       */
           

   if ((p_new_student = (STUDENT *) malloc(sizeof(STUDENT))) == NULL)
   {
      printf("\nError #%d in insert_node.", ID_ALLOC_ERR);
      printf("\nCannot allocate memory for a new list node.");
      printf("\nThe program is aborting.");
      exit  (ID_ALLOC_ERR);
   }

   p_new_student->student_id          = new_student_id;
   p_new_student->p_next_student      = p_current_student;
   p_previous_student->p_next_student = p_new_student;

   return;
}

/**********************************************************************/
/*                  Print all students from the list                  */
/**********************************************************************/
void print_student_list(STUDENT *p_student_list)
{ 
   while (p_student_list = p_student_list->p_next_student,
          p_student_list->student_id < LIST_TRAILER)
          printf("\n%25d", p_student_list->student_id);
   
   return;
}

/**********************************************************************/
/*                    Get the count of the students                   */
/**********************************************************************/
int get_count_of_student(STUDENT *p_student_list)
{
   int student_count = 0; /* Student count value                      */

   while (p_student_list = p_student_list->p_next_student,
          p_student_list->student_id < LIST_TRAILER)
      student_count += 1;

   return student_count;
}

/**********************************************************************/
/*                   Sort the list in ascending order                 */
/**********************************************************************/
void sort_student_list(STUDENT *p_student_list, int student_quantity)
{
   STUDENT *p_student,    /* Points to the student list               */
           *temp_student; /* Temporary student for the swap           */
   int     student_count; /* Number of students                       */

   for (student_count = 1; student_count < student_quantity; 
        student_count++)
   {
      p_student = p_student_list;
      while (p_student->p_next_student->p_next_student->student_id 
             != LIST_TRAILER)
      {
         if (p_student->p_next_student->student_id > 
             p_student->p_next_student->p_next_student->student_id)
         {
            temp_student = p_student->p_next_student->p_next_student;
            p_student->p_next_student = 
               p_student->p_next_student->p_next_student->p_next_student;
            temp_student = p_student->p_next_student;
            p_student = temp_student;
         }
         p_student = p_student->p_next_student;
      }
   }

   return; 
}

/**********************************************************************/
/*                       Remove the duplicate ID's                    */
/**********************************************************************/
void remove_duplicates(STUDENT *p_student_list)
{
   STUDENT *p_current_student  = p_student_list->p_next_student, 
                                 /* Points to each student            */
           *p_previous_student = p_student_list;
                                 /* Points to the previous student    */

   while (p_current_student->student_id != LIST_TRAILER)
   {
      if (p_previous_student->student_id == 
          p_current_student->student_id)
      {
         p_previous_student->p_next_student = 
            p_current_student->p_next_student;
         free (p_current_student);
         p_previous_student = p_current_student;
      }
      p_previous_student = p_current_student;
      p_current_student  = p_current_student->p_next_student;
   } 

   return;
}
