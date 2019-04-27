// File: address.cpp

#include "address.h"
#include <iostream>
using namespace std;
string Address :: getStreet()
{
   return this->street;
}

void Address :: setStreet(string street)
{
   this->street = street;
}

string Address :: getCity()
{
   return this->city;
}

void Address :: setCity(string city)
{
   this->city = city;
}

string Address :: getState()
{
   return this->state;
}

void Address :: setState(string state)
{
   this->state = state;
}

string Address :: getZip()
{
   return this->zip;
}

void Address :: setZip(string zip)
{
   this->zip = zip; 
}

void Address :: display()
{
   cout << this->street << endl << this->city 
      << ", " << this->state << " " << this->zip << endl;
}
// Put your method bodies for the address class here
