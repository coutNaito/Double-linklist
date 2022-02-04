// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   int item_ID,item_score; // char entered by user

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice );

   // loop while user does not choose 3
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf( "%s", "Enter a number: " );
            scanf( "%d", &item_ID );
            printf( "%s", "Enter a score: " );
            scanf("%d", &item_score);
            insert( &startPtr, item_ID, item_score ); // insert item in list
            printList( startPtr );
            printReverse(startPtr);
            break;
         case 2: // delete an element
            // if list is not empty
            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter number to be deleted: " );
               scanf( "%d", &item_ID );

               // if character is found, remove it
               if ( deletes( &startPtr, item_ID )==item_ID) { // remove item
                  printf( "%d deleted.\n", item_ID );
                  printList( startPtr );
                  printReverse( startPtr );
               } // end if
               else {
                  printf( "%d not found.\n\n", item_ID );
               } // end else
            } // end if
            else {
               puts( "List is empty.\n" );
            } // end else

            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } // end switch

      printf( "%s", "? " );
      scanf( "%u", &choice );
   } // end while

   puts( "End of run." );
} // end main
