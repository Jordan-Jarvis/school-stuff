// File: customer.cpp

#include "customer.h"
#include <iostream>
using namespace std;

string Customer :: getName()
{
   return this->name;
}

void Customer :: setName(string name)
{
   this->name = name;
}

Address Customer :: getAddress()
{
   return this->address;
}
void Customer :: setAddress(Address address)
{
   this->address = address;
}

void Customer :: display()
{
   cout << this->name << endl;
   this->address.display();
}
// Put the method bodies for your customer class here
