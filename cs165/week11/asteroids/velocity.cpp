

#include "velocity.h"
#include <iostream>

using namespace std;

float Velocity::getDx()
{
   return x;
}

float Velocity::getDy()
{
   return y;
}
void Velocity::setDx(float x)
{
   this->x = x;
}
void Velocity::setDy(float y)
{
   this->y = y;
}