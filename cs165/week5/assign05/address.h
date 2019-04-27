// File: address.h

#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
using namespace std;
class Address
{
private:
   string street;
   string city;
   string state;
   
public:
   Address() : street("unknown"), zip("00000"), city(""), state("") {}
   Address(string street, string city, string state, string zip)
   {
      setStreet(street);
      setCity(city);
      setState(state);
      setZip(zip);
   }
   string zip;
   string getStreet();
   void setStreet(string street);
   string getCity();
   void setCity(string city);
   string getState();
   void setState(string state);
   string getZip();
   void setZip(string zip);
   void display();
}; 

#endif
