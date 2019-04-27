#include "bird.h"
#include <iostream>
using namespace std;

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
