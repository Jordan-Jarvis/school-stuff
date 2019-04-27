/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program creates a memory reservation, fills it, then deletes 
*    the data in it.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      It was a lot easier than I thought it would be.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream> 
using namespace std;

/**********************************************************************
 * main will do all the work in this program, it will ask for required
 * info, then store it and return it, closing gracefully.
 ***********************************************************************/
int main()
{
   int numGrades;
   cout << "Number of characters: ";
   cin >> numGrades;
   numGrades++;
   char *string = new(nothrow) char[numGrades];
   if (NULL == string)
   {
      cout << "Allocation failure!\n";
      return 0; // in real life it would not be 0
   }
   
   cin.ignore();
   cout << "Enter Text: ";
   cin.getline(string, numGrades); // get the text entered
   
   cout << "Text: ";
   for (int count = 0; count < numGrades - 1; count++)
   {
      cout << string[count]; // display the text entered
   }

   cout << endl; // delete memory before closing
   delete [] string;
   string = NULL;
}
   