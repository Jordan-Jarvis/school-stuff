/***********************************************************************
 * Header:
 *    FIBONACCI
 * Summary:
 *    This will contain just the prototype for fibonacci(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Jordan Jarvis
 ************************************************************************/

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "list.h"        

void fibonacci();

template <class T>
void display(const List<T> & rhs );


class BigNum 
{
private:
   
   List <unsigned int> digits;
   
public:
   
   BigNum() {}
   BigNum(const unsigned int & t)throw (const char *);
   BigNum(const BigNum & rhs)    throw (const char *);
   BigNum & operator = (const BigNum & rhs) throw(const char *);
   BigNum & operator += (const BigNum & rhs) throw(const char *);
   friend std::ostream & operator << (std::ostream & out, const BigNum & fib);
   
};


#endif // FIBONACCI_H