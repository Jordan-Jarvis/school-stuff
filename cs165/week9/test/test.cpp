/***********************************************************************
* Program:
*    Checkpoint 00, TEST
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

class Display
{
private:


public:
   int xPixels;
   int yPixels;
         int yVal;
         int xVal;
char screenArray [40][40];
   
   Display( int x, int y)
   {
      xPixels = x;
      yPixels = y;
      for (int i = 0; i < xPixels; i++)
      {
         for (int g = 0; g < yPixels; g++)
         {
            screenArray[i][g] = ' ';
         }
      }
   }
   
   void turnOnPixel(int xVals, int yVals )
   {
   screenArray[xVals][yVals] = 'X';
   }
   void turnOffPixel(int xVals, int yVals )
   {
      screenArray[xVals][yVals] = '0';
   }
   
   void turnOffScreen()
   {
      for (int i = 0; i < xPixels; i++)
      {
         for (int g = 0; g < yPixels; g++)
         {
            screenArray[i][g] = ' ';
         }
      }
   }
   void displayText()
   {
      cout << " ";
      for (int i = 0; i < xPixels; i++)
      {
         cout << i << " ";
      }
      for (int i = 0; i < 20; i++)
      {
         cout << endl << i;
         for (int j = 0; j < 20; j++)
            cout << screenArray[i][j] << " ";
      }
      cout << endl;
   }

};



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   
   
   
   int xVal = 20;
   int yVal = 20;
   Display * display = new Display(xVal, yVal);
   int t = 1;
   int newX = 0;
   int newY = 0;
   int select = 0;
   while(t != 0)
   {
      select = 0;
      cout << "to edit picture, please enter ";
      cout << "\n 0 to turn on a pixel\n";
      cout << " 1 to turn off a pixel\n";
      cout << " 2 to turn off all pixels on the screen \n";
      cout << " 3 to exit the program \n";
      cin >> select;
      switch (select)
      {
         case 0:
         {
         cout << "please enter a pixel value for the X to edit\n";
         cin >> newX;
         cout << "please enter a pixel value for the Y to edit\n";
         cin >> newY;
         display->turnOnPixel(newY, newX);
         break;
         }
         case 1:
         {
            cout << "please enter a pixel value for the X to edit\n";
            cin >> newX;
            cout << "please enter a pixel value for the Y to edit\n";
            cin >> newY;
            display->turnOffPixel(newY, newX);
            break;
         }
         case 2:
         display->turnOffScreen();
         break;
         case 3:
         return 0;

      }
      display->displayText();
   }      
   
   

   
   return 0;
}


