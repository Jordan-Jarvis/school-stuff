/***********************************************************************
* Program:
*    Assignment 16, Tax Brackets
*    Sister Hansen, CS124
* Author:
*    your name
* Summary: 
*    This Program will calculate which tax bracket the user belongs 
*    to based on their income.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      I keep getting no scope errors. I figured it out though.
************************************************************************/

#include <iostream>
using namespace std;

/*****************************************************
 * calculate their tax bracket 
 * then assign the number to the bracket and return
 * to main.
 *****************************************************/
double computeTax(float income)
{
   double bracket;
   if (income < 15100)
      bracket = 10;
   else if (income < 61300)
      bracket = 15;
   else if (income < 123700)
      bracket = 25;
   else if (income < 188450)
      bracket = 28;
   else if (income < 336550)
      bracket = 33;
   else 
      bracket = 35;
   return bracket;
}

/**********************************************************************
 * Main will ask for income and then calculate 
 * the tax bracket for their income.
 ***********************************************************************/
int main()
{
   double income;

   // prompt user for income
   cout << "Income: ";
   cin  >> income;
   

   // give the user their tax %
   double bracket = computeTax(income);
   cout << "Your tax bracket is " << bracket << "%" << endl;


   return 0;
}
