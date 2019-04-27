/***********************************************************************
* Program:
*    Checkpoint 01b, review   (e.g. Checkpoint 01a, review)           
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>

using namespace std;

/**********************************************************************
 * Function: getSize
 * Purpose: get the size of the list
 ***********************************************************************/
int getSize()
{
   int size = 0;
   cout << "Enter the size of the list: ";
   cin >> size;
   return size;
}

/**********************************************************************
 * Function: getList
 * Purpose: insert data int the array list
 ***********************************************************************/
void getList(int array[], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << "Enter number for index " << i << ": ";
      cin >> array[i];
   }
}

/**********************************************************************
 * Function: displayMultiples
 * Purpose: show the multiples of 3 in the array.
 ***********************************************************************/
void displayMultiples(int array[], int size)
{
   cout << "\nThe following are divisible by 3:\n";
   for (int i = 0; i < size; i++)
   {
      if (array[i] % 3 == 0)
      {
         cout << array[i] << endl;
      }
   }
}

/**********************************************************************
 * Function: main
 * Purpose: call other functions to do all the work.
 ***********************************************************************/
int main()
{
   int size = 0;
   size = getSize();
   int array[size];
   getList(array, size);
   displayMultiples(array, size);
   return 0;
}
