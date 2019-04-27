#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#include "point.h"

#define RIFLE_WIDTH 5
#define RIFLE_HEIGHT 40





// Put your Ship class here


#include <iostream>
#include <iomanip>
using namespace std;
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "flyingObject.h"
class Rock : public FlyingObject
{
   private:
      
   public:
   float angle;

   void draw() const;
   void moveLeft();
   void moveRight();
   int getType();
      Rock()
      {
         angle = 1;
      }
      
      int XSpeed;
      virtual int hit() = 0;
      virtual void draw() = 0;
      
};

class BigRock : public Rock
{
   private:
   public:
   int hitPoints;
   BigRock() : Rock()
   {
      point.setX(random(-190,190));
      point.setY(random(-190,190));
      angle = random(1,360);
      velocity.setDx( (sin(M_PI / 180.0 * angle)));
      velocity.setDy( (-cos(M_PI / 180.0 * angle)));
      hitPoints = 1;
      radius = 16;
      type = 1;
      XSpeed = 3;
   }
   virtual void draw()
   {
      if (isAlive())
      {
         angle = angle + 2;
         if (angle >= 360)
            angle = 1;
         drawLargeAsteroid(point, angle);
      }
   }
   
   virtual int hit()
   {
      alive = 0;
      return hitPoints;
   }
};

class MediumRock : public Rock
{
   private:
   public:
   int hitPoints;
   MediumRock(Point rockPoint, Velocity rockVelocity, int up) : Rock()
   {
      setPoint(rockPoint);
      setVelocity(rockVelocity);
      velocity.setDy(velocity.getDy() + up);
       XSpeed= 3;
       type = 2;
       radius = 8;
   }
   virtual void draw()
   {
      if (isAlive())
      {
         angle = angle + 5;
         if (angle >= 360)
            angle = 1;
         drawMediumAsteroid(point, angle );
      }
   }
   virtual int hit()
   {
      alive = 0;
      return 1;
   }
};

class SmallRock : public Rock
{
   private:
   public:

   int hitPoints;
   SmallRock(Point rockPoint, Velocity rockVelocity, int up) : Rock()
   {
      setPoint(rockPoint);
      setVelocity(rockVelocity);
      velocity.setDx(velocity.getDx() + up);
      XSpeed = 2;
      hitPoints = 1;
      

      type = 3;
      radius = 4;
   }

   
   virtual void draw()
   {
      if (isAlive())
      {
         angle = angle + 10;
         if (angle >= 360)
            angle = 1;
         drawSmallAsteroid(point, angle);
      }
   }
   
   virtual int hit()
   {
      alive = 0;
      return 1;
   }
};

#endif
