/***********************************************************************
* Program:
*    Assignment 26, Files
*    Sister Hansen, CS124
* Author:
*    Jordan Jarvis
* Summary: 
*    This program gets numbers from a file and divides it by 10 
*    and display it is a grade average rounded to the nearest 
*    whole number.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      This took WAY longer than it should have.
*      There is a lot of stuff that is not in the book that was 
*      not well explained.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*****************************************************
 * This function gets the file name and sets it as a 
 * variable.
 *****************************************************/
void getFileName (char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
}

/*****************************************************
 * This function gets the file name and opens the file
 * then pulls the data and calculates the outcome
 *****************************************************/
int readFile(char fileName[])
{
   ifstream fin(fileName); // open the file
   if (fin.fail())
   {
      return -1;
   }
   
   float avg = 0; // set variables
   float data = 1;    
   int count = 0; 
   float test;

   while (fin >> data) 
   {
      avg = data + avg;      // do the work 
      count++;
   } 
   
   if (count != 10) // make sure it uses exactly 10
      return -1;
   else 
      test = avg / 10 + .5; // +.5 to properly round
   fin.close();    
   return test;
}

/*****************************************************
 * Display will show the grade. 
 *****************************************************/
void display (float avg)
{
   cout.setf(ios::fixed);
   cout.precision(0);
   cout << "Average Grade: " << avg << "%" << endl;
}

/*****************************************************
 * Main will get file name, read the file, then send 
 * the average to the display
 *****************************************************/
int main ()
{
   cout.precision(0);
   char fileName[256];
   getFileName(fileName);
   float avg = readFile(fileName);
   
   if (avg != -1)
      display(avg);
   
   else       // error correction
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;;
   }
   
   return 0;
}
