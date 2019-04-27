/***********************************************************************
* Program:
*    Project 02, Monthly Budget          (e.g. Assignment 10, Hello World)
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
*      Of setw, it is wonky. Otherwise it was pretty easy.
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
   
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   float income; // set variables
   cout << "\tYour monthly income: "; 
   cin >> income; //set variable to user input
   float budgetedLiving;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetedLiving;
   float actualLiving;
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;
   float taxes;
   cout << "\tYour actual taxes withheld: ";
   cin >> taxes;
   float tithing;
   cout << "\tYour actual tithe offerings: ";
   cin >> tithing;
   float other;
   cout << "\tYour actual other expenses: ";
   cin >> other;
      
   cout << "\n";
   cout << "The following is a report on your monthly expenses\n";

   // display the columns of item number and other formatting
   cout << "\tItem" << setw(24)  
      << "Budget" << setw(16) 
      << "Actual"  << endl;
      
   cout << "\t===============" << setw(16)  
      << "==============="  << setw(16) 
      << "==============="  << endl;
      
   cout << "\tIncome" << setw(11) 
      << "$" << setw(11) 
      << income << setw(5) 
      << "$"  << setw(11) 
      << income  << endl;
      
   cout << "\tTaxes" << setw(12) 
      << "$" << setw(11)
      << 0.00  << setw(5) 
      << "$" << setw(11) 
      << taxes << endl;
      
   cout << "\tTithing" << setw(10) 
      << "$" << setw(11) 
      << 0.00 << setw(5) 
      << "$" << setw(11) 
      << tithing   << endl;
      
   cout << "\tLiving" << setw(11) 
      << "$" << setw(11)
      << budgetedLiving  << setw(5) 
      <<  "$" << setw(11) 
      << actualLiving  << endl;
      
   cout << "\tOther" << setw(12)
      << "$" << setw(11)
      << 0.00  << setw(5) 
      << "$" << setw(11) 
      << other << endl;
      
   cout << "\t===============" << setw(16)  
      << "==============="  << setw(16) 
      << "==============="  << endl;
      
   cout << "\tDifference" << setw(7) 
      << "$" << setw(11)
      << 0.00  << setw(5) 
      << "$" << setw(11) 
      << 0.00 << endl;
      
   return 0;
}

