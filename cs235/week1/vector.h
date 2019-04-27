/***********************************************************************
* Header:
*    Vector
* Summary:
*    This class contains the notion of a Vector: a bucket to hold
*    data for the user. This is just a starting-point for more advanced
*    constainers such as the vector, set, stack, queue, deque, and map
*    which we will build later this semester.
*
*    This will contain the class definition of:
*        Vector         : A class that holds data dynamically
*        VectorIterator : An interator through Vector
* Author
*    Jordan Jarvis
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>

// forward declaration for VectorIterator
template <class T>
class VectorIterator;

/************************************************
 * Vector
 * A class that holds stuff
 ***********************************************/
template <class T>
class Vector
{
public:
   // default constructor : empty and kinda useless
   Vector() : numItems(0), cap(0), data(NULL) {}

   // copy constructor : copy it
   Vector(const Vector & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Vector(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Vector()        { if (cap) delete [] data; }
   
   // is the Vector currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the Vector
   void clear()        { numItems = 0;                 }

   // how many items are currently in the Vector?
   int size() const    { return numItems;              }

   // add an item to the Vector
   void insert(const T & t) throw (const char *);
   
   // return an iterator to the beginning of the list
   VectorIterator <T> begin() { return VectorIterator<T>(data); }

   // return an iterator to the end of the list
   VectorIterator <T> end() { return VectorIterator<T>(data + numItems);}
   
   //capacity function, returns the capacity
   int capacity() { return cap;}
   
   //resize function
   void resize(int newCap);
   
   //pushback function, adds 1 to the number of items
   void push_back(const T & t);
   
   // copies one data to another
   Vector <T>& operator = (const Vector & info) throw (const char *);
   
   // returns a value from the container
   T& operator [] (int index) throw (const char *);
   
   T & operator [] (int index) const throw (const char *);
   
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Vector?
   int cap;           // how many items can I put on the Vector before full?
};

/**************************************************
 * Vector ITERATOR
 * An iterator through Vector
 *************************************************/
template <class T>
class VectorIterator
{
  public:
   // default constructor
  VectorIterator() : p(NULL) {}

   // initialize to direct p to some item
  VectorIterator(T * p) : p(p) {}


   // not equals operator
   bool operator != (const VectorIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return * p;
   }

   // prefix increment
   VectorIterator <T> & operator ++ ()
   {
      p++;
      return * this;
   }

   // postfix increment
   VectorIterator <T> operator++(int postfix)
   {
      VectorIterator tmp(*this);
      p++;
      return tmp;
   }
   
  private:
   T * p;
};

/*******************************************
 * Vector :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Vector <T> :: Vector(const Vector <T> & rhs) throw (const char *)
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
 * Vector : NON-DEFAULT CONSTRUCTOR
 * Preallocate the Vector to "capacity"
 **********************************************/
template <class T>
Vector <T> :: Vector(int capacity) throw (const char *)
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

   // initialize the Vector by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * Vector :: INSERT
 * Insert an item on the end of the Vector
 **************************************************/
template <class T>
void Vector <T> :: insert(const T & t) throw (const char *)
{
   // do we have space?
   if (cap == 0 || cap == numItems)
      throw "ERROR: Insufficient space";
   
   // add an item to the end
   data[numItems++] = t;
}

/***************************************************
 * Vector :: resize
 * Insert an item on the end of the Vector
 **************************************************/
template <class T>
void Vector <T> :: resize(int newCap)
{

   T * nData =  new T[newCap];
   for (int i = 0; i < numItems; i++)
   {
      nData[i] = data[i];
   }
   delete[] data;
   data = nData;
   
}

/***************************************************
 * Vector :: push_back
 * Add a new piece of data on the end of the Vector
 **************************************************/
template <class T>
void Vector <T> :: push_back(const T &t)
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
      std::cerr << "\nHEEEERRRREEEE!!!!!!!!!!! " << numItems << std::endl;
      std::cerr << "\nNEEEEEEEEEEXTTTTTTTTT!!!!!!!!!!! " << cap << std::endl;
      data[numItems++] = t;
}

/***************************************************
 * Vector :: =
 * assigns vectors to memory (allocate memory)
 **************************************************/
template <class T>
Vector <T> &Vector <T>:: operator = (const Vector <T> & rhs) throw (const char *)
{
     
     assert(rhs.cap >= 0);
     
     if (this->cap)
     {
        delete [] data;
     }
      
   // check if the capacity is zero, if so do nothing
   if (rhs.cap == 0)
   {
      numItems = 0;
      cap = 0;
      data = NULL;
      return *this;
   }

   // attempt to allocate memory needed
   try
   {
      data = new T[rhs.cap];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for Vector";
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
 * Vector :: []
 * Select specific data from the vector
 **************************************************/
template <class T>
T & Vector <T>:: operator [] (int index) throw (const char *)
{
   if (index > numItems || index < 0)
   {
      throw "ERROR: Invalid index\t";
   }
   else
      return data[index];
}

/***************************************************
 * Vector :: [] as well
 * same as vector:: [] except with const throw
 **************************************************/
template <class T>
T & Vector <T>:: operator [] (int index) const throw (const char *)
{
   if (index > numItems || index < 0)
   {
      throw "ERROR: Invalid index\t";
   }
   else
      return data[index];
}

#endif // VECTOR_H

