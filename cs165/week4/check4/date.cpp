/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/
using namespace std;
#include "date.h"
#include <iostream>
void Date :: set(int month, int day, int year)
{
   this->month = month;
   this->day = day;
   this->year = year;
   return;
}

void Date::displayAmerican()
{
   cout << this->month << "/" << this->day << "/" << this->year << endl;
   return;
}

void Date::displayEuropean()
{
   cout << this->day << "/" << this->month << "/" << this->year << endl;
   return;
}

void Date::displayISO()
{
   cout << this->year << "-" << this->month << "-" << this->day << endl;
   return;
}
// Put your method bodies here...
