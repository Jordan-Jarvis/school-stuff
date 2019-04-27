/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
   int dollars;
   int cents; 

   void setDollars(int dollar)
   {
      if (dollar < 0)
         dollars = (dollar * -1);
      else
         dollars = dollar;
   }
      void setCents(int cent)
   {
      if (cent < 0)
         cents = (cent * -1);
      else
         cents = cent;
   }

public:
   Money() : dollars(0) , cents (0) 
   { 
   }
   
   Money(int dollar) :cents(0), dollars(dollars)
   {
      setDollars(dollar);
   }
   
   Money(int dollar, int cent) : dollars(dollars) , cents(cents)
   {
      setDollars(dollar);
      setCents(cent);
   }

   int getDollars() const;
   int getCents() const;
   void prompt();
   void display() const;
};

#endif
