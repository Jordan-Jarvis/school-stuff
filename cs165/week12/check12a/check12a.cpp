/*********************
 * File: check12a.cpp
 *********************/

#include <iostream>
using namespace std;

#include "money.h"

/****************************************************************
 * Function: main
 * Purpose: Test the money class and practice operators
 ****************************************************************/
int main()
{
   Money account1;
   Money account2;

   // Get the input from the user
   account1.prompt();
   account2.prompt();
   cout << endl;
   cout << "The values are: "; 
   (cout << account1) << " and " << account2 << endl;
   // Display the values here using the << operator.
   // DO NOT just use the display function: account1.display();
   // Make sure to use something like: cout << account1;
   


   cout << endl;
   cout << "Using the == operator, they are:\n";

   // Fill in this if statement by changing to to use your == operator.
   // In other words, remove the word "true" and instead use something like: account1 == account2
   if (true)
   {
      cout << "Equal\n";
   }
   else
   {
      cout << "Not Equal\n";
   }


   cout << endl;
   cout << "Using the != operator, they are:\n";

   // Fill in this if statement by changing to to use your != operator.
   // In other words, remove the word "true" and instead use something like: account1 != account2
   if (true)
   {
      cout << "Not Equal\n";
   }
   else
   {
      cout << "Equal\n";
   }

   return 0;
}

