#include "bird.h"
#include <iostream>
using namespace std;
Bird::Bird(Point points)
      {
         alive = 1;
         rand2 = random(-150,150);
         rand1 = random(0, 2);

         setPoint(points);
         gravity = .03;
         
         point.setY(rand2);
         point.setX(-198);
      }


Point Bird::getPoint()
{ 
   return point;
}

Velocity Bird::getVelocity()
{
   return velocity;
}

bool Bird::isAlive()
{ 
   return alive;
}



void Bird::setPoint(Point points)
{
   point = points;
}

void Bird::setVelocity(Velocity velocity)
{
   velocity = this->velocity;
}

void Bird::kill()
{
   alive = 0;
}
void Bird::advance()
{

      velocity.setDy(velocity.getDy() - gravity);
      point.setY(point.getY() - (rand2/50) + rand1 + 1 + velocity.getDy() );
      point.setX(point.getX() + XSpeed);  
      
} 

void Bird::draw()
{

   cout << "THIS SHOULD NOT BE RUNNING!!!";
} 

int Bird::hit()
{
   kill();
}
