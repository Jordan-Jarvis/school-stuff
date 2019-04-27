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
#ifndef LIST_H
#define LIST_H
using namespace std;

#include <cassert>
template <class T>
class ListIterator;
template <class T>
class List;
/*************************************************************************
 * NODE CLASS
 *************************************************************************/
template <class T>
class Node
{
  public:
   // node constructors
  Node(): pNext(NULL), pPrev(NULL) {}
   Node(T item)           { data = item; pNext = pPrev = NULL; }
   Node(const Node & cpy) { data = cpy.data; pNext = cpy.pNext; pPrev = cpy.pPrev; }
   Node(Node * next, Node * prev = NULL): pNext(next) {}
      

   T data; //data in the list
   Node * pNext; //next one to point at
   Node * pPrev; //previous one to point at
};

/*************************************************************************
 * LISTITERATOR
 *************************************************************************/
template <class T>
class ListIterator
{
  public:
   // default constructor
  ListIterator() : p(NULL) {}
   
   // initialize to direct p to some item
   ListIterator(Node<T> * newNode) {p = newNode;}

   // copy constructor
   ListIterator(const ListIterator & rhs) { *this = rhs;}
   
/*OPERATORS, taken from previous, with modification */
   // assign operator
   ListIterator & operator = (const ListIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }
   // not equals operator
   bool operator != (const ListIterator & rhs) const
   {
      if(rhs.p != this->p)
         return true;
      else
         return false;
   }
   // equals to operator
   bool operator == (const ListIterator &rhs)
   {
      return rhs.p == this->p;
   }
   // dereference operator
   T & operator * ()
   {
      return p->data;
   }
   // prefix increment
   ListIterator <T> & operator ++ ()
   {
      p = p->pNext;
      return *this;
   }
   // postfix increment
   ListIterator <T> operator++ (int postfix)
   {
      ListIterator tmp(*this);
      if(p)
         p = p->pNext;
      return tmp;
   }
   // prefix decrement
   ListIterator <T> & operator -- ()
   {
      if(p)
         p = p->pPrev;
      return *this;
   }
   // postfix decrement
   ListIterator <T> operator-- (int postfix)
   {
      ListIterator tmp(*this);
      p = p->pPrev;
      return tmp;
   }
   
   //p is the only thing an iterator has
   Node<T> * p;
};

/*************************************************************************
 * LIST CLASS
 * Container of a list
 *************************************************************************/
template <class T>
class List
{
  public:
  //default
  List(): LFront(NULL), LBack(NULL), numItems(0) {}
  //copy
  List(const List<T> & rhs)
  {
      LFront = LBack = NULL;
      numItems = 0;
      
      Node<T> * tmp = rhs.LFront;
      while(tmp != NULL)
      {
         this->push_back(tmp->data);
         tmp = tmp->pNext;
      }
   }
   //destruct
   ~List() { clear(); }
   
   //prototypes
   bool empty() { return numItems == 0; }  // Is the list empty?
   int size()   { return numItems;      }  // returns number of items
   void clear();  // clears the list
 
   void push_back(const T & item);   // adds item to back
   void push_front(const T & item);  // adds item to front
   void remove(ListIterator<T> it) throw (const char *); // removes item

   T & front() throw (const char *);  // returns front of list
   T & back()  throw (const char *);  // returns back of list
   
   //couldnt figure out how to make it a friend properly
   ListIterator<T> insert(ListIterator<T> it, T item);   // add item 
   ListIterator<T> begin()  const { return ListIterator<T>(LFront); }
   ListIterator<T> rbegin() const { return ListIterator<T>(LBack); }
   ListIterator<T> end()    const { return ListIterator<T>(NULL); }
   ListIterator<T> rend()   const { return ListIterator<T>(NULL); }

   //oh ya there is an operator
   void operator = (List rhs);

  private:
   //what a list contains
   Node<T> * LFront; //points to the front of the list
   Node<T> * LBack; //points to the back of the list
   int numItems; //number of items in the list
};

/*************************************************************************
 * clear
 * deleates everyting on the list
 *************************************************************************/
template <class T>
void List<T>:: clear()
{
   while (LFront != NULL)
   {
      Node<T> * temp = LFront;
      LFront = LFront->pNext;
      delete temp;
   }
   LBack = NULL;
   numItems = 0;
}

/*************************************************************************
 * PUSH_BACK
 * adds an item to the back of the list.
 *************************************************************************/
template <class T>
void List<T>:: push_back(const T & item)
{
   if (LBack == NULL)
      LFront = LBack = new Node<T>(item);
   else
   {
      Node<T> * newNode = new Node<T>(item);
      newNode->pPrev = LBack;
      LBack->pNext = newNode;
      LBack = newNode;
      newNode->pNext = NULL;
   }
   numItems++;
}

/*************************************************************************
 * PUSH_FRONT
 * adds an item to the front of the list.
 *************************************************************************/
template <class T>
void List<T>:: push_front(const T & item)
{
   if (LFront == NULL)
      LFront = LBack = new Node<T>(item);
   else
   {
      Node<T> * newNode = new Node<T>(item);
      newNode->pNext = LFront;
      LFront->pPrev = newNode;
      LFront = newNode;
      newNode->pPrev = NULL;
   }
   numItems++;
}

/*************************************************************************
 * FRONT
 * returns the front of the list
 *************************************************************************/
template <class T>
T & List<T>:: front() throw (const char *)
{
   if(!empty())
      return LFront->data;
   else
      throw "ERROR: unable to access data from an empty list";
}

/*************************************************************************
 * back
 * returns the back of the list
 *************************************************************************/
template <class T>
T & List<T>:: back() throw (const char *)
{
   if(!empty())
      return LBack->data;
   else
      throw "ERROR: unable to access data from an empty list";
}

/*************************************************************************
 * insert
 * inserts an item to the list.
 *************************************************************************/
template <class T>
ListIterator<T> List<T>:: insert(ListIterator<T> it, T item)
{
   // make a new pointer
   Node<T> * newNode = new Node<T>(item);
   
   if (it.p == LFront)
   {
      push_front(item);
      return begin();
   }
   else if (it.p == LBack)
   {
      push_back(item);
      return end();
   }
   else if(it == end())
   {
      newNode->pNext = NULL;
      newNode->pPrev = LBack;
      LBack->pNext = newNode;
      LBack = newNode;
      return end();
   }
   else
   {
      Node<T> * prev = it.p->pPrev;
      newNode->pNext = it.p;
      newNode->pPrev = prev;
      it.p->pPrev = newNode;
      prev->pNext = newNode;
      numItems++;
      return ListIterator<T>(newNode);
   }
}

/*************************************************************************
 * remove
 * removes a item from the list.
 *************************************************************************/
template <class T>
void List<T>:: remove(ListIterator<T> item) throw (const char *)
{   
   if (!empty())
   {
      if(item == LFront)
      {
         Node<T> * tempNode = item.p->pNext;
         tempNode->pPrev = NULL;
         LFront = tempNode;

         delete item.p;
      }
      else if (item == LBack)
      {
         Node<T> * prev = item.p->pPrev;
         prev->pNext = NULL;
         LBack = prev;
         
         delete item.p;
      }
      else
      {
         Node<T> * prev = item.p->pPrev;
         Node<T> * tempNode = item.p->pNext;

         prev->pNext = tempNode;
         tempNode->pPrev = prev;

         delete item.p;
      }
      
      numItems--;
   }
   else
   {
      throw "ERROR: unable to remove from an invalid location in a list";
   }
}

/*************************************************************************
 * operator =
 * copies one list into another
 *************************************************************************/
template <class T>
void List<T>:: operator = (List rhs)
{
   LFront = LBack = NULL;
   numItems = 0;
   
   Node<T> * temp = rhs.LFront;
   while(temp != NULL)
   {
      this->push_back(temp->data);
      temp = temp->pNext;
   }
}

#endif //end LIST_H