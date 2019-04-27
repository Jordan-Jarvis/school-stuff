/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    This will contain just the prototype for stocksBuySell(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Jordan Jarvis
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE
#include <iostream>    // for ISTREAM and OSTREAM


void stocksBuySell();

class TransB {
   private:
   
   public:
      int shares;
      Dollars price;
};

class TransS {
   private:
   
   public:
      int shares;
      Dollars price;
      Dollars profit;
};
#endif 

