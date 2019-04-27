/********************************************************************
 * File: lander.h
 * Purpose: Holds the definition of the Date class.
 ********************************************************************/

#ifndef LANDER_H
#define LANDER_H
#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
#include "uiInteract.h"

#include <iostream>

using namespace std;
class Lander
{
   private:
      

   public:
   bool landed;
   bool alive;
   int fuel;
   Velocity velocity;
   Point point;
   Lander()
   {
      setAlive(1);
      setLanded(0);
      point.setX(180.0);
      point.setY(180.0);
   }
   
   Point getPoint();  
   Velocity getVelocity();
   bool isAlive();
   bool isLanded();
   int getFuel();
   bool canThrust();
   void setLanded (bool landed);
   bool setAlive(bool alive);
   void setFuel(int fuel);
   void applyGravity(float gravity);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();
   void advance();
   void draw(); 
};
#endif