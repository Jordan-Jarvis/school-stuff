// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "address.h"
#include <iostream>
#include <string>
using namespace std;


class Customer
{
   private:
      string name;
      Address address;
   public:
   Customer() 
   {
      name = "unspecified";
      address = getAddress();
   }
   Customer(string name, Address address)
   {
      setName(name);
      setAddress(address);
   }
      string getName();
      void setName(string name);
      Address getAddress();
      void setAddress(Address address);
      void display();
};

#endif
