#ifndef flyingObject_h
#define flyingObject_h
#include <iostream>
#include "velocity.h"
#include "point.h"
using namespace std;

class FlyingObject 
{
   private:

   public:
      FlyingObject()
      {
         alive = 1;
      }
      FlyingObject(int FlyingObject)
      {
         alive = 1;
      }
      Point point; 
      Velocity velocity;
      bool alive;
      Velocity getVelocity();
      Point getPoint();
      bool isAlive();
      void setVelocity(Velocity velocity);
      void setPoint(Point point);
      void kill();
};
#endif
