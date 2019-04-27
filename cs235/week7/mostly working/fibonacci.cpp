/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    Jordan Jarvis
 **********************************************************************/

#include <iostream>
#include "fibonacci.h"   // for fibonacci() prototype
#include "list.h"        // for LIST
using namespace std;


/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{
   int runNumber=0, number;        
   do
   {

      if(!runNumber) 
         cout << "How many Fibonacci numbers would you like to see? ";
      else  
         cout << "Which Fibonacci number would you like to display? ";
     
      cin  >> number;
      {
        BigNum first(0), second(1), temp;       //Create 3 BigNum objects
         

         for (int c = 1; c < number + 1 ; c++ )
         {
            if(c > 1)
            {
               temp = second;             
               second += first;         
               first = temp;             
            }
            if(!runNumber)
               cout <<"\t"<< second << endl;  
         }
         if(runNumber)
            cout <<"\t"<< second << endl; 
      }
   }while(runNumber++ < 1);

}

/*******************************************
 *    BigNum Non-Default Constructor
 *******************************************/
BigNum::BigNum(const unsigned int & t)throw (const char *)
{
   digits.push_front(t);
}

/*******************************************
 * BigNum :: = Operator
 * List Assignment Operator
 *******************************************/
BigNum & BigNum::operator = (const BigNum & rhs) throw(const char *)
{
   
   this->digits = rhs.digits;
   
   return *this;
}

/*******************************************
 * BigNum Copy Constructor
 *******************************************/
BigNum::BigNum(const BigNum & rhs)    throw (const char *)
{
   *this = rhs;
}

/*******************************************
 * Friend stream operator
 *******************************************/
ostream & operator << (ostream & out, const BigNum & fib)
{
   BigNum local(fib);
   ListIterator<unsigned int> it;
   for (it = local.digits.begin(); it != local.digits.end(); ++it)
   {
      if(it != local.digits.begin())
      {
         if(*it < 99)
            out << ",0" << *it;    
         else
             out << "," << *it;   
      }
      else
      {
         
         out << *it;
      }
   }
   return out;
}

/*******************************************
 * BigNum :: Add-onto Operator
 *    Add lists together
 *******************************************/
BigNum & BigNum::operator += (const BigNum & f) throw(const char *)
{
   
   List <unsigned int> first(f.digits), second(this->digits);  
   ListIterator <unsigned int> it1, it2, it3;             
   unsigned int sum=0,carry=0;                       
   it1 = first.rbegin();
   it2 = second.rbegin();
   it3 = this->digits.rbegin();
   
   for (; it1 != first.rend(); it1--, it2--)
   {
      sum = *it1 + *it2 + carry;                  
      
      if(sum > 999)                                   
      {
         carry = (sum * .001);                    
         sum = sum % 1000;                            
      }
      else
      {
         carry = 0;  
      }         
      *it3-- = sum; 
   }
   
   if(it2 != second.rend())
   {
      sum = *it2 + carry;                         
      *it3 = sum;                             
      carry = 0;  
   }
   
   if(carry > 0)   
   {      
      this->digits.push_front(carry);  
   }      
   return *this;
}
 




