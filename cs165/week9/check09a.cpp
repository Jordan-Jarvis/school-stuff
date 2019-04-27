/***********************************************************************
* Program:
*    Checkpoint 09a, Virtual Functions
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your classes here
class Car
{
   private:
   protected:
   string name;
   public:
   Car()
   {
      name = "Unknown Model";
   }
   
   string getName()
   {
      return name;
   }
   void setName(string name)
   {
      this->name = name;
   }
   virtual string getDoorSpecs()
   {
      return "Unknown Doors";
   }
   
};

class Civic : public Car
{
   private:
   public:
   Civic()
   {
      setName("Civic");
   }
   virtual string getDoorSpecs()
   {
      return "4 doors\n";
   }
};
   
class Odyssey : public Car
{
   private:
   public:
   Odyssey()
   {
      setName("Odyssey");
   }
   virtual string getDoorSpecs()
   {
      return "2 front doors, 2 sliding doors, 1 tail gate\n";
   }
};

class Ferrari : public Car
{
   private:
   public:
   Ferrari()
   {
      setName("Ferrari");
   }
   virtual string getDoorSpecs()
   {
      return "2 butterfly doors\n";
   }
};
/**********************************************************************
 * Function: attachDoors
 * Purpose: This function can accept any type of Car object. It will
 *  call the appropriate functions to display the name and the doors info.
 ***********************************************************************/

void attachDoors(Car & car)
{
   cout << "Attaching doors to ";
   cout << car.getName() << " - ";
   cout << car.getDoorSpecs();
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // You should not change main

   Civic civic;
   Odyssey odyssey;
   Ferrari ferrari;

   attachDoors(civic);
   attachDoors(odyssey);
   attachDoors(ferrari);

   return 0;
}


