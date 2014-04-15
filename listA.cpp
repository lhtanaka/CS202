// header files
#include <iostream>
#include <cstdlib>
#include "listA.h"

using namespace std;

// array based list implementation
List::List( int a )
 {
   data = new char[a];
   size = a;
   actual = 0;
   cursor = -1;
 }

List::List( const List& a )
 {
   data = new char[a.size];
   size = a.size;
   actual = a.actual;
   cursor = a.cursor;
   for( int i = 0; i < actual; i++ )
    {
      data[i] = a.data[i];
    }
 }

List::~List()
 {
   delete[]data;
   data = NULL;
   size = 0;
   actual = 0;
   cursor = -1;
 }

bool List::gotoBeginning()
 {
   bool isGood = false;

   if( !empty() )
    {
      cursor = 0;
      isGood = true;
    }

   return isGood;
 }

bool List::gotoEnd()
 {
   bool isGood = false;

   if( !empty() )
    {
      cursor = actual - 1;
      isGood = true;
    }

   return isGood;
 }

bool List::gotoNext()
 {
   bool isGood = false;

   if( !empty() && cursor != size - 1 )
    {
      cursor++;
      isGood = true;
    }
   return isGood;
 }

bool List::gotoPrior()
 {
   bool isGood = false;

   if( !empty() && cursor != 0 )
    {
      cursor--;
      isGood = true;
    }

   return isGood;
 }

bool List::insertAfter( char a )
 {
   bool isGood = false;
   int shuf = actual-1;

   if( !full() )
    {
      if( empty() )
       {
         data[0] = a;
         actual++;
         cursor++;
         isGood = true;
       }

      else if( actual == cursor +1 )
       {
         cursor++;
         data[cursor] = a;
         actual++;
         isGood = true;
       }
      else
       {
         for( int i = 0; i < actual - cursor - 1; i++ )
          {
            data[shuf] = data[shuf-1];
            shuf--;            
          }
         cursor++;
         data[cursor] = a;
         actual++;
         isGood = true;
       }
    }

   return isGood;
 }

bool List::insertBefore( char a )
 {
   bool isGood = false;
   int shuf = actual-1;

   if( !empty() && !full() )
    {
      for( int i = 0; i < actual - cursor; i++ )
       {
         data[shuf] = data[shuf-1];
         shuf--;
       }

      data[cursor] = a;
      actual++;

      isGood = true;
    }

   return isGood;
 }

bool List::remove( char& a) 
 {
   bool isGood = false;
   int shuf = cursor;

   if( !empty() )
    {
      a = data[cursor];

      for( int i = 0; i < actual - cursor - 1; i++ )
       {
         data[shuf] = data[shuf+1];
         shuf++;
       }

      actual--;
      isGood = true;
    }

   return isGood;
 }

bool List::replace( char a )
 {
   bool isGood = false;

   if( !empty() )
    {
      data[cursor] = a;
      isGood = true;
    }

   return isGood;
 }

bool List::getCursor(char& a )const
 {
   bool isGood = false;

   if( !empty() )
    {
      a = data[cursor];
      isGood = true;
    }

   return isGood;
 }

bool List::empty()const
 {
   bool isEmpty = false;

   if( cursor == -1 && actual == 0 )
    {
      isEmpty = true;
    }

   return isEmpty;
 }

bool List::full()const
 {
   bool isFull = false;

   if( actual == size )
     isFull = true;

   return isFull;
 }

bool List::clear()
 {
   bool isClear = false;

   if( cursor != -1 && actual != 0 )
    {
      cursor = -1;
      actual = 0;
      isClear = true;
    }

   return isClear;
 }

List& List::operator=(const List& a )
 {
   if( size == a.size )
    {
      actual = a.actual;
      cursor = a.cursor;
      for( int i = 0; i < actual; i++ )
       {
         data[i] = a.data[i];
       }
    }

   else
    {
      delete[]data;
      data = new char[a.size];
      actual = a.actual;
      size = a.size;
      cursor = a.cursor;
      for( int i = 0; i < actual; i++ )
       {
         data[i] = a.data[i];
       }
    }
   return *this;
 }

ostream& operator<<(ostream& output, const List& a )
 {
   output << "[] indicates cursor" << endl;
   output << "size: " << a.size << endl << "actual: " << a.actual 
          << endl << "cursor: " << a.cursor << endl;
   for( int i = 0; i < a.actual; i++ )
    {
      if( i == a.cursor)
       output << '[' << a.data[i] << ']' << endl;

      else
       output << a.data[i] << endl;
    }

   return output;
 }

bool List::operator==(const List& a )const
 {
   bool isEqual = false, dataSame = false;

   if( actual == a.actual && size == a.size && cursor == a.cursor )
    {
      for( int i = 0; i < actual; i++ )
       {
         if( data[i] != a.data[i] )
          return false;
       }

      isEqual = true;
    }

   return isEqual;
 }

















