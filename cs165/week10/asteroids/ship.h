/********************************************************************
 * File: lander.h
 * Purpose: Holds the definition of the Date class.
 ********************************************************************/

#ifndef ship_H
#define ship_H
#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
#include "uiInteract.h"


#include "point.h"

#define RIFLE_WIDTH 5
#define RIFLE_HEIGHT 40
#define RIFLE_MOVE_AMOUNT 6

#define ANGLE_MAX 360 
#define ANGLE_MIN 1
#define ANGLE_START 360



#include <iostream>
#include "flyingObject.h"

using namespace std;
class Ship : public FlyingObject
{
   private:
       

   public:

   float angle;

   Ship()
   {
      radius = 10;
      angle = 360;
   }
   float getAngle() const { return angle; }
   float getAngle();




   void rotateLeft();
   void rotateRight();
   void applyThrust();
   

   void draw(); 
};




#endif
