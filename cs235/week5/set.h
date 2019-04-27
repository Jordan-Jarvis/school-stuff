/***********************************************************************
* Header:
*    Set
* Summary:
*    This class contains the notion of a Set: or a list of objects
*
*    This will contain the class definition of:
*        Set         : A class that holds stuff
*        SetIterator : An interator through Set
* Author
*    Jordan Jarvis
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>

// forward declaration for SetIterator
template <class T>
class SetIterator;

/************************************************
 * Set
 * A class that holds stuff
 ***********************************************/
template <class T>
class Set
{
public:
   // default constructor : empty and kinda useless
   Set() : numItems(0), cap(0), data(NULL) {}

   // copy constructor : copy it
   Set(const Set & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Set(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Set()        { if (cap) delete [] data; }
   
   // is the Set currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the Set
  // void clear()        { numItems = 0;                 }

   // how many items are currently in the Set?
   int size() const    { return numItems;              }

   // add an item to the Set
   void insert(const T & t) throw (const char *);
   
   // return an iterator to the beginning of the list
   SetIterator <T> begin() { return SetIterator<T>(data); }

   // return an iterator to the end of the list
   SetIterator <T> end() { return SetIterator<T>(data + numItems);}
   
   //finds an item and returns negative if not found
   int find(T item);

   //capacity function, returns the capacity
   int capacity() { return cap;}
   
   //erase function, deletes an item
   void erase(int spot);

   //resize function
   void resize(int newCap);
   
   //clear, dele everything
   void clear();
   
   // copies one data to another
   Set <T>& operator = (const Set & info) throw (const char *);
   
   // the and type operator
   Set<T>  operator && (Set<T> right);

   // the or type operator
   Set<T> operator || (Set<T> right);
   
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Set?
   int cap;           // how many items can I put on the Set before full?
};

/**************************************************
 * Set ITERATOR
 * An iterator through Set
 *************************************************/
template <class T>
class SetIterator
{
  public:
   // default constructor
  SetIterator() : p(NULL) {}

   // initialize to direct p to some item
  SetIterator(T * p) : p(p) {}


   // not equals operator
   bool operator != (const SetIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   SetIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   SetIterator <T> operator++(int postfix)
   {
      SetIterator tmp(*this);
      p++;
      return tmp;
   }
   
  private:
   T * p;
};

/*******************************************
 * Set :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Set <T> :: Set(const Set <T> & rhs) throw (const char *)
{
      
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
 * Set : NON-DEFAULT CONSTRUCTOR
 * Preallocate the Set to "capacity"
 **********************************************/
template <class T>
Set <T> :: Set(int capacity) throw (const char *)
{
   
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

   // initialize the Set by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * Set :: INSERT
 * Insert an item on the end of the Set
 **************************************************/
template <class T>
void Set <T> :: insert(const T & t) throw (const char *)
{
   //checks if the item to be inserted is there
   //negative number if not there

   int check = find(t);
   if (cap == numItems)
      {
         if (cap == 0)
            cap = 1;
         cap = cap * 2;
         resize(cap);
      }
   
   //if it is not there, add it in
   if (check <= 0)
   {
      if(data[0] == t)
      {
         return;
      }
      //check for room
      
      //if nothing in the set
      if (numItems==0)
         {
            data[0] = t;
         }
      //if only one in set, easy comparison
      else if (numItems == 1)
      {
         if (data[0] < t)
         {
            data[1] = t;  
         }
         else
         {
            data[1] = data[0];
            data[0] = t;
         }
      }
      else
      {
            //std::cerr << binarySearch(t,0,numItems - 1, 0);
         check = (check) * -1;

         
            //if (t > data[check])
               {
              //    data[check+1] = t;  
               }
              // else
                  //    data[check+1] = data[check];
               for (int i = numItems - 1; i >= check; i--)
               {
                                          std::cerr << numItems;
                  data[i + 1] =data[i];

               }

               data[check] = t;
      }
      numItems++;
   }
}

/***************************************************
 * Set :: erase
 * erase an item on the end of the Set
 **************************************************/
template <class T>
void Set <T> :: erase(int spot)
{
   numItems--;
   int i = spot;
   for (i; i<numItems; i++)
   {
      data[i] = data[i+1];
   }      
}

/***************************************************
 * Set :: resize
 * Insert an item on the end of the Set
 **************************************************/
template <class T>
void Set <T> :: resize(int newCap)
{

   T * newData =  new T[newCap];
   for (int i = 0; i < numItems; i++)
      newData[i] = data[i];
   delete[] data;
   data = newData;
   
}
   
/***************************************************
 * Set :: clear
 * clears everything in the vector
 **************************************************/
template <class T>
void Set <T> :: clear()
{
   numItems = 0;
   cap = 0;
   delete [] data;
}

/***************************************************
 * Set :: =
 * assigns vecors to be a vector
 **************************************************/
template <class T>
Set <T> & Set <T> :: operator = (const Set <T> & rhs) throw (const char *)
{        
     if (this->cap)
     {
        delete [] data;
     }
   // do nothing if there is nothing to do
   if (rhs.cap == 0)
   {
      cap = 0;
      numItems = 0;
      data = NULL;
      return *this;
   }
   std :: cerr << "HERE\n";
   // attempt to allocate
   try
   {
      data = new T[rhs.cap];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for Set";
   }
   
   // copy over the capacity and size
   cap = rhs.cap;
   numItems = rhs.numItems;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numItems; i++)
   {
      data[i] = rhs.data[i];
   }
      return *this;
}

/***************************************************
 * Set :: find
 * searches a set and checks if something is there 
 **************************************************/
template <class T>
int Set <T> :: find(T item)
{
   
   int high = numItems - 1;
   if (numItems == 0)
   {
      return -1;
   }
   int low = 0;
   int mid = 0;
   while ( low <= high )
    {
        // find the middle iterator
        mid = (high + low) / 2;
        if ( data[mid] == item ) // found
        {
            return mid;
        }
        else if ( data[mid] > item ) // may be on the left half
        {
            high = mid - 1;
         
        }
        else if ( data[mid] < item ) // may be on the right half
        {
            low = mid + 1;
            
        }
    }
    if (item > data[mid] && numItems !=0)
    {

          mid = (mid + 1) * -1;
          return mid;
    }
    else
    {
       mid = (( mid ) * -1);
       return mid;
    }

}

/***************************************************
 * Set :: && operator
 * compares 2 sets and keeps ones that are equal
 **************************************************/
template <class T>
Set<T>  Set <T>:: operator && (Set<T> right)
{
   //set to be returned
   Set<T> tempData;
   //set passed in
   SetIterator<T> set1 = this->begin();
   //set to be added in
   SetIterator<T> set2 = right.begin();
   
   for (set1; set1 != this->end(); set1++)
   {
      for (set2; set2 != right.end(); set2++)
      {
         if (*set1==*set2)
            tempData.insert(*set2);
      }
      set2 = right.begin();
   }
   
   return tempData;
}

/***************************************************
 * Set :: ||
 * copies 2 sets into 1 omitting duplicates
 **************************************************/
template <class T>
Set<T> Set<T>:: operator || (Set<T> right) 
{
   //set to be returned
   Set<T> tempData;
   //set passed in
   SetIterator<T> set1 = this->begin();
   //set compared with
   SetIterator<T> set2 = right.begin();

   for(set1; set1 != this->end(); set1++)
      tempData.insert(*set1);

   for(set2; set2 != right.end(); set2++)
      tempData.insert(*set2);

   return tempData;
}

#endif // VECTOR_H

