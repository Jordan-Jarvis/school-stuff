/***********************************************************************
* Program:
*    Test 2, Interest rates
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    Calculate interest compounded yearly, given the amount starting
*    with, the number of years, and the interest rate.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Ask for the initial investment and return it as a variable
 * ********************************************************************/
double getInvestment()
{
   double startingInvestment;
   cout << "How much are you investing? ";
   cin >> startingInvestment;
   return startingInvestment;
}

/**********************************************************************
 * Ask for the number of years they are investing and return 
 * it as a variable.
 * ********************************************************************/
int getYears()
{
   int years;
   cout << "How long will this investment grow in years? ";
   cin >> years;
   return years;
}

/**********************************************************************
 * Ask for the interest rate and return it as a variable
 * ********************************************************************/
float getPercent()
{
   float percent;
   cout << "What is the interest rate in percent? ";
   cin >> percent;
   return percent;
}

/**********************************************************************
 * Calculate the amount of money after leaving the investment in for the
 * given time.
 * ********************************************************************/
double calcInvestment(double startInvestment, 
   double years, double percent) 
{
   float pFraction = percent / 100.0; 
      // convert the number into math form
   double investment = startInvestment;  
      // keep investment unchanged in case of re-use in the future
   for (int i = 1; i <= years; i++)
   {
      investment = investment + (investment * pFraction);  
      // every year the amount of interest is added
   }
   
   return investment;
}

/***********************************************************************
 * Display the final outcome, including the years and investment.
 ***********************************************************************/
void display(int years, double finalInvestment)
{
   cout << "At the end of " << years 
      << " years, you will have $" << finalInvestment << endl;
}

/***********************************************************************
 * set variables and call functions that do the work and return to main
 ***********************************************************************/
int main()
{

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   double startInvestment = 0;
   double finalInvestment = 0;
   double years = 0;
   double percent = 0;
   startInvestment = getInvestment();
   percent = getPercent();
   years = getYears();
   finalInvestment = calcInvestment(startInvestment, years, percent);
   display(years, finalInvestment);
   return 0;
}





