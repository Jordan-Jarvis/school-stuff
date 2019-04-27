/********************************************************************
 * File: lander.h
 * Purpose: Holds the definition of the Date class.
 ********************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H
#include <iostream>
using namespace std;

class Velocity
{
   private:
      float x;
      float y;
      
   public:
      Velocity()
      {
         x = 0;
         y = 0;
      }
      
      Velocity(float x, float y)
      {
         setDx(x);
         setDy(y);
      }
      float getDx();
      float getDy();
      void setDx(float x);
      void setDy(float y);
};
#endif