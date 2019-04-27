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
         type = 0;
      }
      FlyingObject(int FlyingObject)
      {
         alive = 1;
         type = 0;
      }
      int type;
      Point point; 
      Velocity velocity;
      bool alive;
      int radius;
      int getRadius();
      Velocity getVelocity() const;
      Point getPoint() const;
      bool isAlive();
      void setVelocity(Velocity velocity);
      void setPoint(Point point);
      int kill();
      void advance();
};
#endif
