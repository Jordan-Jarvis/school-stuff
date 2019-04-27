/***********************************************************************
* Program:
*    Assignment 25, Calendar offset
*    Sister Hansen, CS124
* Author:
*    your name
* Summary: 
*    This Program will display a table that counts to whatever number 
*    you ask it to and display it as days of a month. It will also 
*    offset the starting point depending on the offset the user specifies
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      I tried the pseudo-code and couldn't get it to work, so I made
*      a few modifications to get it to calculate properly.
*      It took a lot longer than I thought it would.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*****************************************************
 * This function takes offset and number of days and 
 * then displays output for a standard month, with
 * the offset of the starting day.
 *****************************************************/
void getFileName (char fileName[])
{
   cout << "Please enter filename: ";
   cin >> fileName;
   cout << endl;
   
}

float readFile(char fileName[])
{
   float number;
    // open the file    
    ifstream fin(fileName);      
    if (fin.fail())
    cout << "invalid file name";  
    return 0;                   // some error message 
    
   // read the data    
   int data; 

   int sum = 0;                  
   fin >> data;
   
      cout << data;
      sum = data+sum;                // do the work 
   int test = sum/10;
   
   if (fin.fail())    
   {
      cout << "Unable to read name and age from "           
      << fileName 
      << endl;
      return false;    
   }    
 
   
 
   // close the stream    
   fin.close();    
   return sum; 
    

 
 
}
/*****************************************************
 * Main will ask for number of days and offset 
 * and set the response to variables that will pass
 * into the function displayTable
 *****************************************************/
int main ()
{

   char fileName[256];
   getFileName(fileName);
   int test = readFile(fileName);
   cout << test;
   cout << endl;
   
   return 0;
}
