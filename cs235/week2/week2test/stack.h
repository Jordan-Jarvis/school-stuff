/***********************************************************************
* Header:
*    Stack
* Summary:
*    This class contains a similar implimentation to the Standard 
*    template library version of stack, with a few safeguards.
*
*    This will contain the class definition of:
*        Stack         : A class that holds stuff
*        StackIterator : An interator through Stack
* Author
*    Jordan Jarvis
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>

// forward declaration for StackIterator
template <class T>
class StackIterator;

/************************************************
 * Stack
 * A class that holds stuff
 ***********************************************/
template <class T>
class Stack
{
public:
   // default constructor : empty and kinda useless
   Stack() : numItems(0), cap(0), data(NULL) {}

   // copy constructor : copy it
   Stack(const Stack & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Stack(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Stack()        { if (cap) delete [] data; }
   
   // is the Stack currently empty
   bool empty() const  { return numItems == 0; }      

   // how many items are currently in the Stack?
   int size() const    { return numItems;              }

   // add an item to the Stack
   void insert(const T & t) throw (const char *);
   
   // return an iterator to the beginning of the list
   StackIterator <T> begin() { return StackIterator<T>(data); }

   // return an iterator to the end of the list
   StackIterator <T> end() { return StackIterator<T>(data + numItems);}
   
   //capacity function, returns the capacity
   int capacity() { return cap;}
   
   //pushback function, adds 1 to the number of items
   void push(const T & t);
   
   //resize function
   void resize(int newCap);
   
   //clear, delete everything
   void clear();
   
   // copies one data to another
   Stack <T>& operator = (const Stack & info) throw (const char *);

   //removes the top
   void pop() throw (const char *);
   
   //returns the top of stack
   T & top() throw (const char *);
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Stack?
   int cap;           // how many items can I put on the Stack before full?
};

/**************************************************
 * Stack ITERATOR
 * An iterator through Stack
 *************************************************/
template <class T>
class StackIterator
{
  public:
   // default constructor
  StackIterator() : p(NULL) {}

   // initialize to direct p to some item
  StackIterator(T * p) : p(p) {}


   // not equals operator
   bool operator != (const StackIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   StackIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   StackIterator <T> operator++(int postfix)
   {
      StackIterator tmp(*this);
      p++;
      return tmp;
   }
   
  private:
   T * p;
};

/*******************************************
 * Stack :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Stack <T> :: Stack(const Stack <T> & rhs) throw (const char *)
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
   for (int i = 0; i < numItems; i++)
      data[i] = rhs.data[i];

   // the rest needs to be filled with the default value for T
   for (int i = numItems; i < cap; i++)
      data[i] = T();
}

/**********************************************
 * Stack : NON-DEFAULT CONSTRUCTOR
 * Preallocate the Stack to "capacity"
 **********************************************/
template <class T>
Stack <T> :: Stack(int capacity) throw (const char *)
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

   // initialize the Stack by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * Stack :: INSERT
 * Insert an item on the end of the Stack
 **************************************************/
template <class T>
void Stack <T> :: insert(const T & t) throw (const char *)
{
   // do we have space?
   if (cap == 0 || cap == numItems)
      throw "ERROR: Insufficient space";
   
   // add an item to the end
   data[numItems++] = t;
}

/***************************************************
 * Stack :: push_back
 * Insert an item on the end of the Stack
 **************************************************/
template <class T>
void Stack <T> :: push(const T & t)
{
      if (cap == 0)
      {
         cap = 1;
         resize(1);
      }
      if (numItems == cap)
      {
         cap *= 2;
         resize(cap);
      }
      data[numItems++] = t;
}

/***************************************************
 * Stack :: resize
 * Insert an item on the end of the Stack
 **************************************************/
template <class T>
void Stack <T> :: resize(int newCap)
{

   T * newData =  new T[newCap];
   for (int i = 0; i < numItems; i++)
      newData[i] = data[i];
   delete[] data;
   data = newData;
   
}
   
/***************************************************
 * Stack :: clear
 * clears everything in the vector
 **************************************************/
template <class T>
void Stack <T> :: clear()
{
   numItems = 0;
}

/***************************************************
 * Stack :: =
 * assigns vecors to be a vector
 **************************************************/
template <class T>
Stack <T> &Stack <T>:: operator = (const Stack <T> & rhs) throw (const char *)
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
      throw "ERROR: Unable to allocate a new buffer for Stack";
   }
   
   // copy over the capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.cap);
   cap = rhs.cap;
   numItems = rhs.numItems;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numItems; i++)
      data[i] = rhs.data[i];

   // the rest needs to be filled with the default value for T
   for (int i = numItems; i < cap; i++)
      data[i] = T();
      
      return *this;
}

/***************************************************
 * Stack :: pop
 * removes the top item
 **************************************************/
template <class T>
void Stack <T> :: pop() throw (const char *)
{
   if (numItems == 0)
      throw "ERROR: Unable to pop from an empty Stack";
   else
      numItems--;
}


/***************************************************
 * Stack :: top
 * returns the top of the stack
 **************************************************/
template <class T>
T &Stack <T> :: top() throw (const char *)
{
   if (numItems == 0)
      throw "ERROR: Unable to reference the element from an empty Stack";
   return data[numItems - 1];
}
#endif // VECTOR_H

