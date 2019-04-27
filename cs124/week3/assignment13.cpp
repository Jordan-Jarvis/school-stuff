/***********************************************************************
* Program:
*    Assignment 13, temperature conversion
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary:
*    This program converts Fahrenheit to Celsius
*
*    Estimated:  1.0 hrs
*    Actual:     0.8 hrs
*      Please describe briefly what was the most difficult part.
*      The hardest part was I kept getting -0 as the answer,
*      it took a while for me to figure out it was because
*      I didn't know I needed a * in there
*
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * This Program is designed to convert Celsius to Fahrenheit 
 * It works using simple math functions.
 ***********************************************************************/
int main()

{
   cout.setf(ios::fixed);
   cout.precision(0);
   int F;
   float C;
   cout << "Please enter Fahrenheit degrees: ";
   cin >> F;
   C = (float)5 / 9 * ( F - 32 ) ; // Math for conversion
   cout << "Celsius: " << C << endl;
   return 0;
}


