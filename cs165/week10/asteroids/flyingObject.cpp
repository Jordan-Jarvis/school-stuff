#include "flyingObject.h"

 
Point FlyingObject::getPoint() const
{
   return point;
} 

Velocity FlyingObject::getVelocity() const
{
   return velocity;
}

bool FlyingObject::isAlive()
{
   return alive;
}

void FlyingObject::setPoint(Point point)
{
  this->point = point;

}

void FlyingObject::setVelocity(Velocity velocity)
{
    this->velocity = velocity;
}
int FlyingObject::kill()

{
      alive = 0;
      return type;
}

void FlyingObject::advance()
   {
      
      if (point.getY() < 200 && point.getY() > -200)
      {
         point.setY(point.getY() + velocity.getDy());
      }
      else
      {
            
         if (point.getY() > -200)
         {
            point.setY(-200 + velocity.getDy());
         }
         else
         {
            point.setY(200 + velocity.getDy());
         }

   }
   if (point.getX() < 200 && point.getX() > -200)
      point.setX(point.getX() + velocity.getDx());
   else 
   {
      if (point.getX() > -200)
      {
         point.setX(-200 + velocity.getDx());
      }
      else 
      {
         point.setX(200 + velocity.getDx());
      }

   }
setPoint(point);
}  

int FlyingObject::getRadius()
{
   return radius;
}
// Put your FlyingObject method bodies here
