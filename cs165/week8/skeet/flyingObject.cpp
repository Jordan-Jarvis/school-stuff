#include "flyingObject.h"


Point FlyingObject::getPoint()
{
   return point;
} 

Velocity FlyingObject::getVelocity()
{
   return velocity;
}

bool FlyingObject::isAlive()
{
   return alive;
}

void FlyingObject::setPoint(Point points)
{
  point = points;
}

void FlyingObject::setVelocity(Velocity velocity)
{
    this->velocity = velocity;
}
void FlyingObject::kill()

{
      alive = 0;
}

   

// Put your FlyingObject method bodies here
