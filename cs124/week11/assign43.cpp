/***********************************************************************
* Program:
*    Assignment 43, command line args
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program will show an example of command line args.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      not too bad.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <cmath>
#include <cstdlib>

using namespace std;


/********************************************
 * Main will take command args and use them to calculate.
 ********************************************/
int main(int argc, char **argv)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(1);     
   for (int count = 1; count < argc; count++)
   {
       
      float num = atof(argv[count]);
      if (num < 0)
         num = -num;
      float conversion = num * 0.3048;
      cout << num << " feet is " << conversion << " meters\n";
   }
  

   return 0;
}


