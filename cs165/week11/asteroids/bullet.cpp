#include <iostream>
#include "bullet.h"
#include <cmath>

using namespace std;




void Bullet::draw()
{
   if (life <= 40)
   {
      drawDot(point);
      life++;
   }
   else
      kill();
   
}

void Bullet::fire(Point spoint, float angle)
{
   point = spoint;
   velocity.setDy(-BULLET_SPEED * (-cos(M_PI / 180.0 * angle)));
   velocity.setDx(-BULLET_SPEED * (sin(M_PI / 180.0 * angle)));
}