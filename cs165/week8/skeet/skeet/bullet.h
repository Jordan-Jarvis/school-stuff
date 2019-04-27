/********************************************************************
 * File: bird.h
 ********************************************************************/

#ifndef BULLET_H
#define BULLET_H
#include <iostream>
using namespace std;
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "rifle.h"
class Bullet
{
   private:
      
   public:
   
      Bullet()
      {
         alive = 1;
         point.setX(200);
         point.setY(-200);

      }
      Rifle rifle(Point point);
      Point point;
      Velocity velocity;
      bool alive;
      float angle;
      Point getPoint();
      Velocity getVelocity();
      bool isAlive();
      void setPoint(Point point);
      void setVelocity(Velocity velocity);
      void kill();
      void advance();
      void draw();
      void fire(Point point,float angle);
      
};
#endif