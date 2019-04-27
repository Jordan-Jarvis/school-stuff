/***************************************************************
 * File: assign04.cpp
 * Author: Jordan Jarvis
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
#include "product.h"
#include <iomanip>
using namespace std;

/**********************************************************************
 * this function drives the program
 ***********************************************************************/
int main()
{
   Product product;
   string productName;
   float basePrice;
   float weight;
   string description;
   
   product.prompt();


   cout << endl;
   cout << "Choose from the following options:\n";
   cout << "1 - Advertising profile\n";
   cout << "2 - Inventory line item\n";
   cout << "3 - Receipt\n";
   cout << endl;
   cout << "Enter the option that you would like displayed: ";

   int choice;
   cin >> choice;
   cout << endl;

   if (choice == 1)
   {
      product.advertisingProfile();
   }
   else if (choice == 2)
   {
      product.inventoryLineItem();
   }
   else
   {
      product.reciept();
   }
   return 0;
}
