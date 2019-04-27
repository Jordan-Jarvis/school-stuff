#include <iostream>
#include "bullet.h"
using namespace std;

void Bullet::advance()
{
      point.setY(point.getY() + velocity.getDy());
      point.setX(point.getX() + velocity.getDx());
}

void Bullet::draw()
{
   drawDot(point);
}

void Bullet::fire(Point point, float angle)
{
   
   velocity.setDx((angle - 90)/5);
   velocity.setDy(angle/5);
}
