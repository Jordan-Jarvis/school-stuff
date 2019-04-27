/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy       
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Enter a brief description of your program here!  
*    This program compares the DNA of the user with a few relatives,
*    then returns a percent match between the two.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      I forgot how to use pointers, so I had to look it up.
************************************************************************/
#include <iostream>
#include <string.h>
using namespace std;

/**********************************************************************
 * Function: getUserInfo
 * Purpose: prompts user for information the program will use later to
 * compare data.
 ***********************************************************************/
int getUserInfo(string& userDna)
{
   int numRelatives = 0;
   cout << "Enter your DNA sequence: ";
   cin >> userDna;
   cout << "Enter the number of potential relatives: ";
   cin >> numRelatives;
   cout << endl;
   return numRelatives;
}

/**********************************************************************
 * Function: getSequences
 * Purpose: prompts user for others DNA sequence and stores it for
 * future comparison.
 ***********************************************************************/
void getSequences(string relativeDna[], 
   int numRelatives, string relativeNames[])
{
   for (int i = 0; i < numRelatives; i++)
   {
      cout << "Please enter the name of relative #" << i + 1 << ": ";
      cin >> relativeNames[i];
   }
   cout << endl;
   for (int i = 0; i < numRelatives; i++)
   {
      cout << "Please enter the DNA sequence for " 
         << relativeNames[i] << ": ";
     
      cin >> relativeDna[i];
   }
}

/**********************************************************************
 * Function: calculateMatch
 * Purpose: Compares sequences from user to their relatives DNA and
 * displays a percent match based on the comparison.
 ***********************************************************************/
void calculateMatch(string relativeDna[],
   int numRelatives, string relativeNames[],
   string userDna)
{
   cout << endl;
   for (int i = 0; i < numRelatives; i++)
   {
      int count = 0;
      for ( int j = 0; j < 10; j++)
      {
         if (userDna[j] == relativeDna[i][j])
         {
            count++;
         }
      }
      cout << "Percent match for " << relativeNames[i] 
         << ": " << count * 10 << "%\n";
   }
}

/**********************************************************************
 * Function: main
 * Purpose: calls all other functions and holds variables.
 ***********************************************************************/
int main()
{
   int numRelatives = 0;
   string userDna;
   
   numRelatives = getUserInfo(userDna);
   string relativeDna[numRelatives];
   string relativeNames[numRelatives];
   
   getSequences(relativeDna, numRelatives, relativeNames);
   calculateMatch(relativeDna, numRelatives, relativeNames, userDna);
   return 0;
}
