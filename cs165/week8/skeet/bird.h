/********************************************************************
 * File: bird.h
 ********************************************************************/

#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <iomanip>
using namespace std;
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "flyingObject.h"

class Bird : public FlyingObject
{
   private:
      
   public:

      int rand1;
      int rand;
      int rand2;


      Bird(Point points)
      {
         alive = 1;
         rand2 = random(-150,150);
         rand1 = random(0, 2);

         setPoint(points);
         gravity = .03;
         
         point.setY(rand2);
         point.setX(-198);
      }
      int XSpeed;
      float gravity;
      void advance();
      virtual void draw() = 0;
      virtual int hit() = 0;

      
};

class SacredBird : public Bird
{
   private:
   public:
   int size;
   int hitPoints;
   int durability;
   SacredBird() : Bird(point)
   {
      size = 30;
      hitPoints = -10;
      durability = 1; 
      XSpeed = 3;
   }
   virtual void draw()
   {
      if (isAlive())
      {
         drawSacredBird(point, size);
      }
   }
   
   virtual int hit()
   {
      alive = 0;
      return hitPoints;
   }
};

class CommonBird : public Bird
{
   private:
   public:
   int size;
   int hitPoints;
   int durability;
   CommonBird() : Bird(point)
   {
         XSpeed= 3;
   }
   virtual void draw()
   {
      if (isAlive())
      {
         drawCircle(point, 15 );
      }
   }
   virtual int hit()
   {
      alive = 0;
      return 1;
   }
};

class ToughBird : public Bird
{
   private:
   public:
   int size;
   int hitPoints;
   int durability;
   ToughBird() : Bird(point)
   {
      XSpeed = 2;
      hitPoints = 1;
      durability = 3;


   }
   virtual void draw()
   {
      if (isAlive())
      {
         drawToughBird(point, 15, durability);
      }
      
   }
   virtual int hit()
   {
      
      durability--;
      if (durability == 0)
      {
         alive = 0;
         return 3;
      }
      return 1;
   }
};
#endif