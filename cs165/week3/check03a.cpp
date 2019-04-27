/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/***********************************
 * prompt
 * asks user for a number and checks for errors in the number
 **********************************/
int prompt()
{
   int number = 0;
   cout << "Enter a number: ";
   cin >> number;
   if (number < 0) 
      throw string ("The number cannot be negative.");
   if (number > 100)
      throw string ("The number cannot be greater than 100.");
   if (number % 2)
      throw string ("The number cannot be odd.");
   return number;
}

/***********************************
 * Main
 * displays the number or error associated with the number entered
 **********************************/
int main()
{
   int number = 0;
   try
   {
      number = prompt();
      cout << "The number is " << number  << "." << endl;
   }
   catch (const string message)
   {
      cout << "Error: " << message << endl;
   }
   return 0;
}