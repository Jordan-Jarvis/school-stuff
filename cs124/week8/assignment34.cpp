/***********************************************************************
* Program:
*    Assignment 34, pointers
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program counts the number of a given letter in a string
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      It was not too bad. I think the project will be more
*      of a challenge though.
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
   
   for ( char *pString = string; *pString; pString++)
   {
      if ( check == *pString)
         count++;
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