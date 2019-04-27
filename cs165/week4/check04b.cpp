/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;



int main()
{
   Date date;
   int day;
   int month;
   int year;
   cout << "Month: ";
   cin >> month;
   cout << "Day: ";
   cin >> day;
   cout << "Year: ";
   cin >> year;
   cout << endl;
   
   date.set(month, day, year);
   date.displayAmerican();
   date.displayEuropean();
   date.displayISO();
   // prompt for month, day, year
   
   // create a Date object
   
   // set its values
   
   // call each display function


   return 0;
}
