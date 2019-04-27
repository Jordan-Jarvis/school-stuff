

// Put your ship methods here
#include "ship.h"
#include "uiDraw.h"
#include "point.h"
#include <cassert>




   
   float Ship::getAngle()
   {
      return angle;
   }

   void Ship::rotateRight()
   {
      angle -= RIFLE_MOVE_AMOUNT;

      if (angle < ANGLE_MIN)
      {
         angle = ANGLE_MAX - angle;
      }
   }
   void Ship::rotateLeft()
   {

      angle += RIFLE_MOVE_AMOUNT;

      if (angle > ANGLE_MAX) 
      {
         angle = angle - ANGLE_MAX;
      }
   }
   void Ship::applyThrust()
   { 
   velocity.setDy(velocity.getDy() - (.3 * (-cos(M_PI / 180.0 * angle))));
   velocity.setDx(velocity.getDx() -(.3 * (sin(M_PI / 180.0 * angle))));

   }


   void Ship::draw()
   {
      //assert(angle >= ANGLE_MIN);
      //assert(angle <= ANGLE_MAX);
   
      
      drawShip(point, angle, 1);
   }
   


