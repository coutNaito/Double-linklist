#include <stdlib.h>
#include <stdio.h>

struct Node {                                      
   int ID; // each listNode contains a character
   int score; 
   struct Node *nextPtr;  // pointer to next node
   struct Node *pPtr;   //point to prev node
}; // end structure listNode                        

typedef struct Node LLnode; // synonym for struct listNode
typedef LLnode* LLPtr; // synonym for ListNode*

// prototypes

int deletes( LLPtr *sPtr, int value );
//int deletes( LLnode **sPtr, int value );

int isEmpty( LLPtr sPtr );
void insert( LLPtr *sPtr, int value, int score );
//int insert( LLnode **sPtr, int value );

void printList( LLPtr currentPtr );
void printReverse( LLPtr currentPtr );

void instructions( void );


// display program instructions to user
void instructions( void )
{ 
   puts( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end." );
      
} // end function instructions

// insert a new value into the list in sorted order
void insert( LLPtr *sPtr, int value , int score)
{ 
   LLPtr newPtr = NULL; // pointer to new node
   LLPtr previousPtr = NULL; // pointer to previous node in list
   LLPtr currentPtr = NULL; // pointer to current node in list

   newPtr =(LLPtr) malloc( sizeof( LLnode ) ); // create node

   if ( newPtr != NULL ) { // is space available
      newPtr->ID = value; // place value in node
      newPtr->score = score; //place score in node
      newPtr->nextPtr = NULL; // node does not link to another node
      newPtr->pPtr = NULL;

      previousPtr = NULL;
      currentPtr = *sPtr;

      // loop to find the correct location in the list       
      while ( currentPtr != NULL && value > currentPtr->ID ) {
         previousPtr = currentPtr; // walk to ...               
         currentPtr = currentPtr->nextPtr; // ... next node 
      } // end while                                         

      // insert new node at beginning of list
      if ( previousPtr == NULL ) { 
        
        newPtr->nextPtr = *sPtr;
        if(*sPtr) (*sPtr)->pPtr=newPtr; //if start not point to null do this
         
        newPtr->pPtr = NULL;    //set first previous node to null;
        *sPtr = newPtr;
        
      } // end if
      else if(currentPtr == NULL)
      {
        newPtr->nextPtr = previousPtr->nextPtr;
        previousPtr->nextPtr = newPtr;
        newPtr->pPtr = previousPtr;
      }
      else { // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->pPtr=previousPtr;//create double linklist

         newPtr->nextPtr = currentPtr;
         currentPtr->pPtr=newPtr;

      } // end else
   } // end if
   else {
      printf( "%d not inserted. No memory available.\n", value );
   } // end else
} // end function insert

// delete a list element
int deletes( LLPtr *sPtr, int value )
{ 
   LLPtr previousPtr = NULL; // pointer to previous node in list
   LLPtr currentPtr = NULL; // pointer to current node in list
   LLPtr tempPtr = NULL; // temporary node pointer

   // delete first node
   if ( value == ( *sPtr )->ID ) { 
      tempPtr = *sPtr; // hold onto node being removed
      *sPtr = ( *sPtr )->nextPtr; // de-thread the node
      if(*sPtr) (*sPtr)->pPtr = NULL; //set first previous node point to NULL
      free( tempPtr ); // free the de-threaded node
      return value;
   } // end if
   else { 
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && currentPtr->ID != value ) { 
         previousPtr = currentPtr; // walk to ...  
         currentPtr = currentPtr->nextPtr; // ... next node  
      } // end while
      
      // delete node at currentPtr
      if ( currentPtr != NULL && currentPtr->nextPtr != NULL ) { 
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         currentPtr->nextPtr->pPtr = previousPtr; //connect pPtr node next current to previous node;
         free( tempPtr );
         return value;
      } // end if
      else if(currentPtr != NULL && currentPtr->nextPtr == NULL)
      {
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         return value;
      }
   } // end else

   return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
int isEmpty( LLPtr sPtr )
{ 
   return sPtr == NULL;
} // end function isEmpty

// print the list
void printList( LLPtr currentPtr )
{ 
   // if list is empty
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   } // end if
   else { 
      puts( "The list is:" );

      // while not the end of the list
      while ( currentPtr != NULL ) { 
         printf( "ID:%d_Score:%d --> ", currentPtr->ID,currentPtr->score );
         currentPtr = currentPtr->nextPtr;   
      } // end while

      puts( "NULL\n" );
   } // end else
} // end function printList

void printReverse( LLPtr currentPtr )
{
    LLPtr previousPtr = NULL;
    if ( isEmpty( currentPtr ) ) {
   } // end if
   else { 
      puts( "The list is:" );

      // move current to end of list
      while ( currentPtr != NULL ) { 
         previousPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;   
      } // end while
      currentPtr = previousPtr;
      //print form end of list to start using pPtr and currentPtr
      while ( currentPtr != NULL ) { 
         printf( "ID:%d_Score:%d --> ", currentPtr->ID,currentPtr->score );
         currentPtr = currentPtr->pPtr;   
      } // end while
      puts( "NULL\n" );
   } // end else

      
      
}
