/****************************
 * File: icecream.h
 ****************************/
#ifndef ICECREAM_H
#define ICECREAM_H

#include <string>

class IceCream
{
private:
   std::string flavor;


public:
   float taxes;
   float price;
   IceCream();
   IceCream(std::string flavor, float price);

   float getTax() const;
   void setTax(float tax) ;
   float getTotalPrice() const;
   void prompt();
   void display() const;

};


#endif
