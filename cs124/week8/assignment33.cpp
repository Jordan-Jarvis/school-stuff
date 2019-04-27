/***********************************************************************
* Program:
*    Assignment 33, Pointers
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program calculates bank amounts after going on a date.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      It was not too bad, just had a hard time with creating 
*      functions. It didn't work when I tried to do so.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * This function asks for the date expenses and calculates their
 * bank account balance.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   float accountSue = 0;  // set variables
   float accountSam = 0;
   float priceDinner = 0;
   float priceMovie = 0;
   float priceIceCream = 0;
   float * pAccount = 0;
   
   cout << "What is Sam's balance? "; // get info needed
   cin >> accountSam;
   cout << "What is Sue's balance? ";
   cin >> accountSue;
   cout << "Cost of the date:" << endl;
   cout << "\tDinner:    ";
   cin >> priceDinner;
   cout << "\tMovie:     ";
   cin >> priceMovie;
   cout << "\tIce cream: ";
   cin >> priceIceCream; 
   
   if ( accountSam > accountSue ) // calculate balance
   {
      pAccount = &accountSam;
   }
   else
   { 
      pAccount = &accountSue;
   }

   *pAccount -= (priceDinner + priceMovie + priceIceCream);
   cout << "Sam's balance: " << "$" << accountSam << endl;
   cout << "Sue's balance: " << "$" << accountSue << endl;
}



