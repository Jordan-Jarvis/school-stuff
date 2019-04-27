/***********************************************************************
* Program:
*    Test 3, reverse file
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program reverses a set of numbers in a file.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      I didn't have many issues with it. I think it makes sense. 
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream> 
using namespace std;

/*****************************************************
 * This function gets the name of the file and
 * stores it.
 *****************************************************/
void getFileName(char fileName[])
{
   cout << "Enter the filename: ";
   cin >> fileName;
}

/*****************************************************
 * This function reads the file and stores it as an
 * array
 *****************************************************/
int readFile(char fileName[],float numbers[])
{
   int numData = 0;
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error opening file " << fileName << endl;
      return 0;    // error checking
   }
   while (fin >> numbers[numData] && numData < 100)
      numData++;
   fin.close();

   return numData;
}

/*****************************************************
 * This function shows the output in reverse order
 * using a for loop to go through the array backwards
 *****************************************************/
void display(float numbers[], int numData)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "New order:\n";
   for (int i = numData - 1; i < numData && i >= 0; i--)
   {
      cout << numbers[i] << endl;
   }
   return;
}

/*****************************************************
 * main calls other functions and sets the arrays and
 * variables, it also checks for certain errors.
 *****************************************************/
int main()
{
   char fileName[256];
   float numbers[100];
   getFileName(fileName);
   int numData = readFile(fileName, numbers);
   if (numData == 0)
   {
      return 0;
   }
   display(numbers, numData);
   return 0;
}
