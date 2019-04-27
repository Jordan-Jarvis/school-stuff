/***********************************************************************
* Header:
*    List
* Summary:
*    This class contains the notion of a List: or a list of objects
*
*    This will contain the class definition of:
*        List         : A class that works like a list
* Author
*    Jordan Jarvis
************************************************************************/

#include <iostream>
#ifndef BNODE_H
#define BNODE_H
using namespace std;

#include <cassert>

/***********************************************************************
 * BNODE CLASS
 * Cantainer of a binary node tree
 ***********************************************************************/
template <class T>
class BinaryNode
{
  public:
   // Constructors
   BinaryNode() : pLeft(NULL), pRight(NULL), pParent(NULL) {}
   BinaryNode(T item) : data(item), pLeft(NULL), pRight(NULL), pParent(NULL){}


   // function prototypes
   BinaryNode<T> * addLeft(T item) throw (const char *);
   BinaryNode<T> * addLeft(BinaryNode<T> * lhsChild) throw (const char *);
   BinaryNode<T> * addRight(T item) throw (const char *);
   BinaryNode<T> * addRight(BinaryNode<T> * rhsChild) throw (const char *);
   int size()
   {
      return 1 +
              (pLeft==NULL? 0 : pLeft->size()) +
              (pRight==NULL? 0 : pRight->size());
   }

   // whats inside
   T data;
   BinaryNode * pLeft;
   BinaryNode * pRight;
   BinaryNode * pParent;
};

/***********************************************************************
 * addLeft, adds to the left side of the node
 ***********************************************************************/
template <class T>
BinaryNode<T> * BinaryNode<T> :: addLeft(T item) throw (const char *)
{
   try
   {
      BinaryNode<T> *newNode = new BinaryNode(item);

      pLeft = newNode;
      newNode->pParent = this;
   }
   catch (...)
   {
      cout << "ERROR: Unbale to allocate a node";
   }

   return this;
}

/***********************************************************************
 * OVERLOAD addLeft, adds to the left side of the node
 ***********************************************************************/
template <class T>
BinaryNode<T> * BinaryNode<T>:: addLeft(BinaryNode<T> * lhsChild) throw (const char *)
{
   try
   {
      if(lhsChild != NULL)
      {
         lhsChild->pParent = this;
         pLeft = lhsChild;
      }
      else
      {
         pLeft = NULL;
      }
   }
   catch (...)
   {
      cout << "ERROR: Unbale to allocate a node";
   }

   return this;
}

/***********************************************************************
 * addRight adds to the right side of the passed in node
 ***********************************************************************/
template <class T>
BinaryNode<T> * BinaryNode<T> :: addRight(T item) throw (const char *)
{
   try
   {
      BinaryNode<T> *newNode = new BinaryNode(item);

      pRight = newNode;

      newNode->pParent = this;
   }
   catch(...)
   {
      cout << "ERROR: Unable to allocate a node";
   }

   return this;
}

/***********************************************************************
 * OVERLOAD addRight, adds to the right side of the passed in node
 ***********************************************************************/
template <class T>
BinaryNode<T> * BinaryNode<T>:: addRight(BinaryNode<T> * rhsChild) throw (const char *)
{
   try
   {
      if(rhsChild != NULL)
      {
         pRight = rhsChild;
         rhsChild->pParent = this;
      }
      else
         pRight = NULL;
   }
   catch (...)
   {
      cout << "ERROR: Unbale to allocate a node";
   }

   return this;
}

/***********************************************************************
 * deleteBinaryTree deletes everything one node at a time
 ***********************************************************************/
template <class T>
void deleteBinaryTree(BinaryNode<T> * node)
{
   if (node == NULL)
      return;
   else if(node->pLeft > NULL)
      deleteBinaryTree(node->pLeft);
   else if(node->pRight > NULL)
      deleteBinaryTree(node->pRight);
   
   delete node;
}

/***********************************************************************
 * insertion operator, inserts
 ***********************************************************************/
template <class T>
ostream & operator << (ostream & out, const BinaryNode<T> * rhs)
{
   if(rhs == NULL)
      return out;
   else
   {
      if(rhs != NULL)
      {
         out << rhs->pLeft;
         out << rhs->data << " ";
         out << rhs->pRight;
      }
      return out;
   }
}

#endif //end BNODE_H