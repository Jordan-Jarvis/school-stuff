/***********************************************************************
* Program:
*    Checkpoint 03b, Errors
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
   bool test = 0;
   do
   {
      cout << "Enter a number: ";
      cin >> number;
      if (cin.fail())
   {
      cout << "Invalid input.\n";
      cin.clear();
      number = 0;
      cin.ignore(256, '\n');

   }
   else 
      return number;
   }
   while(test == 0);
   return number;
}

/***********************************
 * Main
 * displays the number or error associated with the number entered
 **********************************/
int main()
{
   int number = 0;
   

      number = prompt();
      cout << "The number is " << number  << "." << endl;

   return 0;
}