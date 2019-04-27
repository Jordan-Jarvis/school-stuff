/***********************************************************************
* Program:
*    Assignment 25, Calendar offset
*    Sister Hansen, CS124
* Author:
*    your name
* Summary: 
*    This Program will display a table that counts to whatever number 
*    you ask it to and display it as days of a month. It will also 
*    offset the starting point depending on the offset the user specifies
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      I tried the pseudo-code and couldn't get it to work, so I made
*      a few modifications to get it to calculate properly.
*      It took a lot longer than I thought it would.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*****************************************************
 * This function takes offset and number of days and 
 * then displays output for a standard month, with
 * the offset of the starting day.
 *****************************************************/
void displayTable ( int numDays, int offset )
{

   // Display month header
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   // Set variables
   int dayOfWeek = 0;
   // correct for blank first row
   if ( offset == 6 )
      offset = -1;
   // set offset to work from monday instead of sunday
   offset = ( offset + 1 );
   // loop rows until the program has counted all days
   // up to the number specified in numDays
   for ( int dayOfMonth = -offset; dayOfMonth <= numDays; dayOfMonth++ )
   {
      
      // loop for columns, allowing up to 7 
      // and displaying the day of the month
      if ( dayOfMonth > 0 )
         cout << setw (4) << dayOfMonth;
      
      // correct for offset being 0
      else if ( dayOfMonth == 0 );
      
      // add blank space if day of month is negative
      else
         cout << "    ";
      
      // add a day to the week before the loop starts over
      dayOfWeek++;
      
      // end the columns at 7 days
      if ( dayOfWeek == 8 )
      {
         cout << "\n";
         dayOfWeek = 1;
      }
   }
   // another way to assure columns are at 7 days
   if ( dayOfWeek >= 2 && dayOfWeek <= 7 )
      cout << "\n";
}

/*****************************************************
 * Main will ask for number of days and offset 
 * and set the response to variables that will pass
 * into the function displayTable
 *****************************************************/
int main ()
{
   int numDays;
   int offset;
   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;
   displayTable ( numDays, offset );
   return 0;
}
