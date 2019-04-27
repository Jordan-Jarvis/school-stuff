/***********************************************************************
* Program:
*    Assignment 21, empty functions
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This Program is a skeleton of a program to  
*    calculate cost of vehicle ownership
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      This was actually really easy, it compiled on my first try..
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*****************************************************
 * get devalue of vehicle
 *****************************************************/
double promptDevalue()
{
   return 0;
}

/*****************************************************
 * get insurance cost of vehicle
 *****************************************************/
double promptInsurance()
{
   return 0;
}

/*****************************************************
 * get parking cost of vehicle
 *****************************************************/
double promptParking()
{
   return 0;
}

/*****************************************************
 * will calculate the periodic cost of ownership
 *****************************************************/
double getPeriodicCost()
{
   double parking = promptParking();
   double insurance = promptInsurance();
   double devalue = promptDevalue();
   double cost = parking + insurance + devalue;
   return 0;
}

/*****************************************************
 * get mileage of vehicle
 *****************************************************/
double promptMileage()
{
   return 0;
}

/*****************************************************
 * get fuel cost of vehicle
 *****************************************************/
double promptGas()
{
   return 0;
}

/*****************************************************
 * get repair cost of vehicle
 *****************************************************/
double promptRepairs()
{
   return 0;
}

/*****************************************************
 * get tire cost of vehicle
 *****************************************************/
double promptTires()
{
   return 0;
}

/*****************************************************
 * get normal wear and tear cost of vehicle
 *****************************************************/
double getUsageCost()
{
   double mileage = promptMileage();
   double gas = promptGas();
   double repairs = promptRepairs();
   double tires = promptTires();
   return 0;
}

/*****************************************************
 * display output
 *****************************************************/
void display(double costUsage, double costPeriodic)
{
   cout << "Success\n";
}

/**********************************************************************
 * Main will call usage costs and periodic, then set variables
 ***********************************************************************/
int main()
{
   double costPeriodic = getPeriodicCost();
   double costUsage = getUsageCost();
   display(costUsage, costPeriodic);
   return 0;
}

