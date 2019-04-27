/********************************************************************
 * File: lander.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/

#include "lander.h"
#include "ground.h"
#include "uiDraw.h"
#include "point.h"


   Point Lander :: getPoint() 
   {
      return this->point;
   }
   Velocity Lander::getVelocity()
   {
      return velocity;
   }
   bool Lander::isAlive()
   {
      return alive; 
   }
   bool Lander::isLanded() 
   {
      return landed;
   }
   int Lander::getFuel()
   {
      return this->fuel;
   }
   bool Lander::canThrust()
   {
      if (alive && fuel < 50)
      {
         drawText(Point(50), "Warning! Your fuel is running low!");
      }
      if (this->fuel > 0 && alive && !landed)
         return 1;
      else
         return 0;
   }
   void Lander::setLanded (bool landed)
   {
      this->landed = landed;
   }
   bool Lander::setAlive(bool alive)
   {
      this->alive = alive;
   }
   void Lander::setFuel(int fuel)
   {
      this->fuel = fuel;
   }
   void Lander::applyGravity(float gravity)
   {
      velocity.setDy(velocity.getDy() - gravity);
   }
   void Lander::applyThrustLeft()
   {
      if (canThrust())
      {
         velocity.setDx(velocity.getDx() + .1);
         this->fuel--;
      }
      
   }
   void Lander::applyThrustRight()
   {
      if (canThrust())
      {
         velocity.setDx(velocity.getDx() - .1);
         this->fuel--;
      }
   }
   void Lander::applyThrustBottom()
   { 
      if (canThrust())
      {
         velocity.setDy(velocity.getDy() + .3);
         this->fuel = this->fuel - 1; 
      }
   }
   void Lander::advance()
   {
      point.setY(point.getY() + velocity.getDy());
      point.setX(point.getX() + velocity.getDx());

   }
   void Lander::draw()
   {
      drawLander(point);
   }