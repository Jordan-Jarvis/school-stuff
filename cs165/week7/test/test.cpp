/***********************************************************************
* Program:
*    Checkpoint 00, test1          (e.g. Assignment 01, Hello World)  
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
#include <iomanip>
using namespace std;

class Forklift
{
private:

public:
   int fuel;
   bool forkLift;
   Forklift()
   {
   fuel = 10;
   forkLift = 0;
   }
   int raise();
   int lower();
   void display();
};

  int Forklift::raise()
   {
      if (fuel <= 0)
         cout << "not enough fuel\n press x to exit.\n";
      else
      { 
         forkLift = 1;
         fuel--;
      }
      
   }
   int Forklift::lower()
   {
      if (fuel <= 0)
         cout << "not enough fuel\n press x to exit.\n";
      else 
      {
         forkLift = 0;
         fuel --;
      }
   }
/*****************************************************************

 ****************************************************************/
void Forklift :: display()
{
   if (forkLift == 1)
   {
      cout << "the forklift is up\n";
   }
   else 
   { 
      cout << "the forklift is down\n";
   }
   cout << " there is " << fuel << " units of fuel left\n";
}


int main()
{
   Forklift forklift;
   int i = 1;
   char choice;
   while (i =! 0)
   {
      cout << "would you like to raise or lower the fork lift?\n"
         << "please enter U for up and D for down.\n";
      cin >> choice;
   switch (choice)
   {
      case 'U': 
      case 'u':
      forklift.raise();
      forklift.display();
         break;
      
      case 'D':
      case 'd':
      forklift.lower();
      forklift.display();
      break;
      case 'x':
      case 'X':
      return 0;
      
      default:
         cout << "Invalid input";
         return -1;
   }
   choice = '0';
   }


   return 0;
}

