/***********************************************************************
* Program:
*    Assignment 32, Strings
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program counts the number of a given letter in a string
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      It was not too bad.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * This function asks for a letter and a string, then counts the number
 * of the letter specified in the string.
 ***********************************************************************/
void countLetters()
{
   char check;
   char string[256];
   cout << "Enter a letter: ";
   cin >> check;
   int count = 0;
   cout << "Enter text: ";
   cin.ignore();
   cin.getline(string, 256);
   
   for ( int i = 0; string[i] != '\0'; ++i)
   {
      if ( check == string[i])
         ++count;
   }
   cout << "Number of '" << check <<  "'s: " << count << endl;
}

/**********************************************************************
 * main will call countLetters.
 ***********************************************************************/
int main()
{
   countLetters();
}