#ifndef BULLET_H
#define BULLET_H
#define BULLET_LIFE 40
#define BULLET_SPEED 10
#include <iostream>
using namespace std;
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "ship.h"
#include "flyingObject.h"
class Bullet : public FlyingObject
{
   private:
      
   public:
      int life;
      Bullet()
      {
         life = 0;
         angle = 0;
      }
      float angle;
      void draw();
      void fire(Point point,float angle);
};
#endif