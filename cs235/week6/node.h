/***********************************************************************
* Header:
*    Node
* Summary:
*    This class contains the notion of a Node: or a list of objects
*
*    This will contain the class definition of:
*        Node         : A class that works like a node
* Author
*    Jordan Jarvis
************************************************************************/

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cassert>

// forward declaration for NodeIterator
template <class T>
class NodeIterator;

/************************************************
 * Node
 * A class that holds stuff
 ***********************************************/
template <class T>
class Node
{
public:
   // default constructor : empty and kinda useless
   Node() : pNext(NULL), data(T()) {}

   // copy constructor : copy it
   Node(const T & passIn) : pNext(NULL)
    {
       this->data = passIn;
    }
   
   // add an item to the Nodes
   void insert(T passIn, Node<T> * &pHead, bool isHead = false);
   
   //finds an item and returns negative if not found
   int find(Node<T> * pHead, T value);
   
   //free data function
   void freeData(Node<T> * &first);
   
   //copies
   void copy(Node<T> * first);

   //public to allow for use between nodes
   T  data;          // the actual data
   Node<T> * pNext;    // points to the next node in list
};


/****************************************************
 * COPY
 * Returns a copy of the list passed in
 ****************************************************/
template <class T>
Node<T> * copy(Node<T> * first)
{
   // Check to see if NULL
   if (first == NULL)
      return NULL;

   Node <T> * tempNode = new Node <T>;

   // Copy data into the temp
   tempNode->data = first->data;

   if (first->pNext != NULL)
      tempNode->pNext = copy(first->pNext); //recall for a link

   return tempNode;
}

/****************************************************
 * INSERT
 * Insert an item to the list. 
 ****************************************************/
template <class T>
void insert(T passIn, Node<T> * &whereAt, bool isFront = false)
{
   Node<T> * tempData = new Node<T>(passIn);

   // if inserting to the front
   if (isFront || whereAt == NULL) 
   {
      tempData->pNext = whereAt;
      whereAt = tempData;        
   }
   else // if inserting anywhere except the front
   {
      tempData->pNext = whereAt->pNext;
      whereAt->pNext = tempData;
   }
}

/****************************************************
 * FIND
 * Find a value in the list, return NULL if not found
 ****************************************************/
template <class T>
Node<T>* find(Node<T> * passIn, T value)
{
   // see if passIn is NULL
   if (passIn == NULL)
      return NULL;

   // If not NULL
   else if (passIn->data == value)
      return passIn;

   // Increment the pointer
   else
      return find(passIn->pNext, value);
}

/*****************************************************
 * FREEDATA
 * deletes the list
 *****************************************************/
template <class T>
void freeData(Node<T> * &passIn)
{
   for (Node<T> * p = passIn; p; p = p->pNext)
   {
      delete p;
   }
   passIn = NULL;
}

/******************************************
 * DISPLAY
 * Display the contents of the Node
 *****************************************/
template <class T>
std::ostream & operator << (std::ostream & out, Node <T> * rhs)
{
   while (rhs != NULL)
   {
      //if the end, no comma
      if (rhs->pNext == NULL)
      {
         out << rhs->data;
         rhs=rhs->pNext;
      }
      //send out the data and a comma space
      else 
      {
         out << rhs->data << ", ";
         rhs = rhs->pNext;
      }
         
   }
   return out;   //send it out as a list of outs
}
#endif // VECTOR_H

