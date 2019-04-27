/***************************************************************
 * File: product.h
 * Author: (your name here)
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{
   private:


   public:
      Product()  
      {
         product = "none";
         description = "";
         basePrice= 0;
      }
      Product(string product, string description, float basePrice, float weight)
      {
         setName(product);
         setDescription(description);
         setBasePrice(basePrice);
         setWeight(weight);
      }
      string product;
      string description;
      float weight;
      float basePrice;
      
      string getName();
      void setName(string product);
      string getDescription();
      void setDescription(string description);
      float getBasePrice();
      void setBasePrice(float basePrice);
      float getWeight();
      void setWeight(float weight);
      void prompt();
      float getSalesTax();
      float getShippingCost();
      float getTotalPrice();
      void displayAdvertising();
      void displayInventory();
      void displayReceipt(); 
};

#endif
