/***********************************************************************
* Program:
*    Assignment 31, Arrays
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program gets 10 grades from the user, adds them to an array
*    then calculates the average grade and returns it .it also will
*    correct for negative scores.
************************************************************************/
#include <iostream>
using namespace std;

/**********************************************************************
 * Ask for the grades and add them to the array using a loop
 * ********************************************************************/
void getGrades (float tempArr[10])
{
   for (int i = 0; i < 10; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> tempArr[i];
   }
   return;
}

/**********************************************************************
 * Calculate the average grades from the array
 * ********************************************************************/
float avgGrades (float tempArr[10])
{
   float avg = 0;
   float total = 0;
   int i = 0;
   int minus = 0;
   for (i = 0; i < 10; i++)
   {
      if (tempArr[i] > -1)
         total += tempArr[i];
      else
         minus++; // modified to remove the negative numbers from calc
   }
   avg = total / (i - minus);

   return avg;
}

/**********************************************************************
 * Initialize the array and call functions that do all the work.
 * Then display output.
 * ********************************************************************/
int main ()
{
   float array1[10];
   getGrades (array1);
   int avg = avgGrades (array1);
   if (avg >= 0)
      cout << "Average Grade: " << avg << "%\n";
   else 
      cout << "Average Grade: ---%\n";
   return 0;
}


