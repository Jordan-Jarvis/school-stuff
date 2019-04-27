#ifndef BNODE_H
#define BNODE_H

using namespace std;
#include <iostream>
#include <cassert>

/***********************************************************************
 * BNODE CLASS
 * Container of a binary node tree
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
   BinaryNode<T> * addLeft(BinaryNode<T> * leftChild) throw (const char *);
   BinaryNode<T> * addRight(T item) throw (const char *);
   BinaryNode<T> * addRight(BinaryNode<T> * rightChild) throw (const char *);
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
BinaryNode<T> * BinaryNode<T>:: addLeft(BinaryNode<T> * leftChild) throw (const char *)
{
   try
   {
      if(leftChild != NULL)
      {
         leftChild->pParent = this;
         pLeft = leftChild;
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
BinaryNode<T> * BinaryNode<T>:: addRight(BinaryNode<T> * rightChild) throw (const char *)
{
   try
   {
      if(rightChild != NULL)
      {
         pRight = rightChild;
         rightChild->pParent = this;
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
   if(node->pRight != NULL)
      deleteBinaryTree(node->pRight);
   if(node->pLeft != NULL)
      deleteBinaryTree(node->pLeft);
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