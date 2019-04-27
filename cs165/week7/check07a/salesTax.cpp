/***********************************
 * File: salesTax.cpp
 ***********************************/


#include <iostream>
#include <string>
#include <iomanip>
#include "salesTax.h"
using namespace std;

/***********************************
 * Constructors
 ***********************************/


/**********************************************************************
 * Function: IceCream::display
 * Purpose: Displays the current ice cream.
 **********************************************************************/
float SalesTax::addTax(float price, float taxes) const
{
   return price * taxes;
}
void SalesTax::setTax(float tax) 
{
   taxes = tax;
}
float SalesTax::getTax() const
{
   return taxes;
}
