/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/

using namespace std;
#include <vector>
#include <iostream>
#include <string>

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main() 

{
   vector<int> number;
   int notZero = 1;
   
   while (notZero != 0)
   {
      cout << "Enter int: ";
      cin >> notZero;
      if (notZero != 0)
         number.push_back(notZero);
   }
   cout << "Your list is:\n";
   for (vector <int> :: iterator it = number.begin();
      it != number.end(); it++)
      cout << *it << endl;
   cout << endl;
       number;
    notZero = 1;
   
   vector<string> strings;
   string word;
   bool quit = 0;
   while (quit == 0)
   {
      cout << "Enter string: ";
      cin >> word;
      if (word != "quit")
      {
         strings.push_back(word);
      }
      else
         quit = 1;
   }
   cout << "Your list is:\n";
   for (vector <string> :: iterator it = strings.begin();
      it != strings.end(); it++)
      cout << *it << endl;




   return 0;
}


