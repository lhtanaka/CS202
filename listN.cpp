// header files 
#include <iostream>
#include <cstdlib>
#include "listN.h"

using namespace std;

// node based list implementation

// class node
Node::Node(char a, Node* nptr ) //DO I NEED TO HAVE A DECLARATION OF NEW MEM?
 {
   data = a;
   nptr = NULL;
 }

ostream& operator<<(ostream& output, const List& a );

// class List
List::List( int a )  
 {
   head = NULL;  
   cursor = NULL;  
 }

List::List(const List& a )
 {
   Node* tempA;
   Node* tempNew;

   head = new Node( a.head->data, NULL );
   tempA = a.head->next;
   cursor = head;

   if( a.head->next != NULL )        // head node
    {
      cursor = new Node( tempA->data, NULL );
      head->next = cursor;
      tempNew = cursor;
      tempA = tempA->next;
    }

   while( tempA->next != NULL )
    {
      cursor = new Node( tempA->data, NULL );

      tempNew->next = cursor;
      tempNew = cursor;
      tempA = tempA->next;
    }
 }

List::~List()
 {
   if( head == NULL )
     delete head;

   else
    {
      while( head->next != NULL )
       {
         cursor = head->next;
         delete head;
         head = cursor;
       }
      delete head;
    }
   cursor = head = NULL;
 }

bool List::gotoBeginning()
 {
   bool isGood = false;

   if( !empty() )
    {
      cursor = head;
      isGood = true;
    }

   return isGood;
 }

bool List::gotoEnd()
 {
   bool isGood = false;

   if( !empty() )
    {
      while( cursor->next != NULL )
       {
         cursor = cursor->next;
       }
      isGood = true;
    }
   return isGood;
 }

bool List::gotoNext()
 {
   bool isGood = false;

   if( !empty() && cursor->next != NULL )
    {
      cursor = cursor->next;
      isGood = true;
    }

   return isGood;
 }

bool List::gotoPrior()
 {
   bool isGood = false;
   Node* temp = head;

   if( !empty() && cursor->next != head->next )
    {
      while( temp->next != cursor )
       {
         temp = temp->next;
       }
      cursor = temp;
      isGood = true;
    }

   return isGood; 
 }

bool List::insertAfter( char a )
 {
   bool isGood = false;
   Node* temp;

   if( !full() )
    {
      if( head == NULL ) // if list empty
       {
         head = new Node( a, NULL );
         cursor = head;
       }

      else
       {
         if( cursor->next == NULL )
          {
            temp = new Node(a, NULL );
            cursor->next = temp;
            cursor = temp;
            temp = NULL;
          }

         else
          {
            temp = new Node( a, NULL );
            temp->next = cursor->next;
            cursor->next = temp;
            cursor = temp;
            temp = NULL;
          }
       }
      isGood = true;
    }

   return isGood;
 }

bool List::insertBefore( char a )
 {
   bool isGood = false;
   Node* temp;

   if( !empty() || !full() )
    {
      temp = new Node( cursor->data, cursor->next );
      cursor->next = temp;
      cursor->data = a;
      isGood = true;
      temp = NULL;
    }

   return isGood;
 }

bool List::remove(char& a )
 {
   bool isGood = false;
   Node* temp;

   if( !empty() )
    {
      a = cursor->data;
      temp = cursor->next;
      cursor->data = temp->data;
      cursor->next = temp->next;
      delete temp;
      isGood = true;
    }

   return isGood;
 }

bool List::replace(char a )
 {
   bool isGood = false;

   if( !empty() ) 
    {
      cursor->data = a;
      isGood = true;
    }

   return isGood;
 }

bool List::getCursor( char& a )const
 {
   bool isGood = false;

   if( !empty() )
    {
      a = cursor->data;
      isGood = true;
    }

   return isGood;
 }

bool List::empty()const
 {
   bool isEmpty = false;

   if( head == NULL )
    {
      isEmpty = true;
    }

   return isEmpty;
 }

bool List::full()const 
 {
   bool isFull = false;

   return isFull;
 }

bool List::clear()
 {
   bool isClear = false;

   if( !empty() )
    { 
      while( head != NULL )
       {
         cursor = head;
         head = head->next;
         delete cursor;
       }
      cursor = head = NULL;
      isClear = true;
    }

   return isClear;
 }

List& List::operator=(const List& a)
 {
   Node* temp = head;
   Node* temp2;
   Node* aTemp = a.head;

   while( aTemp != NULL )
    {
      if( empty() )
       {
         head = new Node( aTemp->data, NULL );
         temp = head;
         aTemp = aTemp->next;
       }

      else if( temp->next != NULL )
       {
         temp->data = aTemp->data;
         aTemp = aTemp->next;
         temp = temp->next;
       }

      else
       {
         temp2 = new Node( aTemp->data, NULL );
         temp->next = temp2;
         temp = temp->next;
         aTemp = aTemp->next;
       }

    }

   while( temp->next != NULL )
    {
      temp2 =temp; //= temp->next;
      temp = temp->next;
      delete temp2;
    }

   // set the cursor
   aTemp = a.head;
   cursor = head;

   while( aTemp != a.cursor )
    {
      aTemp = aTemp->next;
      cursor = cursor->next; 
    }

   return *this;
 }

ostream& operator<<(ostream& output, const List& a )
 {
   Node* temp = a.head;
   output << "[] indidcates cursor" << endl;

   while( temp != NULL )
    {
      if( temp == a.cursor )
       {
         output << '[' << temp->data << ']' << endl;
         temp = temp->next;
       }

      else
       {
         output << temp->data << endl;
         temp = temp->next;
       }
    }
   return output;
 }

bool List::operator==(const List& a )const
 {
   bool isGood = true, repeat = false;
   Node* aTemp = a.head;
   Node* temp = head;

   if( aTemp->data == temp->data )
     repeat = true;

   while( repeat )
    {
      if( aTemp->data != temp->data )
         return false;

      aTemp = aTemp->next;
      temp = temp->next;

      if( aTemp == NULL || temp == NULL )
         repeat = false;
    }
   if( aTemp != NULL && temp != NULL ) 
     isGood = false;

   return isGood;
 }


















