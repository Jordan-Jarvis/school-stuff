#include <iostream>
#include "bullet.h"
using namespace std;

Point Bullet::getPoint()
{
   return point;
}

Velocity Bullet::getVelocity()
{
   return velocity;
}

bool Bullet::isAlive()
{
   return alive;
}

void Bullet::setPoint(Point point)
{
  this->point = point;
}

void Bullet::setVelocity(Velocity velocity)
{
    velocity = this->velocity;
}

void Bullet::kill()
{
   alive = 0;
}
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
