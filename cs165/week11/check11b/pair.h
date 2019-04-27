/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H
template<class T1, class T2>
class Pair
{
   private:
   public:
   T1 first;
   T2 second;
   T1 getFirst()
   {
      return first;
   }
   T2 getSecond()
   {
      return second;
   }
   void setFirst(T1 first)
   {
      this->first = first;
   }
   void setSecond(T2 second)
   {
      this->second = second;
   }
   void display()
   {
      cout << first << " - " << second;
   }
};
   
   

// TODO: Fill in this class
// Put all of your method bodies right in this file


#endif // PAIR_H
