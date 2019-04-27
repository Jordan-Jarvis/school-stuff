/***********************************************************************
* Header:
*    Deque
* Summary:
*    This class contains the headers for the deque class
*
*    This will contain the class definition of:
*        Deque         : A class that holds stuff
* Author
*    Jordan Jarvis
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H
#include <cassert>


/************************************************
 * Deque
 * A class that holds stuff and can be accessed like a stack, with insertions.
 ***********************************************/
template <class T>
class Deque
{
public:
   // default constructor : empty and kinda useless
   Deque() : numItems(0), cap(0), data(NULL), fro(0), bac(0) {}
   // copy constructor : copy it
   Deque(const Deque & rhs) throw (const char *);
   // non-default constructor : pre-allocate
   Deque(int capacity) throw (const char *);
   // destructor : free everything
   ~Deque()        { if (cap) delete [] data; }
   // is the Deque currently empty
   bool empty() const  { return numItems == 0; }     
   // how many items are currently in the Deque?
   int size() const    { return numItems; }
   // add an item to the Deque
   void insert(const T & t) throw (const char *);
   //capacity function, returns the capacity
   int capacity() { return cap;}
   //adds to the front
   void push_front(const T & t);  
   //adds to the back
   void push_back(const T & t);
   //resize function
   void resize(int newCap);
   //clear, delete everything
   void clear();
   // copies one data to another
   Deque <T>& operator = (const Deque & info) throw (const char *);
   //removes the front
   void pop_front() throw (const char *);
   //removes the back
   void pop_back() throw (const char *);   
   //returns the front of queue
   T & front() throw (const char *);
   //returns the back of queue
   T & back() throw (const char *);
   
private:
   T * data;      // dynamically allocated array
   int numItems;  // how many items are in the deque
   int cap;       // maximum capacity
   int fro;       // front of the deque
   int bac;       // back of the deque
};

/*******************************************
 * Deque :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Deque <T> :: Deque(const Deque <T> & rhs) throw (const char *)
{
   assert(rhs.cap >= 0);
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
   // copy capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.cap);
   cap = rhs.cap;
   numItems = rhs.numItems;
   // copy the items with the assignment operator
   int j = rhs.fro;
   for (int i = 0; i < numItems; i++, j = (j+1)%cap)
      data[i] = rhs.data[j];
   for (int i = numItems; i < cap; i++)
      data[i] = T();
   fro = 0;
   bac = rhs.numItems;
}

/**********************************************
 * Deque : NON-DEFAULT CONSTRUCTOR
 * allocate the Deque to "capacity"
 **********************************************/
template <class T>
Deque <T> :: Deque(int capacity) throw (const char *)
{
   assert(capacity >= 0);
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
   this->cap = capacity;
   this->numItems = 0;
   this->bac = 0;
   this->fro = 0;
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * Deque :: INSERT
 * Insert an item 
 **************************************************/
template <class T>
void Deque <T> :: insert(const T & t) throw (const char *)
{
   // check for space
   if (cap == 0 || cap == numItems)
      throw "ERROR: Insufficient space";

   data[numItems++] = t;
}

/***************************************************
 * Deque :: push_front
 * Insert an item on the front
 **************************************************/
template <class T>
void Deque <T> :: push_front(const T & t)
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
      fro = ((fro+cap)-1)%cap;
      data[fro] = t;
      numItems++;
}

/***************************************************
 * Deque :: push_back
 * Insert an item on the end
 **************************************************/
template <class T>
void Deque <T> :: push_back(const T & t)
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
 * Deque :: resize
 * sets new capacity
 **************************************************/
template <class T>
void Deque <T> :: resize(int capa)
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
 * Deque :: clear
 * clears everything in the queue
 **************************************************/
template <class T>
void Deque <T> :: clear()
{
   numItems = 0;
   fro = 0;
   bac = 0;
}

/***************************************************
 * Deque :: =
 * assigns queue to be a queue
 **************************************************/
template <class T>
Deque <T> &Deque <T>:: operator = (const Deque <T> & rhs) throw (const char *)
{    
     assert(rhs.cap >= 0);
     if (this->cap)
        delete [] data;
   if (rhs.cap == 0)
   {
      cap = 0;
      numItems = 0;
      data = NULL;
      return *this;
   }
   try
   {
      data = new T[rhs.cap];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for Deque";
   }
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.cap);
   cap = rhs.cap;
   numItems = rhs.numItems;
   int j = rhs.fro;
   for (int i = 0; i < numItems; i++, j = (j+1)%cap)
      data[i] = rhs.data[j];

   for (int i = numItems; i < cap; i++)
      data[i] = T();
   fro = 0;
   bac = rhs.numItems;
   return *this;
}

/***************************************************
 * Deque :: pop_front
 * removes the front item
 **************************************************/
template <class T>
void Deque <T> :: pop_front() throw (const char *)
{
   if (numItems == 0)
      throw "ERROR: unable to pop from the front of empty deque";
   else
   {
      fro = (fro+1)%cap;
      numItems--;
   }
}


/***************************************************
 * Deque :: pop_back
 * removes the back item
 **************************************************/
template <class T>
void Deque <T> :: pop_back() throw (const char *)
{
   if (numItems == 0)
      throw "ERROR: unable to pop from the back of empty deque";
   else
   {
      bac = (bac+cap-1)%cap;
      numItems--;
   }
}

/***************************************************
 * Deque :: front
 * returns the top of the queue
 **************************************************/
template <class T>
T &Deque <T> :: front() throw (const char *)
{
   if (numItems == 0)
      throw "ERROR: unable to access data from an empty deque";
   return data[fro];
}

/***************************************************
 * Deque :: back
 * returns the back of the queue
 **************************************************/
template <class T>
T &Deque <T> :: back() throw (const char *)
{
   if (numItems == 0)
      throw "ERROR: unable to access data from an empty deque";
   return data[(cap+bac-1)%cap];
}
#endif

