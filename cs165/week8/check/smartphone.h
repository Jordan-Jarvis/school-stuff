/****************
 * smartphone.h
 ****************/

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include "phone.h"
#include <iostream>
using namespace std;
class SmartPhone : public Phone
{
   private:
   public:
   string email;
   void prompt();
   void display();
};

#endif
