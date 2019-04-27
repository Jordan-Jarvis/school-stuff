/****************************
 * File: salesTax.h
 ****************************/
#ifndef SALESTAX_H
#define SALESTAX_H

#include <string>

class SalesTax
{
private:


public:
float taxes;
void setTax(float tax);
float getTax() const;
SalesTax()
{
   taxes = 0.06;
}
SalesTax(float tax)
{
   taxes = tax;
}
float addTax(float price, float tax) const;
};


#endif
