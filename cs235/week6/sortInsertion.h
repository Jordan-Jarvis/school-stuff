/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Jordan Jarvis
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   // the new one is the beginning of the array
   Node<T> * tempData = new Node<T>(array[0]);
   // for every item in the array
   for (int i = 1; i < num; i++)
   {
      Node<T> * lookBack = tempData;
      for (Node <T> * p = tempData; p; p = p->pNext)
      {
         if(array[i] < p->data)
         {
            if (p != tempData)
               insert(array[i], lookBack);
            else
               insert(array[i], tempData, true);

            break;
         }
         else
         {
            // if theres another item in the list
            if(p->pNext)
               lookBack = p;
            else
            {
               // if nothing is next
               insert(array[i],p);

               break;
            }
         }
      }
   }
   int j = 0;
   for (Node <T> * p = tempData; p; p = p->pNext, j++)
      array[j] = p->data;  
}

#endif // INSERTION_SORT_H

