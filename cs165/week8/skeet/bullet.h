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
#include "flyingObject.h"
class Bullet : public FlyingObject
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
      float angle;
      void advance();
      void draw();
      void fire(Point point,float angle);
      
};
#endif