/***********************************************************************
 * Module:
 *    Week 09, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 *     Edited by Jordan Jarvis
 * Summary:
 *    This program will implement the Binary Tree Sort
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"

/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
   //a BST to be used for sorting
   BST<T> sortThis;

   //inserts everyting into the tree, insert function handles the sorting
   for (int i = 0; i < num; i++)
      sortThis.insert(array[i]);
   //reset i
   int i = 0;
   for (BSTIterator<T> temp =  sortThis.begin(); temp != sortThis.end(); temp++, i++)
      array[i] = *temp;
   return;
}


#endif // SORT_BINARY_H
