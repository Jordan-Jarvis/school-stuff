/***************
 * phone.h
 ***************/

#ifndef PHONE_H
#define PHONE_H
#include <iostream>
#include <string>
using namespace std;
class Phone
{
   private:
   public:
   int areaCode;
   int prefix;
   int suffix;
   void promptNumber();
   void display();
};

#endif
