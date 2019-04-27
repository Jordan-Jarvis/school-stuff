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
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   cout << endl;
   
}

void getWords (char pWords[][32])
{
   cout << "\tPlural noun: ";
   cin >> pWords[0];
   cout << endl;
   cout << "\tPlural noun: ";
   cin >> pWords[1];
   cout << "\tType of liquid: ";
   cin >> pWords[2];
   cout << "\tAdjective: ";
   cin >> pWords[3];
   cout << "\tFunny noise: ";
   cin >> pWords[4];
   cout << "\tAnother funny noise: ";
   cin >> pWords[5];
   cout << "\tAdjective: ";
   cin >> pWords[6];
   cout << "\tAnimal: ";
   cin >> pWords[7];
   cout << "\tAnother animal: ";
   cin >> pWords[8];
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
   char data[32][80];
   fin.getline(*data, 80);
   cout << data;
   if (fin.fail())    
   {
      cout << "Unable to read name and age from "           
      << fileName 
      << endl;
      return false;    
   }    
 
   
 
   // close the stream    
   fin.close();    
 
    

 
 
}
/*****************************************************
 * Main will ask for number of days and offset 
 * and set the response to variables that will pass
 * into the function displayTable
 *****************************************************/
int main ()
{
   char words[256][32];
   char fileName[256];
   getFileName(fileName);
   int test = readFile(fileName);
   getWords( words);

   cout << test;
   cout << endl;
   
   return 0;
}
