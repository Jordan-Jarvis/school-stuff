/***********************************************************************
* Program:
*    Assignment 11, Monthly Budget          (e.g. Assignment 10, Hello World)
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary:
*    This program displays living expenses in a specified format.
*
*    Estimated:  1.0 hrs
*    Actual:     0.8 hrs
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

   // display the columns of item number and other formatting
   cout << "\tItem" << setw(20)  << "Projected"     << endl;
   cout << "\t=============" << setw(12)  << "=========="     << endl;
   cout << "\tIncome" << setw(10) << "$" << setw(9) << 1000.00     << endl;
   cout << "\tTaxes" << setw(11) << "$" << setw(9) << 100.00     << endl;
   cout << "\tTithing" << setw(9) << "$" << setw(9) << 100.00     << endl;
   cout << "\tLiving" << setw(10) << "$" << setw(9) << 650.00     << endl;
   cout << "\tOther" << setw(11) << "$" << setw(9) << 90.00     << endl;
   cout << "\t=============" << setw(12)  << "=========="     << endl;
   cout << "\tDelta" << setw(11) << "$" << setw(9) << 60.00     << endl;
   return 0;
}

