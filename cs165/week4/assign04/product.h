/***************************************************************
 * File: product.h
 * Author: (your name here)
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <iomanip>
using namespace std;
class Product
{
   private:
      string productName;
      string description;
      float weight;
      float basePrice;
      float getSalesTax();
      float getShippingCost();
      float getTotalPrice();
   public:
      void prompt();
      void advertisingProfile();
      void inventoryLineItem();
      void reciept();
};

#endif
