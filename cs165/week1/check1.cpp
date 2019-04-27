/***********************************************************************
* Program:
*    Checkpoint 01a, review   (e.g. Checkpoint 01a, review)           
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: ask user for name and age, then display it back to them.
 ***********************************************************************/
int main()
{
   string fName;
   int age = 0;  // init variables
   
   cout << "Hello CS 165 World!\n";
   cout << "Please enter your first name: ";
   cin >> fName;
   cout << "Please enter your age: ";  // display info requested
   cin >> age;
   cout << "\nHello " << fName << ", you are " << age << " years old.\n";
   return 0;
}
