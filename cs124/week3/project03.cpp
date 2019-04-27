/***********************************************************************
* Program:
*    Project 03, Monthly Budget          (e.g. Assignment 10, Hello World)
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary:
*    This program displays living expenses in a specified format.
*
*    Estimated:  2.0 hrs
*    Actual:     2.8 hrs
*      Please describe briefly what was the most difficult part.
*      The most difficult part was I kept getting scope not defined 
*      errors. I hated them and then realised why. it makes sense now.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;


/**********************************************************************
* Request income and set variable
***********************************************************************/
double getIncome()
{
   double income = 0; // set variables
   cout << "\tYour monthly income: ";
   cin >> income; //set variable to user input
   return income;
}

/**********************************************************************
* Request the budget living expenses
***********************************************************************/
double getBudgetLiving()  
{
   double budgetLiving = 0; // set variables
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving; //set variable to user input
   return budgetLiving;
}

/**********************************************************************
* Request actual Living expenses and set variable
***********************************************************************/
double getActualLiving()
{
   double actualLiving = 0; // set variables
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving; //set variable to user input
   return actualLiving; 
}

/**********************************************************************
* Request actual taxes and set variable
***********************************************************************/
double getActualTax()
{
   double actualTax = 0; // set variables
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTax; //set variable to user input
   return actualTax;   
}

/**********************************************************************
* Request actual tithing and set variable
***********************************************************************/
double getActualTithing()
{
   double actualTithing = 0; // set variables
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing; //set variable to user input
   return actualTithing; 
}

/**********************************************************************
* Request actual other income and set variable
***********************************************************************/
double getActualOther()
{
   double actualOther = 0; // set variables
   cout << "\tYour actual other expenses: ";
   cin >> actualOther; //set variable to user input
   return actualOther;
}

/**********************************************************************
* Computes tithing based on the income from above
***********************************************************************/
double computeTithing(double income)
{
   // Local Declarations
   double expectedTithing;
   expectedTithing = (income * 0.1);
   return expectedTithing;
}

/**********************************************************************
* Computes budget by subtracting income from expectedTithing and 
* budgetLiving
***********************************************************************/
double getBudgetOther(double income,double expectedTithing,double budgetLiving)
{
   double budgetOther;
   budgetOther = (income - (expectedTithing + budgetLiving));
   return budgetOther;
}

/**********************************************************************
* subtracts Tithing living tax and other expenses from 
* income and sets it as a variable
***********************************************************************/
double getDifferenceActual(
   double income, double actualTithing,
   double actualLiving, double actualTax, 
   double actualOther)
{
   double differenceActual;
   differenceActual = income - actualLiving - 
      actualTithing - actualTax - actualOther;
   return differenceActual;
}

/**********************************************************************
* Displays results that were requested by main and 
* performed/calculated by everything else.
***********************************************************************/
void display(double income, double actualLiving, double budgetedLiving,
      double actualTax, double actualTithing, double expectedTithing,
      double actualOther, double budgetOther, double differenceActual)
{
   cout << endl; //the following is display formatting with variables
   cout << "The following is a report on your monthly expenses\n";
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
      << actualTax << endl;
      
   cout << "\tTithing" << setw(10) 
      << "$" << setw(11) 
      << expectedTithing << setw(5) 
      << "$" << setw(11) 
      << actualTithing   << endl;
      
   cout << "\tLiving" << setw(11) 
      << "$" << setw(11)
      << budgetedLiving << setw(5) 
      <<  "$" << setw(11) 
      << actualLiving  << endl;
      
   cout << "\tOther" << setw(12)
      << "$" << setw(11)
      << budgetOther  << setw(5) 
      << "$" << setw(11) 
      << actualOther << endl;
      
   cout << "\t===============" << setw(16)  
      << "==============="  << setw(16) 
      << "==============="  << endl;
      
   cout << "\tDifference" << setw(7) 
      << "$" << setw(11)
      << 0.00  << setw(5) 
      << "$" << setw(11) 
      << differenceActual << endl;
   return;
}

/**********************************************************************
* Main will call each of the functions and set variables for 
* display to output to the screen
***********************************************************************/
int main()
{
    // configure the output to display money
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(2);         // two decimals for cents
   
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   double income = getIncome();
   double budgetLiving = getBudgetLiving();
   double actualLiving = getActualLiving();
   double actualTax = getActualTax();
   double actualTithing = getActualTithing();
   double actualOther = getActualOther();
   double expectedTithing = computeTithing(income);
   double budgetOther = getBudgetOther(income,expectedTithing,budgetLiving);
   double differenceActual = getDifferenceActual( 
      income, actualTithing, actualLiving, actualTax, actualOther);
   display(income, actualLiving, budgetLiving, actualTax, 
      actualTithing, expectedTithing, actualOther, 
      budgetOther, differenceActual);
   return 0;
}
//end main

