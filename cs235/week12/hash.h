#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cassert>
#include <list>
#include <vector>
using namespace std;

/************************
 * hash class
 ************************/
template <class T>
class Hash
{
  public:
   Hash(int buckets) throw (const char *);
   Hash(const Hash <T> & rhs) : 
   numItems(rhs.size()), cap(rhs.capacity()), table(rhs.table) {}

   ~Hash() { table.clear(); }
   Hash<T> & operator = (const Hash<T> & rhs) throw (const char *);
   bool find(const T & t); 
   void insert(const T & t);
   int size() const     { return numItems;} 
   int capacity() const { return cap;} 
   bool empty() const   { return (numItems == 0);}
   virtual int hash(const T & t) const = 0;
  private:
   int cap;
   int numItems;
   vector<list <T> >  table;
};

/*****************************
 * non default constructor
 *****************************/
template <class T>
Hash <T> :: Hash(int altCap) throw (const char *)
{
   cap = altCap;
   numItems = 0;
   try
   {
      table.resize(cap);
   }
   catch (bad_alloc)
   {
      throw "ERROR: Could not allocate an array for Hash";
   }
}

/**********************************************************************
 * find()
 * returns whether somehting is in the hash or not
 **********************************************************************/
template <class T>
bool Hash <T> :: find(const T & t)
{
   int value = hash(t);

   typename list<T>::iterator it = table[value].begin();
   while (it != table[value].end()){
         it++;
         if (*it == t)
            return true;
   }
   
   return false;
}

/**********************************************************************
 * insert()
 * adds to the hash
 **********************************************************************/
template <class T>
void Hash <T> :: insert(const T & t)
{
   int value = hash(t);
   table[value].push_back(t);
   ++numItems;
}

/*********************
 * = operator
 *********************/
template <class T>
Hash<T> & Hash<T> :: operator = (const Hash<T> & rhs) throw (const char *)
{
   table.clear();
   if (rhs.empty())
      return *this;
   try
   {
      cap = rhs.cap;
      numItems = rhs.numItems;
      table = rhs.table;
   }
   catch (bad_alloc)
   {
      throw "ERROR: Cannot allocate an array from Hash";
   }

   return *this;
}

#endif 