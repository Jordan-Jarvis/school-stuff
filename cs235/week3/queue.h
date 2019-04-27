/***********************************************************************
* Header:
*    Queue
* Summary:
*    This class contains the notion of a Queue
*
*    This will contain the class definition of:
*        Queue         : A class that holds stuff
* Author
*    Jordan Jarvis
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H
#include "dollars.h"
#include <cassert>

// forward declaration for QueueIterator
template <class T>
class QueueIterator;

/************************************************
 * Queue
 * A class that holds stuff
 ***********************************************/
template <class T>
class Queue
{
public:
   // default constructor : empty and kinda useless
   Queue() : numItems(0), cap(0), data(NULL), fro(0), bac(0) {}

   // copy constructor : copy it
   Queue(const Queue & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Queue(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Queue()        { if (cap) delete [] data; }
   
   // is the Queue currently empty
   bool empty() const  { return numItems == 0; }      

   // how many items are currently in the Queue?
   int size() const    { return numItems;              }

   // add an item to the Queue
   void insert(const T & t) throw (const char *);
   

   
   //capacity function, returns the capacity
   int capacity() { return cap;}
   
   //pushback function, adds 1 to the number of items
   void push(const T & t);
   
   //resize function
   void resize(int newCap);
   
   //clear, delete everything
   void clear();
   
   // copies one data to another
   Queue <T>& operator = (const Queue & info) throw (const char *);

   //removes the front
   void pop() throw (const char *);
   
   //returns the front of queue
   T & front() throw (const char *);
   
   //returns the back of queue
   T & back() throw (const char *);
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Queue?
   int cap;           // how many items can I put on the Queue before full?
   int fro;         // fro of the queue
   int bac;           // back of the queue
};



/*******************************************
 * Queue :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Queue <T> :: Queue(const Queue <T> & rhs) throw (const char *)
{
   assert(rhs.cap >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.cap == 0)
   {
      cap = 0;
      numItems = 0;
      data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.cap];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.cap);
   cap = rhs.cap;
   numItems = rhs.numItems;

   // copy the items over one at a time using the assignment operator
   int j = rhs.fro;
   for (int i = 0; i < numItems; i++, j = (j+1)%cap)
      data[i] = rhs.data[j];

   // the rest needs to be filled with the default value for T
   for (int i = numItems; i < cap; i++)
      data[i] = T();
   fro = 0;
   bac = rhs.numItems;
}

/**********************************************
 * Queue : NON-DEFAULT CONSTRUCTOR
 * Preallocate the Queue to "capacity"
 **********************************************/
template <class T>
Queue <T> :: Queue(int capacity) throw (const char *)
{
   assert(capacity >= 0);
   
   
   // do nothing if there is nothing to do
   if (capacity == 0)
   {
      this->cap = this->numItems = 0;
      this->data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[capacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

      
   // copy over the stuff
   this->cap = capacity;
   this->numItems = 0;
   this->bac = 0;
   this->fro = 0;

   // initialize the Queue by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * Queue :: INSERT
 * Insert an item on the end of the Queue
 **************************************************/
template <class T>
void Queue <T> :: insert(const T & t) throw (const char *)
{
   // do we have space?
   if (cap == 0 || cap == numItems)
      throw "ERROR: Insufficient space";
   
   // add an item to the end
   data[numItems++] = t;
}

/***************************************************
 * Queue :: push_back
 * Insert an item on the end of the Queue
 **************************************************/
template <class T>
void Queue <T> :: push(const T & t)
{
      if (cap == 0)
      {
         cap = 1;
         resize(cap);
      }
      if (numItems == cap)
      {
         resize(cap);
      }
      data[bac] = t;
      bac = (bac + 1) % cap;
      numItems++;
}

/***************************************************
 * Queue :: resize
 * Insert an item on the end of the Queue
 **************************************************/
template <class T>
void Queue <T> :: resize(int capa)
{
   int j = fro;
   T * newData =  new T[capa*2];
   for (int i = 0; i < numItems; i++,j = (j+1)%cap)
      newData[i] = data[j];
   delete[] data;
   data = newData;
   fro = 0;
   bac = numItems; 
   cap *= 2;
}
   
/***************************************************
 * Queue :: clear
 * clears everything in the queue
 **************************************************/
template <class T>
void Queue <T> :: clear()
{
   numItems = 0;
   fro = 0;
   bac = 0;
}

/***************************************************
 * Queue :: =
 * assigns queues to be a queue
 **************************************************/
template <class T>
Queue <T> &Queue <T>:: operator = (const Queue <T> & rhs) throw (const char *)
{    
     assert(rhs.cap >= 0);
     
     if (this->cap)
        delete [] data;
      
   // do nothing if there is nothing to do
   if (rhs.cap == 0)
   {
      cap = 0;
      numItems = 0;
      data = NULL;
      return *this;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.cap];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for Queue";
   }
   
   // copy over the capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.cap);
   cap = rhs.cap;
   numItems = rhs.numItems;

   // copy the items over one at a time using the assignment operator
   int j = rhs.fro;
   for (int i = 0; i < numItems; i++, j = (j+1)%cap)
      data[i] = rhs.data[j];

   // the rest needs to be filled with the default value for T
   for (int i = numItems; i < cap; i++)
      data[i] = T();
   fro = 0;
   bac = rhs.numItems;
   return *this;
}

/***************************************************
 * Queue :: pop
 * removes the front item
 **************************************************/
template <class T>
void Queue <T> :: pop() throw (const char *)
{
   if (numItems == 0)
      throw "ERROR: attempting to pop from an empty queue";
   else
   {
      fro = (fro+1)%cap;
      numItems--;
   }
}


/***************************************************
 * Queue :: front
 * returns the top of the queue
 **************************************************/
template <class T>
T &Queue <T> :: front() throw (const char *)
{
   if (numItems == 0)
      throw "ERROR: attempting to access an item in an empty queue";
   return data[fro];
}

/***************************************************
 * Queue :: back
 * returns the back of the queue
 **************************************************/
template <class T>
T &Queue <T> :: back() throw (const char *)
{
   if (numItems == 0)
      throw "ERROR: attempting to access an item in an empty queue";
   return data[(cap+bac-1)%cap];
}
#endif

