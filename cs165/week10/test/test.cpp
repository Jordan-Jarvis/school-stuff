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



class Airplane
{
private:


public:
   float cruisAltitude;
   float currentAltitude;
   
   Airplane(float cruiseAltitude, float takeOffAltitude)
   {
      cruisAltitude = cruiseAltitude;
      currentAltitude = takeOffAltitude;
   }
   float getCruiseAltitude()
   {
      return cruisAltitude;
   }
   float getCurrentAltitude()
   {
      return currentAltitude;
   }

   bool increaceAltitude()
   {
      if (currentAltitude < cruisAltitude)
      {
         currentAltitude = currentAltitude + 100;
         return true;
      }
      else 
      {
         return false;
      }
   }

   void displayCurrentAltitude()
   {
      cout << "The current altitude is " << currentAltitude << endl;
      
   }
   void displayCruisingAltitude()
   {
      cout << "You are now at cruising altitude of " << cruisAltitude << "feet\n" ;
   }
};



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   float cAltitude = 2000;
      float takeOffAltitude = 0;
   Airplane airplane(cAltitude, takeOffAltitude);
   bool increace = true;

   airplane.displayCurrentAltitude();
   while (increace == true)
   {
      
      increace = airplane.increaceAltitude();
      if (increace != false)
      {
         airplane.displayCurrentAltitude();
      }
      
   }
   
   airplane.displayCruisingAltitude();
   return 0;


   
   

   
   return 0;
}


