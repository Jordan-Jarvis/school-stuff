/***********************************************************************
* Program:
*    Week 11, Sorting
*    Brother Ercanbrack, CS 235
* Author:
*   Jordan Jarvis
************************************************************************/

#include <iostream> // for CIN and COUT
#include <cstring>  // for strcmp
#include <iomanip>  // for SETW
#include <fstream>  // for file builder
#include <vector>   // for vector
#include "heap.h"
#include "merge.h"

using namespace std;

/**********************************************************************
 * MAIN
 * Gets the sort type and filename from the command line. If the sort type
 * or filename are not entered on the command line, the user will be
 * prompted for the sort type and/or filename.
 * Call the appropriate sort to sort the data contained in the vector or
 * linked list and display the sorted data to the console.
 ***********************************************************************/
int main(int argc, const char *argv[])
{
   char sortType[10];
   char fileName[50];
   if (argc == 1)
   {
      cout << "Which sort merge or heap? ";
      cin >> sortType;
      cout << "Enter name of file to sort: ";
      cin >> fileName;
   }
   else if (argc == 2)
   {
      strcpy(sortType, argv[1]);
      cout << "Enter name of file to sort: ";
      cin >> fileName;
   }
   else if (argc == 3)
   {
      strcpy(sortType, argv[1]);
      strcpy(fileName, argv[2]);
   }

   if (strcmp(sortType, "heap") == 0)
   {
      ifstream fin;
      fin.open(fileName);
      if (!fin)
      {
         cout << "Unable to open file";
         return 1; 
      }
      int temp;
      vector<int> vints;
      vints.push_back(00);

      while (fin >> temp)
      {
         vints.push_back(temp);
      }
      fin.close();
      heapSort(vints);

      for (int i = 1; i < vints.size(); ++i)
      {
         cout << setw(3) << vints[i];
         if (i % 10 == 0)
            cout << endl;
      }
   }
   else if (strcmp(sortType, "merge") == 0)
   {

      ifstream fin;
      fin.open(fileName);
      if (!fin)
      {
         cout << "Unable to open file";
         return 1; 
      }

      int temp;
      list<int> myList;

      while (fin >> temp)
      {
         myList.push_back(temp);
      }
      fin.close();
      mergeSort(myList);

      int i = 1;
      for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it, ++i)
      {
         cout << setw(3) << *it;
         if (i % 10 == 0)
            cout << endl;
      }
   }
   else
   {
      cout << "\nInvalid sort name - must be 'heap' or 'merge'" << endl;
   }
   return 0;
}