#include "rocks.h"

// Put your Rock methods here
#include <iostream>
using namespace std;


void Rock::draw()
{

   cout << "THIS SHOULD NOT BE RUNNING!!!";
} 

int Rock::hit()
{
   kill();
}

int Rock::getType()
{
   return type;
}