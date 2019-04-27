/***********************************************************************
* Program:
*    Week 11, Sorting
*    Brother Ercanbrack, CS 235
*
* Author:
*   Jordan Jarvis 
* Summary: 
* Sorts things in a merge style
************************************************************************/
#include <list>
   
using namespace std;

template <class T>
int split(list<T> & array, list<T> & data1, list<T> & data2);
template <class T>
void merge(list<T> & array, list<T> & data1, list<T> & data2);

/*************************************************************************
* This function sorts a linked list using a Natural Merge Sort.
* Input:  data -  linked list of data to be sorted.
* Output: data -  sorted linked list
**************************************************************************/
template<class T>
void mergeSort(list<T> &data)
{

   list<T> listA;
   list<T> listB;
   while (split(data, listA, listB) > 1)
      merge(data, listA, listB); 
}

/******************************************
 * takes one list and makes it 2
 ******************************************/
template <class T>
int split(list<T> & array, list<T> & data1, list<T> & data2)
{
   int numSublists = 1;
   list<int>::iterator item  = array.begin(); 
   list<T> *list1 = &data1;   
   list<T> *list2 = &data2; 

   data1.clear();
   data2.clear();

   list1->push_back(*item);
   item++;

   for (; item != array.end(); item++)
   {
      if (*item < list1->back())
      {
         numSublists++; 

         list2->push_back(*item);

         if (list1 == &data1)
         {
            list1 = &data2;
            list2 = &data1;
         }
         else
         {
            list1 = &data1;
            list2 = &data2;
         }
      }
      else
      {
         list1->push_back(*item);
      }
   }
   return numSublists; 
}

/**************************************************
 * puts it back together
 **************************************************/
template <class T>
void merge(list<T> & array, list<T> & data1, list<T> & data2)
{

   array.clear();

   list<int>::iterator tempData1 = data1.begin();
   list<int>::iterator tempData2 = data2.begin(); 
   list<int>::iterator *tempData3 = &tempData1;     

   while (true) 
   {
      if (*tempData3 == data1.end() || *tempData3 == data2.end())
         break;
      if (*tempData1 < *tempData2)
         tempData3 = &tempData1;
      else
         tempData3 = &tempData2;
      array.push_back(**tempData3);
      (*tempData3)++;
   }
   list<T> *tempList;
   if (*tempData3 != tempData1)
      tempList = &data1;
   else
      tempList = &data2;

   list<int>::iterator *leftOvers = (tempData1 != data1.end() ? &tempData1 : &tempData2 );
   for (; *leftOvers != tempList->end(); (*leftOvers)++)
      array.push_back(**leftOvers);
}