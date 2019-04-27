/***********************************************************************
 * Component:
 *    Week 09, Binary Search Tree (BST)
 *    Brother Ercanbrack, CS 235
 * Author:
 *    Br. Helfrich
 *    Modified by Scott Ercanbrack - removed most of the the BST class functions,
 *                                   but left BST Iterator class.
 *    Modified by Jordan Jarvis - Added what was needed to fix everything.
 * Summary:
 *    Create a binary search tree
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include "bnode.h"    // for BinaryNode
#include "stack.h"    // for Stack

// forward declaration for the BST iterator
template <class T>
class BSTIterator;

/*****************************************************************
 * BINARY SEARCH TREE
 * Create a Binary Search Tree
 *****************************************************************/
template <class T>
class BST
{
public:
   // constructor
   BST(): root(NULL){};

   // copy constructor
   BST(const BST & rhs);

   ~BST();

   int  size() const  { return empty() ? 0 : root->size(); }   // BinaryNode class needs a size function


   // determine if the tree is empty
   bool empty() const
   {
      return root == NULL;
   }

   // remove all the nodes from the tree.  Makes an empty tree.
   void clear()
   {
      deleteBinaryTree(root);
      root = NULL;
   }
   //copy function prototype
   void copy(BinaryNode<T> * rightS, BinaryNode<T> * Passin);

   // overloaded assignment operator
   BST & operator = (const BST & rhs) throw (const char *)
   {
       // if rhs is empty then return
       if (rhs.empty())
          return *this;
       else
       {
          // copy the root
          this->root = new BinaryNode<T>(rhs.root->data);
          copy(rhs.root, this->root);
       }
       return *this;
      
   }

   // insert an item
   void insert(const T & t) throw (const char * );

   // remove an item
   void remove(BSTIterator <T> & it);

   // find a given item
   BSTIterator <T> find(const T & t);

   // the usual iterator stuff
   BSTIterator <T> begin() const;
   BSTIterator <T> end() const  { return BSTIterator <T> (NULL) ; }
   BSTIterator <T> rbegin() const;
   BSTIterator <T> rend() const  { return BSTIterator <T> (NULL); }

private:

   BinaryNode <T> * root;
};

/*********************************************************
* copy constructor
**********************************************************/
template <class T>
BST<T>::BST(const BST &rhs)
{
   if (rhs.root == NULL)
      this->root = NULL;
   else
      *this = rhs;
    
}

/*****************************************************
* copy function, made life so much easier
*******************************************************/
template <class T>
void BST<T> :: copy(BinaryNode<T> * rightS, BinaryNode<T> * passIn) 
{
   if (rightS->pLeft == NULL && rightS->pRight == NULL)
      return;

   else
   {
      if (rightS->pLeft)
      {
         passIn->addLeft(rightS->pLeft->data);
         copy(rightS->pLeft, passIn->pLeft);
      }
      if (rightS->pRight)
      {
         passIn->addRight(rightS->pRight->data);
         copy(rightS->pRight, passIn->pRight);
      }
   }
}

/*****************************************************
* Destructor
*******************************************************/
template <class T>
BST<T>::~BST()
{
   clear();
}

/*****************************************************
 * BST :: BEGIN
 * Return the first node (left-most) in a binary search tree
 ****************************************************/
template <class T>
BSTIterator <T> BST <T> :: begin() const
{
   Stack < BinaryNode <T> * > nodes;

   nodes.push(NULL);
   nodes.push(root);
   while (nodes.top() != NULL && nodes.top()->pLeft)
      nodes.push(nodes.top()->pLeft);

   return BSTIterator<T>(nodes);
}

/*****************************************************
 * BST :: RBEGIN
 * Return the last node (right-most) in a binary search tree
 ****************************************************/
template <class T>
BSTIterator <T> BST <T> :: rbegin() const
{
   Stack < BinaryNode <T> * > nodes;

   nodes.push(NULL);
   nodes.push(root);
   while (nodes.top() != NULL && nodes.top()->pRight)
      nodes.push(nodes.top()->pRight);

   return BSTIterator<T>(nodes);
}

/*****************************************************
 * BST :: INSERT
 * Insert a node at a given location in the tree
 ****************************************************/
template <class T>
void BST <T> :: insert(const T & t) throw (const char *)
{
   BinaryNode<T> * position = root;
   BinaryNode<T> * parent = NULL;

   while(position)
   {
      parent = position;
      if (t < position->data)
         position = position->pLeft;
      else
         position = position->pRight;
   }

   if (parent)
   {
      if (t < parent->data)
         parent->addLeft(new BinaryNode<T> (t));
      else
         parent->addRight(new BinaryNode<T> (t));
   }
   else
      root = new BinaryNode<T> (t);
}

/*************************************************
 * BST :: REMOVE
 * Remove a given node as specified by the iterator
 ************************************************/
template <class T>
void BST <T> :: remove(BSTIterator <T> & it)
{
   if (it.getNode() == NULL)
      throw "ERROR: null iterator";

   if (it.getNode()->pLeft != NULL && it.getNode()->pRight != NULL)
   {
      // copy the node
      BinaryNode <T> * pTemp = it.getNode();
      it++;

      // copy the data in
      pTemp->data = it.getNode()->data;

      remove(it);
   }
   else
   {
      if (it.getNode()->pParent->pLeft == it.getNode())
      {
         if (it.getNode()->pLeft != NULL)
         {
            it.getNode()->pParent->pLeft = it.getNode()->pLeft;
            it.getNode()->pLeft->pParent = it.getNode()->pParent;
         }
         else
         {
            it.getNode()->pParent->pLeft = it.getNode()->pRight;

            if (it.getNode()->pLeft != NULL)
               it.getNode()->pLeft->pParent = it.getNode()->pParent;
         }

      }

      else
      {
         if (it.getNode()->pLeft != NULL)
         {
            it.getNode()->pParent->pRight = it.getNode()->pLeft;

            it.getNode()->pLeft->pParent = it.getNode()->pParent;
         }
         else
         {
            it.getNode()->pParent->pRight = it.getNode()->pRight;

            if (it.getNode()->pRight != NULL)
               it.getNode()->pRight->pParent = it.getNode()->pParent;
         }
      }

      // delete the node
      delete it.getNode();
   }
}

/****************************************************
 * BST :: FIND
 * Return the node corresponding to a given value
 ****************************************************/
template <class T>
BSTIterator <T> BST <T> :: find(const T & t)
{
   BinaryNode<T> * tmp = root;

   while (tmp)
   {
      if (tmp->data == t)
         return BSTIterator<T>(tmp);
      else if (tmp->data > t)
         tmp = tmp->pLeft;
      else
         tmp = tmp->pRight;
   }

   return end();
}


/**********************************************************
 * BINARY SEARCH TREE ITERATOR
 * Forward and reverse iterator through a BST
 *********************************************************/
template <class T>
class BSTIterator
{
public:
   // constructors
   BSTIterator(BinaryNode <T> * p = NULL)    { nodes.push(p);  }
   BSTIterator(Stack <BinaryNode <T> *> & s) { nodes = s;         }
   BSTIterator(const BSTIterator <T> & rhs)  { nodes = rhs.nodes; }

   // assignment
   BSTIterator <T> & operator = (const BSTIterator <T> & rhs)
   {
      // need an assignment operator for the Stack class.
      nodes = rhs.nodes;
      return *this;
   }

   // compare
   bool operator == (const BSTIterator <T> & rhs) const
   {
      // only need to compare the leaf node
      return rhs.nodes.const_top() == nodes.const_top();
   }
   bool operator != (const BSTIterator <T> & rhs) const
   {
      // only need to compare the leaf node
      return rhs.nodes.const_top() != nodes.const_top();
   }

   // de-reference. Cannot change because it will invalidate the BST
   T & operator * ()
   {
      return nodes.top()->data;
   }

   // iterators
   BSTIterator <T> & operator ++ ();
   BSTIterator <T>   operator ++ (int postfix)
   {
      BSTIterator <T> itReturn = *this;
      ++(*this);
      return itReturn;
   }
   BSTIterator <T> & operator -- ();
   BSTIterator <T>   operator -- (int postfix)
   {
      BSTIterator <T> itReturn = *this;
      --(*this);
      return itReturn;
   }

   // must give friend status to remove so it can call getNode() from it
   friend void BST <T> :: remove(BSTIterator <T> & it);

private:

   // get the node pointer
   BinaryNode <T> * getNode() { return nodes.top(); }

   // the stack of nodes
   Stack < BinaryNode <T> * > nodes;
};


/**************************************************
 * BST ITERATOR :: INCREMENT PREFIX
 * advance by one
 *************************************************/
template <class T>
BSTIterator <T> & BSTIterator <T> :: operator ++ ()
{
   // do nothing if we have nothing
   if (nodes.top() == NULL)
      return *this;

   // if there is a right node, take it
   if (nodes.top()->pRight != NULL)
   {
      nodes.push(nodes.top()->pRight);

      // there might be more left-most children
      while (nodes.top()->pLeft)
         nodes.push(nodes.top()->pLeft);
      return *this;
   }

   // there are no right children, the left are done
   assert(nodes.top()->pRight == NULL);
   BinaryNode <T> * pSave = nodes.top();
   nodes.pop();

   // if the parent is the NULL, we are done!
   if (NULL == nodes.top())
      return *this;

   // if we are the left-child, got to the parent.
   if (pSave == nodes.top()->pLeft)
      return *this;

   // we are the right-child, go up as long as we are the right child!
   while (nodes.top() != NULL && pSave == nodes.top()->pRight)
   {
      pSave = nodes.top();
      nodes.pop();
   }

   return *this;
}

/**************************************************
 * BST ITERATOR :: DECREMENT PREFIX
 * advance by one
 *************************************************/
template <class T>
BSTIterator <T> & BSTIterator <T> :: operator -- ()
{
   // do nothing if we have nothing
   if (nodes.top() == NULL)
      return *this;

   // if there is a left node, take it
   if (nodes.top()->pLeft != NULL)
   {
      nodes.push(nodes.top()->pLeft);

      // there might be more right-most children
      while (nodes.top()->pRight)
         nodes.push(nodes.top()->pRight);
      return *this;
   }

   // there are no left children, the right are done
   assert(nodes.top()->pLeft == NULL);
   BinaryNode <T> * pSave = nodes.top();
   nodes.pop();

   // if the parent is the NULL, we are done!
   if (NULL == nodes.top())
      return *this;

   // if we are the right-child, got to the parent.
   if (pSave == nodes.top()->pRight)
      return *this;

   // we are the left-child, go up as long as we are the left child!
   while (nodes.top() != NULL && pSave == nodes.top()->pLeft)
   {
      pSave = nodes.top();
      nodes.pop();
   }

   return *this;
}


#endif // BST_H
