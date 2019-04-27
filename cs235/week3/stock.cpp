/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    Jordan Jarvis
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
using namespace std;

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   string command;
   Queue <TransB> buy(400);
   Queue <TransS> sell(400);
   TransB b;
   TransS s;
   Dollars total = 0;
   
   do
   {
      cout << "> ";
      cin  >> command;
      
      if (command == "buy")
      {
         cin >> b.shares;
         cin >> b.price;
         buy.push(b); 
      }
      else if (command == "sell")
      {
         cin >> s.shares;
         cin >> s.price;
         
         float remainingShares = s.shares;
         while (buy.size() != 0 && remainingShares >= buy.front().shares)
         {
            remainingShares = remainingShares - buy.front().shares;
            s.shares = buy.front().shares;
            s.profit = (s.price * s.shares ) - (buy.front().price * buy.front().shares );
            sell.push(s);
            buy.pop();
         }
         float temp;
         if (buy.size() > 0)
         {
            temp = buy.front().shares - remainingShares;
            s.profit = s.price * remainingShares - buy.front().price * remainingShares;
         
            buy.pop();
               b.shares = temp;
               s.shares = remainingShares;
            if(temp > 0)
            {
               if (s.shares > 0)
               {
                  sell.push(s);
               }
               buy.push(b);
            }
         }
      
      }
      else if (command == "display")
      {
         Queue <TransB> iBuy = buy;
         Queue <TransS> iSell = sell;
         if (iBuy.size() > 0)
         {
            cout << "Currently held:" << endl;
         }
         while (iBuy.size() > 0)
         {
            
            cout << "\tBought " << iBuy.front().shares << " shares at " 
                 << iBuy.front().price << endl;
                 
            iBuy.pop();
         }
         if (iSell.size() > 0)
            cout << "Sell History:" << endl;
         Dollars tally;
         while (iSell.size() > 0)
         {
            tally = tally + iSell.front().profit;
            cout << "\tSold " << iSell.front().shares << " shares at " 
                 << iSell.front().price << " for a profit"
                 << " of " << iSell.front().profit << endl;
            iSell.pop();
         }
         cout << "Proceeds: " << tally << endl;   
       }
      else  
      {
         //do nothing
      }                
   }
   while (command != "quit");
   
}


