/***********************************************************************
* Program:
*    Project 07, Calendar 
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program displays a calendar table for the given month number  
*    and year. 
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      I had a bit of trouble with the loop for computeOffset
*      it kept giving me the wrong type of count. So i had to get 
*      creative.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

   //prototypes
int getMonth(int month);
int getYear(int year);
int computeOffset(int year, int month);
int numDaysMonth(int year, int month);
int isLeapYear(int year);
void display(int year, int month, int numDays, int offset);


/**********************************************************************
 * This function will call all the functions needed to make a calendar
 * for any given month and year.
 ***********************************************************************/
int main()
{
    // initialize variables
   int numDays;
   int offset;
   int month;
   int year;

   // call functions
   month = getMonth(month);
   year = getYear(year);
   numDays = numDaysMonth(year, month);
   offset = computeOffset(year, month);
   display(year, month, numDays, offset);
   return 0;
}

/***********************************************************************
 * Gets the month number.
 **********************************************************************/
int getMonth(int month)
{
   cout << "Enter a month number: ";
   cin >> month;
   while ( month < 1 || month > 12) // error correction
   {
      cout << "Month must be between 1 and 12.\n"
           << "Enter a month number: ";
      cin >> month;
   }
   return month;
}

/***********************************************************************
 * Get the year
 **********************************************************************/
int getYear(int year)
{
   cout << "Enter year: ";
   cin >> year;

   while ( year < 1753)
   {
      cout << "Year must be 1753 or later.\n"
           << "Enter year: ";
      cin >> year;
   }
   return year;
}

/***********************************************************************
 * Computes offset based on the year and month by checking if it is a 
 * leap year and adding 2 to the offset instead of the typical 1 per
 * year, it then calculates the offset for the month and adds the two 
 * together returning offset mod 7 for 7 days
 **********************************************************************/
int computeOffset(int year, int month)
{
   int offset = 0;
   int count = year - 1;
   for ( int iYear = 1753; iYear <= count; iYear++)
   {
      offset = ( offset + isLeapYear(iYear) - 365);
      if (offset == 7)
         offset = 0;
      offset++;
   }
   
   for ( int iMonth = 1; iMonth < month; iMonth++)
      offset = ( offset + numDaysMonth(year, iMonth));
   
   return offset % 7;
}

/***********************************************************************
 * Calculates the number of days in the given month.
 **********************************************************************/
int numDaysMonth(int year, int month)
{
   int daysMonth; // sets variable to amount of days in given month

   if ( month == 1)
      daysMonth = 31;
   else if ( month == 2)
   {
      if (isLeapYear(year) == 366) // check for leap year
         daysMonth = 29;
      else
         daysMonth = 28;
   }
   else if ( month == 3)
      daysMonth = 31;
   else if ( month == 4)
      daysMonth = 30;
   else if ( month == 5)
      daysMonth = 31;
   else if ( month == 6)
      daysMonth = 30;
   else if ( month == 7)
      daysMonth = 31;
   else if ( month == 8)
      daysMonth = 31;
   else if ( month == 9)
      daysMonth = 30;
   else if ( month == 10)
      daysMonth = 31;
   else if ( month == 11)
      daysMonth = 30;
   else if ( month == 12)
      daysMonth = 31;

   return daysMonth;
}

/***********************************************************************
 * Determines if given year is a leap year.
 **********************************************************************/
int isLeapYear(int year)
{
   if ( year % 4 != 0)  // checks for leap year using math
      return 365;
   if (year % 100 != 0)
      return 366;
   if (year % 400 == 0)
      return 366;
      
   return 365;
}

/***********************************************************************
 * Displays the calendar table.
 **********************************************************************/
void display(int year, int month, int numDays, int offset)
{
   int dayOfWeek = 0;  // initialize variables needed.
   cout << endl;
   if ( month == 1)
      cout << "January";  // display the proper month
   else if ( month == 2)
      cout << "February";
   else if ( month == 3)
      cout << "March";
   else if ( month == 4)
      cout << "April";
   else if ( month == 5)
      cout << "May";
   else if ( month == 6)
      cout << "June";
   else if ( month == 7)
      cout << "July";
   else if ( month == 8)
      cout << "August";
   else if ( month == 9)
      cout << "September";
   else if ( month == 10)
      cout << "October";
   else if ( month == 11)
      cout << "November";
   else if ( month == 12)
      cout << "December";

   cout << ", " << year << "\n";
   // Display month header
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   // Set variables
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