/***********************************************************************
* Program:
*    Assignment 12, Input and Variables          
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary:
*    This program asks for monthly income and then tells you what your
*    monthly income is.
*
*    Estimated:  1.0 hrs
*    Actual:     0.5 hrs
*      Please describe briefly what was the most difficult part.
*      The formatting was the hardest part. also, i am not a fan
*      Of setw, it is wonky.
************************************************************************/

#include <iostream>    // required for COUT
#include <iomanip>     // we will use setw() in this example
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()

{
    // configure the output to display money
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(2);         // two decimals for cents
   
   float income;
   cout << "\tYour monthly income: "; 
   cin >> income; // ask for income and set it as variable

   cout << "Your income is: " // Output the "income" variable with formatting
      << setw(1) << "$" 
      << setw(9) << income 
      << endl;

   return 0;
}

