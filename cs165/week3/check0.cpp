/***********************************************************************
* Program:
*    Checkpoint 00, test3          (e.g. Assignment 01, Hello World)  
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

int thermostat(int currentTemp, int desiredTemp)
{
    int onOff = 0;
   if (currentTemp < desiredTemp)
   {
       onOff = 1;
   }
   return onOff;
}
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int currentTemp = 0;
   int desiredTemp = 0;
   int onOff = 0;
   int increace = 1;
   cout << "What is the current temperature?";
   cin >> currentTemp;
   cout << "What is the desired temperature?";
   cin >> desiredTemp;
      
      while (increace == 1)
   {
      onOff = thermostat(currentTemp, desiredTemp);
      if (onOff == 1)
      {
         currentTemp++;
         cout << currentTemp << endl;
      }
      else 
      {
          increace = 0;
      }
      
   }

   return 0;
}
